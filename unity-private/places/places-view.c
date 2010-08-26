/* places-view.c generated by valac 0.9.7, the Vala compiler
 * generated from places-view.vala, do not modify */

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
 * Authored by Mirco "MacSlow" Müller <mirco.mueller@canonical.com>
 *             Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <unity.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <dee.h>
#include <float.h>
#include <math.h>
#include <clutter/clutter.h>


#define UNITY_PLACES_TYPE_VIEW (unity_places_view_get_type ())
#define UNITY_PLACES_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_VIEW, UnityPlacesView))
#define UNITY_PLACES_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewClass))
#define UNITY_PLACES_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_VIEW))
#define UNITY_PLACES_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_VIEW))
#define UNITY_PLACES_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewClass))

typedef struct _UnityPlacesView UnityPlacesView;
typedef struct _UnityPlacesViewClass UnityPlacesViewClass;
typedef struct _UnityPlacesViewPrivate UnityPlacesViewPrivate;

#define UNITY_PLACES_TYPE_PLACE_HOME_ENTRY (unity_places_place_home_entry_get_type ())
#define UNITY_PLACES_PLACE_HOME_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY, UnityPlacesPlaceHomeEntry))
#define UNITY_PLACES_PLACE_HOME_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY, UnityPlacesPlaceHomeEntryClass))
#define UNITY_PLACES_IS_PLACE_HOME_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY))
#define UNITY_PLACES_IS_PLACE_HOME_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY))
#define UNITY_PLACES_PLACE_HOME_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY, UnityPlacesPlaceHomeEntryClass))

typedef struct _UnityPlacesPlaceHomeEntry UnityPlacesPlaceHomeEntry;
typedef struct _UnityPlacesPlaceHomeEntryClass UnityPlacesPlaceHomeEntryClass;

#define UNITY_PLACES_TYPE_PLACE_SEARCH_BAR (unity_places_place_search_bar_get_type ())
#define UNITY_PLACES_PLACE_SEARCH_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR, UnityPlacesPlaceSearchBar))
#define UNITY_PLACES_PLACE_SEARCH_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR, UnityPlacesPlaceSearchBarClass))
#define UNITY_PLACES_IS_PLACE_SEARCH_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR))
#define UNITY_PLACES_IS_PLACE_SEARCH_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR))
#define UNITY_PLACES_PLACE_SEARCH_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR, UnityPlacesPlaceSearchBarClass))

typedef struct _UnityPlacesPlaceSearchBar UnityPlacesPlaceSearchBar;
typedef struct _UnityPlacesPlaceSearchBarClass UnityPlacesPlaceSearchBarClass;

#define UNITY_PLACES_TYPE_PLACE_MODEL (unity_places_place_model_get_type ())
#define UNITY_PLACES_PLACE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_MODEL, UnityPlacesPlaceModel))
#define UNITY_PLACES_PLACE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_MODEL, UnityPlacesPlaceModelClass))
#define UNITY_PLACES_IS_PLACE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_MODEL))
#define UNITY_PLACES_IS_PLACE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_MODEL))
#define UNITY_PLACES_PLACE_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_MODEL, UnityPlacesPlaceModelClass))

typedef struct _UnityPlacesPlaceModel UnityPlacesPlaceModel;
typedef struct _UnityPlacesPlaceModelClass UnityPlacesPlaceModelClass;

#define UNITY_PLACES_TYPE_PLACE_ENTRY (unity_places_place_entry_get_type ())
#define UNITY_PLACES_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntry))
#define UNITY_PLACES_IS_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_PLACE_ENTRY_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryIface))

typedef struct _UnityPlacesPlaceEntry UnityPlacesPlaceEntry;
typedef struct _UnityPlacesPlaceEntryIface UnityPlacesPlaceEntryIface;

#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER (unity_places_folder_browser_renderer_get_type ())
#define UNITY_PLACES_FOLDER_BROWSER_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER, UnityPlacesFolderBrowserRenderer))
#define UNITY_PLACES_FOLDER_BROWSER_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER, UnityPlacesFolderBrowserRendererClass))
#define UNITY_PLACES_IS_FOLDER_BROWSER_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER))
#define UNITY_PLACES_IS_FOLDER_BROWSER_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER))
#define UNITY_PLACES_FOLDER_BROWSER_RENDERER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_FOLDER_BROWSER_RENDERER, UnityPlacesFolderBrowserRendererClass))

