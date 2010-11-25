/*
 * Copyright (C) 2010 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Jason Smith <jason.smith@canonical.com>
 */

#include <sys/time.h>

#include "Nux/Nux.h"
#include "Nux/VScrollBar.h"
#include "Nux/HLayout.h"
#include "Nux/VLayout.h"
#include "Nux/MenuPage.h"
#include "Nux/WindowCompositor.h"
#include "Nux/BaseWindow.h"
#include "Nux/MenuPage.h"
#include "NuxCore/Color.h"

#include "LauncherIcon.h"
#include "Launcher.h"

#define DEFAULT_ICON "application-default-icon"

nux::Tooltip *LauncherIcon::_current_tooltip = 0;
QuicklistView *LauncherIcon::_current_quicklist = 0;

LauncherIcon::LauncherIcon(Launcher* launcher)
{
  _folding_angle = 0;
  _launcher = launcher;
  m_TooltipText = "blank";

  for (int i = 0; i < LAUNCHER_ICON_QUIRK_LAST; i++)
  {
    _quirks[i] = 0;
    _quirk_times[i].tv_sec = 0;
    _quirk_times[i].tv_nsec = 0;
  }

  _related_windows = 0;

  _background_color = nux::Color::White;
  _glow_color = nux::Color::White;
  
  _mouse_inside = false;
  _tooltip = new nux::Tooltip ();
  _icon_type = LAUNCHER_ICON_TYPE_NONE;
  _sort_priority = 0;

  _quicklist = new QuicklistView ();
  _quicklist->sigVisible.connect (sigc::mem_fun (this, &LauncherIcon::RecvShowQuicklist));
  _quicklist->sigHidden.connect (sigc::mem_fun (this, &LauncherIcon::RecvHideQuicklist));
  _quicklist_is_initialized = false;
  
  MouseEnter.connect (sigc::mem_fun(this, &LauncherIcon::RecvMouseEnter));
  MouseLeave.connect (sigc::mem_fun(this, &LauncherIcon::RecvMouseLeave));
  MouseDown.connect (sigc::mem_fun(this, &LauncherIcon::RecvMouseDown));
  MouseUp.connect (sigc::mem_fun(this, &LauncherIcon::RecvMouseUp));
  
}

LauncherIcon::~LauncherIcon()
{
  if (_present_time_handle)
    g_source_remove (_present_time_handle);
  _present_time_handle = 0;
  
  if (_center_stabilize_handle)
    g_source_remove (_center_stabilize_handle);
  _center_stabilize_handle = 0;
}

nux::Color LauncherIcon::BackgroundColor ()
{
  return _background_color;
}

nux::Color LauncherIcon::GlowColor ()
{
  return _glow_color;
}

nux::BaseTexture * LauncherIcon::TextureForSize (int size)
{
  nux::BaseTexture * result = GetTextureForSize (size);
  return result;
}

void LauncherIcon::ColorForIcon (GdkPixbuf *pixbuf, nux::Color &background, nux::Color &glow)
{
  unsigned int width = gdk_pixbuf_get_width (pixbuf);
  unsigned int height = gdk_pixbuf_get_height (pixbuf);
  unsigned int row_bytes = gdk_pixbuf_get_rowstride (pixbuf);
  
  long int rtotal = 0, gtotal = 0, btotal = 0;
  float total = 0.0f;
  
  
  guchar *img = gdk_pixbuf_get_pixels (pixbuf);
  
  for (unsigned int i = 0; i < width; i++)
  {
    for (unsigned int j = 0; j < height; j++)
    {
      guchar *pixels = img + ( j * row_bytes + i * 4);
      guchar r = *(pixels + 0);
      guchar g = *(pixels + 1);
      guchar b = *(pixels + 2);
      guchar a = *(pixels + 3);
      
      float saturation = (MAX (r, MAX (g, b)) - MIN (r, MIN (g, b))) / 255.0f;
      float relevance = .1 + .9 * (a / 255.0f) * saturation;
      
      rtotal += (guchar) (r * relevance);
      gtotal += (guchar) (g * relevance);
      btotal += (guchar) (b * relevance);
      
      total += relevance * 255;
    }
  }
  
  float r, g, b, h, s, v;
  r = rtotal / total;
  g = gtotal / total;
  b = btotal / total;
  
  nux::RGBtoHSV (r, g, b, h, s, v);
  
  if (s > .15f)
    s = 0.4f;
  v = .85f;
  
  nux::HSVtoRGB (r, g, b, h, s, v);
  background = nux::Color (r, g, b);
  
  v = 1.0f;
  nux::HSVtoRGB (r, g, b, h, s, v);
  glow = nux::Color (r, g, b);
}

