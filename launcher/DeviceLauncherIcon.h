// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#ifndef _DEVICE_LAUNCHER_ICON_H__H
#define _DEVICE_LAUNCHER_ICON_H__H

#include <gio/gio.h>
#include <UnityCore/GLibWrapper.h>
#include <UnityCore/GLibSignal.h>

#include "SimpleLauncherIcon.h"

namespace unity
{
namespace launcher
{

class DeviceLauncherIcon : public SimpleLauncherIcon
{

public:
  DeviceLauncherIcon(glib::Object<GVolume> const& volume);

  void OnRemoved();
  bool CanEject();
  void Eject();

protected:
  std::list<DbusmenuMenuitem*> GetMenus();
  std::string GetName() const;

private:
  void UpdateVisibility();
  void UpdateDeviceIcon();
  void ActivateLauncherIcon(ActionArg arg);
  void ShowMount(GMount* mount);
  void Unmount();
  void StopDrive();
  static void OnTogglePin(DbusmenuMenuitem* item, int time, DeviceLauncherIcon* self);
  static void OnOpen(DbusmenuMenuitem* item, int time, DeviceLauncherIcon* self);
  static void OnEject(DbusmenuMenuitem* item, int time, DeviceLauncherIcon* self);
  static void OnUnmount(DbusmenuMenuitem* item, int time, DeviceLauncherIcon* self);
  static void OnChanged(GVolume* volume, DeviceLauncherIcon* self);
  static void OnMountReady(GObject* object, GAsyncResult* result, DeviceLauncherIcon* self);
  static void OnEjectReady(GObject* object, GAsyncResult* result, DeviceLauncherIcon* self);
  static void OnUnmountReady(GObject* object, GAsyncResult* result, DeviceLauncherIcon* self);
  static void OnDriveStop(DbusmenuMenuitem* item, int time, DeviceLauncherIcon* self);
  void OnVolumeChanged(GVolume* volume);
  void OnSettingsChanged();
  void ShowNotification(std::string const&, unsigned, glib::Object<GdkPixbuf> const&, std::string const&);

private:
  glib::Signal<void, GVolume*> signal_volume_changed_;
  glib::Source::UniquePtr changed_timeout_;
  glib::Object<GVolume> volume_;

  std::string name_;
  bool keep_in_launcher_;
};

}
} // namespace unity

#endif // _DEVICE_LAUNCHER_ICON_H__H