typedef struct _UnityPlacesFolderBrowserRenderer UnityPlacesFolderBrowserRenderer;
typedef struct _UnityPlacesFolderBrowserRendererClass UnityPlacesFolderBrowserRendererClass;

#define UNITY_PLACES_TYPE_HOME_RENDERER (unity_places_home_renderer_get_type ())
#define UNITY_PLACES_HOME_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_HOME_RENDERER, UnityPlacesHomeRenderer))
#define UNITY_PLACES_HOME_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_HOME_RENDERER, UnityPlacesHomeRendererClass))
#define UNITY_PLACES_IS_HOME_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_HOME_RENDERER))
#define UNITY_PLACES_IS_HOME_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_HOME_RENDERER))
#define UNITY_PLACES_HOME_RENDERER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_HOME_RENDERER, UnityPlacesHomeRendererClass))

typedef struct _UnityPlacesHomeRenderer UnityPlacesHomeRenderer;
typedef struct _UnityPlacesHomeRendererClass UnityPlacesHomeRendererClass;

#define UNITY_PLACES_TYPE_DEFAULT_RENDERER (unity_places_default_renderer_get_type ())
#define UNITY_PLACES_DEFAULT_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_DEFAULT_RENDERER, UnityPlacesDefaultRenderer))
#define UNITY_PLACES_DEFAULT_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_DEFAULT_RENDERER, UnityPlacesDefaultRendererClass))
#define UNITY_PLACES_IS_DEFAULT_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_DEFAULT_RENDERER))
#define UNITY_PLACES_IS_DEFAULT_RENDERER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_DEFAULT_RENDERER))
#define UNITY_PLACES_DEFAULT_RENDERER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_DEFAULT_RENDERER, UnityPlacesDefaultRendererClass))

typedef struct _UnityPlacesDefaultRenderer UnityPlacesDefaultRenderer;
typedef struct _UnityPlacesDefaultRendererClass UnityPlacesDefaultRendererClass;

#define UNITY_PLACES_TYPE_ACTIVATION_STATUS (unity_places_activation_status_get_type ())

struct _UnityPlacesView {
	CtkBox parent_instance;
	UnityPlacesViewPrivate * priv;
	UnityPlacesPlaceHomeEntry* home_entry;
	UnityPlacesPlaceSearchBar* search_bar;
};

struct _UnityPlacesViewClass {
	CtkBoxClass parent_class;
};