nux::BaseTexture * LauncherIcon::TextureFromGtkTheme (const char *icon_name, int size)
{
  GdkPixbuf *pbuf;
  GtkIconTheme *theme;
  GtkIconInfo *info;
  nux::BaseTexture *result;
  GError *error = NULL;
  
  theme = gtk_icon_theme_get_default ();
      
  if (!icon_name)
    icon_name = g_strdup (DEFAULT_ICON);
   
  info = gtk_icon_theme_lookup_icon (theme,
                                     icon_name,
                                     size,
                                     (GtkIconLookupFlags) 0);            
  if (!info)
  {
    info = gtk_icon_theme_lookup_icon (theme,
                                       DEFAULT_ICON,
                                       size,
                                       (GtkIconLookupFlags) 0);
  }
        
  if (gtk_icon_info_get_filename (info) == NULL)
  {
    info = gtk_icon_theme_lookup_icon (theme,
                                       DEFAULT_ICON,
                                       size,
                                       (GtkIconLookupFlags) 0);
  }
  
  pbuf = gtk_icon_info_load_icon (info, &error);

  if (GDK_IS_PIXBUF (pbuf))
  {
    result = nux::CreateTextureFromPixbuf (pbuf); 
    ColorForIcon (pbuf, _background_color, _glow_color);
  
    g_object_unref (pbuf);
  }
  else
  {
    g_warning ("Unable to load '%s' from icon theme: %s",
               icon_name,
               error ? error->message : "unknown");

    if (g_strcmp0 (icon_name, "folder") == 0)
      return NULL;
    else
      return TextureFromGtkTheme ("folder", size);
  }
  
  return result;
}

void LauncherIcon::SetTooltipText(const TCHAR* text)
{
    m_TooltipText = text;
    _tooltip->SetText (m_TooltipText);
}

nux::NString LauncherIcon::GetTooltipText()
{
    return m_TooltipText;
}

void
LauncherIcon::RecvMouseEnter ()
{
  if (_quicklist_is_initialized == false)
  {
    std::list<DbusmenuClient *> menus_list = Menus ();
    std::list<DbusmenuClient *>::iterator it;
    for (it = menus_list.begin (); it != menus_list.end (); it++)
    {
      g_signal_connect(G_OBJECT(*it), DBUSMENU_CLIENT_SIGNAL_ROOT_CHANGED, G_CALLBACK(&LauncherIcon::root_changed), _quicklist);
      dbusmenu_client_add_type_handler (*it, DBUSMENU_CLIENT_TYPES_DEFAULT, (&LauncherIcon::label_handler));
      dbusmenu_client_add_type_handler (*it, DBUSMENU_CLIENT_TYPES_SEPARATOR, (&LauncherIcon::separator_handler));
    }
    
    _quicklist_is_initialized = true;
  }
  
  if (_launcher->GetActiveQuicklist ())
  {
    // A quicklist is active
    return;
  }
  
  int tip_x = _launcher->GetBaseWidth () + 1; //icon_x + icon_w;
  int tip_y = _center.y;
          
  _tooltip->ShowTooltipWithTipAt (tip_x, tip_y);
  
  if (!_quicklist->IsVisible ())
  {
    _tooltip->ShowWindow (true);
  }
}

void LauncherIcon::RecvMouseLeave ()
{
  _tooltip->ShowWindow (false);
}


gboolean LauncherIcon::label_handler (DbusmenuMenuitem * newitem, DbusmenuMenuitem * parent, DbusmenuClient * client)
{
  //const gchar* s = dbusmenu_menuitem_property_get (newitem, DBUSMENU_MENUITEM_PROP_LABEL);
  //printf ("label: %s\n", s);
  
  return true;
}