struct _UnityPlacesPlaceEntryIface {
	GTypeInterface parent_iface;
	void (*connect) (UnityPlacesPlaceEntry* self);
	void (*set_search) (UnityPlacesPlaceEntry* self, const char* search, GHashTable* hints);
	void (*set_active_section) (UnityPlacesPlaceEntry* self, guint section_id);
	void (*set_global_search) (UnityPlacesPlaceEntry* self, const char* search, GHashTable* hints);
	const char* (*get_name) (UnityPlacesPlaceEntry* self);
	void (*set_name) (UnityPlacesPlaceEntry* self, const char* value);
	const char* (*get_icon) (UnityPlacesPlaceEntry* self);
	void (*set_icon) (UnityPlacesPlaceEntry* self, const char* value);
	const char* (*get_description) (UnityPlacesPlaceEntry* self);
	void (*set_description) (UnityPlacesPlaceEntry* self, const char* value);
	guint (*get_position) (UnityPlacesPlaceEntry* self);
	void (*set_position) (UnityPlacesPlaceEntry* self, guint value);
	char** (*get_mimetypes) (UnityPlacesPlaceEntry* self, int* result_length1);
	void (*set_mimetypes) (UnityPlacesPlaceEntry* self, char** value, int value_length1);
	gboolean (*get_sensitive) (UnityPlacesPlaceEntry* self);
	void (*set_sensitive) (UnityPlacesPlaceEntry* self, gboolean value);
	GeeHashMap* (*get_hints) (UnityPlacesPlaceEntry* self);
	void (*set_hints) (UnityPlacesPlaceEntry* self, GeeHashMap* value);
	gboolean (*get_online) (UnityPlacesPlaceEntry* self);
	void (*set_online) (UnityPlacesPlaceEntry* self, gboolean value);
	gboolean (*get_active) (UnityPlacesPlaceEntry* self);
	void (*set_active) (UnityPlacesPlaceEntry* self, gboolean value);
	DeeModel* (*get_sections_model) (UnityPlacesPlaceEntry* self);
	void (*set_sections_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	const char* (*get_entry_renderer_name) (UnityPlacesPlaceEntry* self);
	void (*set_entry_renderer_name) (UnityPlacesPlaceEntry* self, const char* value);
	DeeModel* (*get_entry_groups_model) (UnityPlacesPlaceEntry* self);
	void (*set_entry_groups_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	DeeModel* (*get_entry_results_model) (UnityPlacesPlaceEntry* self);
	void (*set_entry_results_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	GeeHashMap* (*get_entry_renderer_hints) (UnityPlacesPlaceEntry* self);
	void (*set_entry_renderer_hints) (UnityPlacesPlaceEntry* self, GeeHashMap* value);
	const char* (*get_global_renderer_name) (UnityPlacesPlaceEntry* self);
	void (*set_global_renderer_name) (UnityPlacesPlaceEntry* self, const char* value);
	DeeModel* (*get_global_groups_model) (UnityPlacesPlaceEntry* self);
	void (*set_global_groups_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	DeeModel* (*get_global_results_model) (UnityPlacesPlaceEntry* self);
	void (*set_global_results_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	GeeHashMap* (*get_global_renderer_hints) (UnityPlacesPlaceEntry* self);
	void (*set_global_renderer_hints) (UnityPlacesPlaceEntry* self, GeeHashMap* value);
	UnityPlacesPlace* (*get_parent) (UnityPlacesPlaceEntry* self);
	void (*set_parent) (UnityPlacesPlaceEntry* self, UnityPlacesPlace* value);
};

struct _UnityPlacesViewPrivate {
	UnityShell* _shell;
	UnityPlacesPlaceModel* _model;
	CtkVBox* content_box;
	UnityLayeredBin* layered_bin;
	UnityPlaceRenderer* renderer;
	UnityPlacesPlaceEntry* active_entry;
	gboolean is_showing;
};

typedef enum  {
	UNITY_PLACES_ACTIVATION_STATUS_NOT_ACTIVATED,
	UNITY_PLACES_ACTIVATION_STATUS_ACTIVATED_FALLBACK,
	UNITY_PLACES_ACTIVATION_STATUS_ACTIVATED_SHOW_DASH,
	UNITY_PLACES_ACTIVATION_STATUS_ACTIVATED_HIDE_DASH
} UnityPlacesActivationStatus;


static gpointer unity_places_view_parent_class = NULL;

GType unity_places_view_get_type (void) G_GNUC_CONST;
GType unity_places_place_home_entry_get_type (void) G_GNUC_CONST;
GType unity_places_place_search_bar_get_type (void) G_GNUC_CONST;
GType unity_places_place_model_get_type (void) G_GNUC_CONST;
GType unity_places_place_get_type (void) G_GNUC_CONST;
GType unity_places_place_entry_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewPrivate))
enum  {
	UNITY_PLACES_VIEW_DUMMY_PROPERTY,
	UNITY_PLACES_VIEW_SHELL,
	UNITY_PLACES_VIEW_MODEL
};
#define UNITY_PLACES_VIEW_PADDING 8.0f
UnityPlacesView* unity_places_view_new (UnityShell* shell, UnityPlacesPlaceModel* model);
UnityPlacesView* unity_places_view_construct (GType object_type, UnityShell* shell, UnityPlacesPlaceModel* model);
void unity_places_view_about_to_show (UnityPlacesView* self);
UnityShell* unity_places_view_get_shell (UnityPlacesView* self);
UnityPlacesPlaceModel* unity_places_view_get_model (UnityPlacesView* self);
UnityPlacesPlaceHomeEntry* unity_places_place_home_entry_new (UnityShell* shell, UnityPlacesPlaceModel* model);
UnityPlacesPlaceHomeEntry* unity_places_place_home_entry_construct (GType object_type, UnityShell* shell, UnityPlacesPlaceModel* model);
UnityPlacesPlaceSearchBar* unity_places_place_search_bar_new (void);
UnityPlacesPlaceSearchBar* unity_places_place_search_bar_construct (GType object_type);
void unity_places_view_shown (UnityPlacesView* self);
void unity_places_place_search_bar_reset (UnityPlacesPlaceSearchBar* self);
void unity_places_view_on_entry_view_activated (UnityPlacesView* self, UnityPlacesPlaceEntry* entry, guint section_id);
void unity_places_view_hidden (UnityPlacesView* self);
void unity_places_place_entry_set_active (UnityPlacesPlaceEntry* self, gboolean value);
static void unity_places_view_on_entry_renderer_info_changed (UnityPlacesView* self, UnityPlacesPlaceEntry* entry);
static void _unity_places_view_on_entry_renderer_info_changed_unity_places_place_entry_renderer_info_changed (UnityPlacesPlaceEntry* _sender, gpointer self);
static void unity_places_view_update_views (UnityPlacesView* self, UnityPlacesPlaceEntry* entry, guint section_id);
static void _lambda38_ (ClutterAnimation* a, UnityPlacesView* self);
static void __lambda38__clutter_animation_completed (ClutterAnimation* _sender, gpointer self);
static UnityPlaceRenderer* unity_places_view_lookup_renderer (UnityPlacesView* self, UnityPlacesPlaceEntry* entry);
DeeModel* unity_places_place_entry_get_entry_groups_model (UnityPlacesPlaceEntry* self);
DeeModel* unity_places_place_entry_get_entry_results_model (UnityPlacesPlaceEntry* self);
GeeHashMap* unity_places_place_entry_get_entry_renderer_hints (UnityPlacesPlaceEntry* self);
static void unity_places_view_on_result_activated (UnityPlacesView* self, const char* uri, const char* mimetype);
static void _unity_places_view_on_result_activated_unity_place_renderer_activated (UnityPlaceRenderer* _sender, const char* uri, const char* mimetype, gpointer self);
void unity_places_place_search_bar_set_active_entry_view (UnityPlacesPlaceSearchBar* self, UnityPlacesPlaceEntry* entry, gint x, guint section);
GeeHashMap* unity_places_place_entry_get_hints (UnityPlacesPlaceEntry* self);
UnityPlacesFolderBrowserRenderer* unity_places_folder_browser_renderer_new (void);
UnityPlacesFolderBrowserRenderer* unity_places_folder_browser_renderer_construct (GType object_type);
GType unity_places_folder_browser_renderer_get_type (void) G_GNUC_CONST;
const char* unity_places_place_entry_get_entry_renderer_name (UnityPlacesPlaceEntry* self);
UnityPlacesHomeRenderer* unity_places_home_renderer_new (void);
UnityPlacesHomeRenderer* unity_places_home_renderer_construct (GType object_type);
GType unity_places_home_renderer_get_type (void) G_GNUC_CONST;
UnityPlacesDefaultRenderer* unity_places_default_renderer_new (void);
UnityPlacesDefaultRenderer* unity_places_default_renderer_construct (GType object_type);
GType unity_places_default_renderer_get_type (void) G_GNUC_CONST;
UnityPlacesPlace* unity_places_place_entry_get_parent (UnityPlacesPlaceEntry* self);
GType unity_places_activation_status_get_type (void) G_GNUC_CONST;
UnityPlacesActivationStatus unity_places_place_activate (UnityPlacesPlace* self, const char* uri, const char* mimetype);
static void unity_places_view_set_shell (UnityPlacesView* self, UnityShell* value);
static void unity_places_view_set_model (UnityPlacesView* self, UnityPlacesPlaceModel* value);
static GObject * unity_places_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_view_finalize (GObject* obj);
static void unity_places_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



UnityPlacesView* unity_places_view_construct (GType object_type, UnityShell* shell, UnityPlacesPlaceModel* model) {
	UnityPlacesView * self;
	g_return_val_if_fail (shell != NULL, NULL);
	g_return_val_if_fail (model != NULL, NULL);
	self = (UnityPlacesView*) g_object_new (object_type, "shell", shell, "orientation", CTK_ORIENTATION_VERTICAL, "model", model, NULL);
	return self;
}


UnityPlacesView* unity_places_view_new (UnityShell* shell, UnityPlacesPlaceModel* model) {
	return unity_places_view_construct (UNITY_PLACES_TYPE_VIEW, shell, model);
}


void unity_places_view_about_to_show (UnityPlacesView* self) {
	UnityPlacesPlaceHomeEntry* _tmp0_;
	CtkVBox* _tmp1_;
	CtkPadding _tmp2_ = {0};
	CtkPadding _tmp3_;
	UnityPlacesPlaceSearchBar* _tmp4_;
	UnityLayeredBin* _tmp5_;
	g_return_if_fail (self != NULL);
	if (UNITY_PLACES_IS_PLACE_HOME_ENTRY (self->home_entry)) {
		return;
	}
	self->home_entry = (_tmp0_ = unity_places_place_home_entry_new (self->priv->_shell, self->priv->_model), _g_object_unref0 (self->home_entry), _tmp0_);
	self->priv->content_box = (_tmp1_ = g_object_ref_sink ((CtkVBox*) ctk_vbox_new ((guint) 4)), _g_object_unref0 (self->priv->content_box), _tmp1_);
	ctk_actor_set_padding ((CtkActor*) self->priv->content_box, (_tmp3_ = (_tmp2_.top = UNITY_PLACES_VIEW_PADDING * 2.5f, _tmp2_.right = UNITY_PLACES_VIEW_PADDING, _tmp2_.bottom = 0.0f, _tmp2_.left = UNITY_PLACES_VIEW_PADDING, _tmp2_), &_tmp3_));
	ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->content_box, TRUE, TRUE);
	clutter_actor_show ((ClutterActor*) self->priv->content_box);
	self->search_bar = (_tmp4_ = g_object_ref_sink (unity_places_place_search_bar_new ()), _g_object_unref0 (self->search_bar), _tmp4_);
	ctk_box_pack ((CtkBox*) self->priv->content_box, (ClutterActor*) self->search_bar, FALSE, TRUE);
	clutter_actor_show ((ClutterActor*) self->search_bar);
	self->priv->layered_bin = (_tmp5_ = g_object_ref_sink (unity_layered_bin_new ()), _g_object_unref0 (self->priv->layered_bin), _tmp5_);
	ctk_box_pack ((CtkBox*) self->priv->content_box, (ClutterActor*) self->priv->layered_bin, TRUE, TRUE);
	clutter_actor_show ((ClutterActor*) self->priv->layered_bin);
}


void unity_places_view_shown (UnityPlacesView* self) {
	g_return_if_fail (self != NULL);
	self->priv->is_showing = TRUE;
	unity_places_place_search_bar_reset (self->search_bar);
	unity_places_view_on_entry_view_activated (self, (UnityPlacesPlaceEntry*) self->home_entry, (guint) 0);
}


void unity_places_view_hidden (UnityPlacesView* self) {
	g_return_if_fail (self != NULL);
	self->priv->is_showing = FALSE;
	if (UNITY_PLACES_IS_PLACE_ENTRY (self->priv->active_entry)) {
		unity_places_place_entry_set_active (self->priv->active_entry, FALSE);
	}
	self->priv->active_entry = NULL;
}


static void _unity_places_view_on_entry_renderer_info_changed_unity_places_place_entry_renderer_info_changed (UnityPlacesPlaceEntry* _sender, gpointer self) {
	unity_places_view_on_entry_renderer_info_changed (self, _sender);
}


void unity_places_view_on_entry_view_activated (UnityPlacesView* self, UnityPlacesPlaceEntry* entry, guint section_id) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	if (UNITY_PLACES_IS_PLACE_ENTRY (self->priv->active_entry)) {
		unity_places_place_entry_set_active (self->priv->active_entry, FALSE);
		if (self->priv->active_entry != self->home_entry) {
			guint _tmp0_;
			g_signal_parse_name ("renderer-info-changed", UNITY_PLACES_TYPE_PLACE_ENTRY, &_tmp0_, NULL, FALSE);
			g_signal_handlers_disconnect_matched (self->priv->active_entry, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp0_, 0, NULL, (GCallback) _unity_places_view_on_entry_renderer_info_changed_unity_places_place_entry_renderer_info_changed, self);
		}
	}
	self->priv->active_entry = entry;
	unity_places_place_entry_set_active (entry, TRUE);
	unity_places_view_update_views (self, entry, section_id);
	g_signal_connect_object (entry, "renderer-info-changed", (GCallback) _unity_places_view_on_entry_renderer_info_changed_unity_places_place_entry_renderer_info_changed, self, 0);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _lambda38_ (ClutterAnimation* a, UnityPlacesView* self) {
	GObject* _tmp0_;
	g_return_if_fail (a != NULL);
	clutter_actor_destroy ((_tmp0_ = clutter_animation_get_object (a), CLUTTER_IS_ACTOR (_tmp0_) ? ((ClutterActor*) _tmp0_) : NULL));
}


static void __lambda38__clutter_animation_completed (ClutterAnimation* _sender, gpointer self) {
	_lambda38_ (_sender, self);
}


static void _unity_places_view_on_result_activated_unity_place_renderer_activated (UnityPlaceRenderer* _sender, const char* uri, const char* mimetype, gpointer self) {
	unity_places_view_on_result_activated (self, uri, mimetype);
}


static void unity_places_view_update_views (UnityPlacesView* self, UnityPlacesPlaceEntry* entry, guint section_id) {
	UnityPlaceRenderer* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	if (CLUTTER_IS_ACTOR (self->priv->renderer)) {
		ClutterAnimation* anim;
		anim = _g_object_ref0 (clutter_actor_animate ((ClutterActor*) self->priv->renderer, (gulong) CLUTTER_EASE_OUT_QUAD, (guint) 300, "opacity", 0, NULL));
		g_signal_connect_object (anim, "completed", (GCallback) __lambda38__clutter_animation_completed, self, 0);
		_g_object_unref0 (anim);
	}
	self->priv->renderer = (_tmp0_ = unity_places_view_lookup_renderer (self, entry), _g_object_unref0 (self->priv->renderer), _tmp0_);
	clutter_container_add_actor ((ClutterContainer*) self->priv->layered_bin, (ClutterActor*) self->priv->renderer);
	clutter_actor_set_opacity ((ClutterActor*) self->priv->renderer, (guint8) 0);
	clutter_actor_animate ((ClutterActor*) self->priv->renderer, (gulong) CLUTTER_EASE_OUT_QUAD, (guint) 300, "opacity", 255, NULL);
	unity_place_renderer_set_models (self->priv->renderer, unity_places_place_entry_get_entry_groups_model (entry), unity_places_place_entry_get_entry_results_model (entry), unity_places_place_entry_get_entry_renderer_hints (entry));
	clutter_actor_show ((ClutterActor*) self->priv->renderer);
	g_signal_connect_object (self->priv->renderer, "activated", (GCallback) _unity_places_view_on_result_activated_unity_place_renderer_activated, self, 0);
	unity_places_place_search_bar_set_active_entry_view (self->search_bar, entry, 0, section_id);
}


static void unity_places_view_on_entry_renderer_info_changed (UnityPlacesView* self, UnityPlacesPlaceEntry* entry) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	unity_places_view_update_views (self, entry, 0);
}


static UnityPlaceRenderer* unity_places_view_lookup_renderer (UnityPlacesView* self, UnityPlacesPlaceEntry* entry) {
	UnityPlaceRenderer* result = NULL;
	char* browser_path;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (entry != NULL, NULL);
	browser_path = NULL;
	if (unity_places_place_entry_get_hints (entry) != NULL) {
		{
			GeeIterator* _e_it;
			_e_it = gee_iterable_iterator ((GeeIterable*) unity_places_place_entry_get_hints (entry));
			while (TRUE) {
				GeeMapEntry* e;
				if (!gee_iterator_next (_e_it)) {
					break;
				}
				e = (GeeMapEntry*) gee_iterator_get (_e_it);
				if (_vala_strcmp0 ((const char*) gee_map_entry_get_key (e), "UnityPlaceBrowserPath") == 0) {
					char* _tmp0_;
					browser_path = (_tmp0_ = g_strdup ((const char*) gee_map_entry_get_value (e)), _g_free0 (browser_path), _tmp0_);
				}
				_g_object_unref0 (e);
			}
			_g_object_unref0 (_e_it);
		}
	}
	if (browser_path != NULL) {
		result = (UnityPlaceRenderer*) g_object_ref_sink (unity_places_folder_browser_renderer_new ());
		_g_free0 (browser_path);
		return result;
	} else {
		if (_vala_strcmp0 (unity_places_place_entry_get_entry_renderer_name (entry), "UnityHomeScreen") == 0) {
			result = (UnityPlaceRenderer*) g_object_ref_sink (unity_places_home_renderer_new ());
			_g_free0 (browser_path);
			return result;
		} else {
			result = (UnityPlaceRenderer*) g_object_ref_sink (unity_places_default_renderer_new ());
			_g_free0 (browser_path);
			return result;
		}
	}
	_g_free0 (browser_path);
}


static void unity_places_view_on_result_activated (UnityPlacesView* self, const char* uri, const char* mimetype) {
	UnityPlacesActivationStatus _result_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (uri != NULL);
	g_return_if_fail (mimetype != NULL);
	_result_ = unity_places_place_activate (unity_places_place_entry_get_parent (self->priv->active_entry), uri, mimetype);
	switch (_result_) {
		case UNITY_PLACES_ACTIVATION_STATUS_ACTIVATED_SHOW_DASH:
		{
			break;
		}
		case UNITY_PLACES_ACTIVATION_STATUS_NOT_ACTIVATED:
		case UNITY_PLACES_ACTIVATION_STATUS_ACTIVATED_HIDE_DASH:
		case UNITY_PLACES_ACTIVATION_STATUS_ACTIVATED_FALLBACK:
		{
			unity_shell_hide_unity (unity_global_shell);
			break;
		}
		default:
		{
			g_warning ("places-view.vala:188: Unexpected activation status: %u", (guint) _result_);
			break;
		}
	}
}


UnityShell* unity_places_view_get_shell (UnityPlacesView* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
	return result;
}


static void unity_places_view_set_shell (UnityPlacesView* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


UnityPlacesPlaceModel* unity_places_view_get_model (UnityPlacesView* self) {
	UnityPlacesPlaceModel* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_model;
	return result;
}


static void unity_places_view_set_model (UnityPlacesView* self, UnityPlacesPlaceModel* value) {
	UnityPlacesPlaceModel* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_model = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_model), _tmp0_);
	g_object_notify ((GObject *) self, "model");
}


static GObject * unity_places_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesView * self;
	parent_class = G_OBJECT_CLASS (unity_places_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_VIEW (obj);
	{
		unity_places_view_about_to_show (self);
	}
	return obj;
}


static void unity_places_view_class_init (UnityPlacesViewClass * klass) {
	unity_places_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesViewPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_places_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_view_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_VIEW_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_VIEW_MODEL, g_param_spec_object ("model", "model", "model", UNITY_PLACES_TYPE_PLACE_MODEL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_places_view_instance_init (UnityPlacesView * self) {
	self->priv = UNITY_PLACES_VIEW_GET_PRIVATE (self);
	self->priv->active_entry = NULL;
	self->priv->is_showing = FALSE;
}


static void unity_places_view_finalize (GObject* obj) {
	UnityPlacesView * self;
	self = UNITY_PLACES_VIEW (obj);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->_model);
	_g_object_unref0 (self->priv->content_box);
	_g_object_unref0 (self->priv->layered_bin);
	_g_object_unref0 (self->home_entry);
	_g_object_unref0 (self->search_bar);
	_g_object_unref0 (self->priv->renderer);
	G_OBJECT_CLASS (unity_places_view_parent_class)->finalize (obj);
}


GType unity_places_view_get_type (void) {
	static volatile gsize unity_places_view_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesView), 0, (GInstanceInitFunc) unity_places_view_instance_init, NULL };
		GType unity_places_view_type_id;
		unity_places_view_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPlacesView", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_view_type_id__volatile, unity_places_view_type_id);
	}
	return unity_places_view_type_id__volatile;
}


static void unity_places_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesView * self;
	self = UNITY_PLACES_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_VIEW_SHELL:
		g_value_set_object (value, unity_places_view_get_shell (self));
		break;
		case UNITY_PLACES_VIEW_MODEL:
		g_value_set_object (value, unity_places_view_get_model (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesView * self;
	self = UNITY_PLACES_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_VIEW_SHELL:
		unity_places_view_set_shell (self, g_value_get_object (value));
		break;
		case UNITY_PLACES_VIEW_MODEL:
		unity_places_view_set_model (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