gboolean LauncherIcon::separator_handler (DbusmenuMenuitem * newitem, DbusmenuMenuitem * parent, DbusmenuClient * client)
{
  //const gchar* s = dbusmenu_menuitem_property_get (newitem, DBUSMENU_MENUITEM_PROP_LABEL);
  //printf ("separator: %s\n", s);

  return true;
}

void LauncherIcon::child_realized (DbusmenuMenuitem *newitem, QuicklistView *quicklist)
{
  const gchar* label = dbusmenu_menuitem_property_get (newitem, DBUSMENU_MENUITEM_PROP_LABEL);
  const gchar* type = dbusmenu_menuitem_property_get (newitem, DBUSMENU_MENUITEM_PROP_TYPE);
  
  if (g_strcmp0 (type, DBUSMENU_CLIENT_TYPES_SEPARATOR) == 0)
  {
    quicklist->AddMenuItem ("-----------------");
  }
  else
  {
    quicklist->AddMenuItem (label);
  }
    
}

void LauncherIcon::root_changed (DbusmenuClient * client, DbusmenuMenuitem * newroot, QuicklistView *quicklist)
{
  GList * child = NULL;
  for (child = dbusmenu_menuitem_get_children(newroot); child != NULL; child = g_list_next(child))
  {
    g_signal_connect(G_OBJECT(child->data), DBUSMENU_MENUITEM_SIGNAL_REALIZED, G_CALLBACK(child_realized), quicklist);    
  }
}

void LauncherIcon::RecvMouseDown (int button)
{
  if (button == 3)
  {
    if (_launcher->GetActiveQuicklist () == _quicklist)
    {
      // this quicklist is already active
      return;
    }
    
    if (_launcher->GetActiveQuicklist ())
    {
      // Hide the active quicklist. This will prevent it from Ungrabing the pointer in 
      // QuicklistView::RecvMouseDownOutsideOfQuicklist or void QuicklistView::RecvMouseClick.
      // So the new quicklist that is about to be set as active will keep the grab of the pointer.
      // Also disable theinput window.
      _launcher->GetActiveQuicklist ()->EnableInputWindow (false);
      _launcher->GetActiveQuicklist ()->CaptureMouseDownAnyWhereElse (false);
      // This call must be last, because after, _launcher->GetActiveQuicklist () will return Null.
      // the launcher listen to the sigHidden signal emitted by the BaseWindow when it becomes invisible
      // and it set the active window to Null.
      _launcher->GetActiveQuicklist ()->ShowWindow (false);
    }
    
    _tooltip->ShowWindow (false);
    
    
    int tip_x = _launcher->GetBaseWidth () + 1; //icon_x + icon_w;
    int tip_y = _center.y;

    _quicklist->ShowQuicklistWithTipAt (tip_x, tip_y);
    _quicklist->EnableInputWindow (true);
    _quicklist->GrabPointer ();
    nux::GetWindowCompositor ().SetAlwaysOnFrontWindow (_quicklist);
    _quicklist->NeedRedraw ();
  }
}

void LauncherIcon::RecvMouseUp (int button)
{
  if (button == 3)
  {
    if (_quicklist->IsVisible ())
      _quicklist->CaptureMouseDownAnyWhereElse (true);
  }
}

void LauncherIcon::RecvShowQuicklist (nux::BaseWindow *quicklist)
{
  _launcher->SetActiveQuicklist (_quicklist);
}

void LauncherIcon::RecvHideQuicklist (nux::BaseWindow *quicklist)
{
  _launcher->CancelActiveQuicklist (_quicklist);
}

void LauncherIcon::HideTooltip ()
{
  _tooltip->ShowWindow (false);
}

gboolean
LauncherIcon::OnCenterTimeout (gpointer data)
{
  LauncherIcon *self = (LauncherIcon*)data;
  
  if (self->_last_stable != self->_center)
  {
    self->OnCenterStabilized (self->_center);
    self->_last_stable = self->_center;
  }

  self->_center_stabilize_handle = 0;
  return false;
}

void 
LauncherIcon::SetCenter (nux::Point3 center)
{
  _center = center;
  
  int tip_x = _launcher->GetBaseWidth () + 1; //icon_x + icon_w;
  int tip_y = _center.y;
    
  if (_quicklist->IsVisible ())
    _quicklist->ShowQuicklistWithTipAt (tip_x, tip_y);
  else if (_tooltip->IsVisible ())
    _tooltip->ShowTooltipWithTipAt (tip_x, tip_y);
    
  if (_center_stabilize_handle)
    g_source_remove (_center_stabilize_handle);
  
  _center_stabilize_handle = g_timeout_add (500, &LauncherIcon::OnCenterTimeout, this);
}

nux::Point3
LauncherIcon::GetCenter ()
{
  return _center;
}

gboolean
LauncherIcon::OnPresentTimeout (gpointer data)
{
  LauncherIcon *self = (LauncherIcon*) data;
  if (!self->GetQuirk (LAUNCHER_ICON_QUIRK_PRESENTED))
    return false;
  
  self->_present_time_handle = 0;
  self->Unpresent ();
  
  return false;
}

void 
LauncherIcon::Present (int length)
{
  if (GetQuirk (LAUNCHER_ICON_QUIRK_PRESENTED))
    return;
  
  if (length >= 0)
    _present_time_handle = g_timeout_add (length, &LauncherIcon::OnPresentTimeout, this);
  
  SetQuirk (LAUNCHER_ICON_QUIRK_PRESENTED, true);
}

void
LauncherIcon::Unpresent ()
{
  if (!GetQuirk (LAUNCHER_ICON_QUIRK_PRESENTED))
    return;
  
  if (_present_time_handle > 0)
    g_source_remove (_present_time_handle);
  
  SetQuirk (LAUNCHER_ICON_QUIRK_PRESENTED, false);
}

void 
LauncherIcon::SetRelatedWindows (int windows)
{
  if (_related_windows == windows)
    return;
    
  _related_windows = windows;
  needs_redraw.emit (this);
}

void 
LauncherIcon::Remove ()
{
  SetQuirk (LAUNCHER_ICON_QUIRK_VISIBLE, false);
  remove.emit (this);
}

void 
LauncherIcon::SetIconType (LauncherIconType type)
{
  _icon_type = type;
}

void 
LauncherIcon::SetSortPriority (int priority)
{
  _sort_priority = priority;
}

int 
LauncherIcon::SortPriority ()
{
  return _sort_priority;
}
    
LauncherIconType 
LauncherIcon::Type ()
{
  return _icon_type;
}

bool
LauncherIcon::GetQuirk (LauncherIconQuirk quirk)
{
  return _quirks[quirk];
}

void
LauncherIcon::SetQuirk (LauncherIconQuirk quirk, bool value)
{
  if (_quirks[quirk] == value)
    return;
    
  _quirks[quirk] = value;
  clock_gettime (CLOCK_MONOTONIC, &(_quirk_times[quirk]));
  needs_redraw.emit (this);
  
  // Present on urgent as a general policy
  if ((quirk == LAUNCHER_ICON_QUIRK_URGENT || quirk == LAUNCHER_ICON_QUIRK_VISIBLE) && value)
    Present ();
}

void
LauncherIcon::UpdateQuirkTime (LauncherIconQuirk quirk)
{
  clock_gettime (CLOCK_MONOTONIC, &(_quirk_times[quirk]));
  needs_redraw.emit (this);
}

void 
LauncherIcon::ResetQuirkTime (LauncherIconQuirk quirk)
{
  _quirk_times[quirk].tv_sec = 0;
  _quirk_times[quirk].tv_nsec = 0;
}

struct timespec
LauncherIcon::GetQuirkTime (LauncherIconQuirk quirk)
{
  return _quirk_times[quirk];
}

int
LauncherIcon::RelatedWindows ()
{
  return _related_windows;
}

std::list<DbusmenuClient *> LauncherIcon::Menus ()
{
  return GetMenus ();
}

std::list<DbusmenuClient *> LauncherIcon::GetMenus ()
{
  std::list<DbusmenuClient *> result;

  return result;
}
