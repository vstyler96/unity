/*
 * Copyright 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Andrea Azzarone <azzarone@gmail.com>
 *              Brandon Schaefer <brandon.schaefer@canonical.com>
 *              Marco Trevisan <marco.trevisan@canonical.com>
 */

#include <config.h>
#include <gmock/gmock.h>

#include <UnityCore/GLibWrapper.h>
#include <UnityCore/DesktopUtilities.h>

#include "BamfLauncherIcon.h"
#include "FavoriteStore.h"

using namespace unity;
using namespace unity::launcher;

namespace
{

const std::string USC_DESKTOP = BUILDDIR"/tests/data/applications/ubuntu-software-center.desktop";
const std::string NO_ICON_DESKTOP = BUILDDIR"/tests/data/applications/no-icon.desktop";

class TestBamfLauncherIcon : public testing::Test
{
public:
  virtual void SetUp()
  {
    BamfApplication* bamf_app;
    bamf_matcher = bamf_matcher_get_default();

    bamf_app = bamf_matcher_get_application_for_desktop_file(bamf_matcher, USC_DESKTOP.c_str(), TRUE);
    usc_icon = new launcher::BamfLauncherIcon(bamf_app);
    ASSERT_EQ(usc_icon->DesktopFile(), USC_DESKTOP);

    bamf_app = bamf_matcher_get_application_for_desktop_file(bamf_matcher, NO_ICON_DESKTOP.c_str(), TRUE);
    empty_icon = new launcher::BamfLauncherIcon(bamf_app);
    ASSERT_EQ(empty_icon->DesktopFile(), NO_ICON_DESKTOP);

    bamf_app = static_cast<BamfApplication*>(g_object_new(BAMF_TYPE_APPLICATION, nullptr));
    empty_app = new launcher::BamfLauncherIcon(bamf_app);
    ASSERT_TRUE(empty_app->DesktopFile().empty());
  }

  glib::Object<BamfMatcher> bamf_matcher;
  nux::ObjectPtr<launcher::BamfLauncherIcon> usc_icon;
  nux::ObjectPtr<launcher::BamfLauncherIcon> empty_icon;
  nux::ObjectPtr<launcher::BamfLauncherIcon> empty_app;
};

TEST_F(TestBamfLauncherIcon, Position)
{
  EXPECT_EQ(usc_icon->position(), AbstractLauncherIcon::Position::FLOATING);
}

TEST_F(TestBamfLauncherIcon, TestCustomBackgroundColor)
{
  nux::Color const& color = usc_icon->BackgroundColor();

  EXPECT_EQ(color.red, 0xaa / 255.0f);
  EXPECT_EQ(color.green, 0xbb / 255.0f);
  EXPECT_EQ(color.blue, 0xcc / 255.0f);
  EXPECT_EQ(color.alpha, 0xff / 255.0f);
}

TEST_F(TestBamfLauncherIcon, TestDefaultIcon)
{
  EXPECT_EQ(usc_icon->icon_name.Get(), "softwarecenter");
  EXPECT_EQ(empty_icon->icon_name.Get(), "application-default-icon");
  EXPECT_EQ(empty_app->icon_name.Get(), "application-default-icon");
}

TEST_F(TestBamfLauncherIcon, Stick)
{
  BamfView* bamf_app = BAMF_VIEW(bamf_matcher_get_application_for_desktop_file(bamf_matcher, USC_DESKTOP.c_str(), FALSE));
  ASSERT_FALSE(bamf_view_is_sticky(bamf_app));

  bool saved = false;
  usc_icon->position_saved.connect([&saved] {saved = true;});

  usc_icon->Stick(false);
  EXPECT_TRUE(bamf_view_is_sticky(bamf_app));
  EXPECT_TRUE(usc_icon->IsSticky());
  EXPECT_TRUE(usc_icon->IsVisible());
  EXPECT_FALSE(saved);

  usc_icon->Stick(true);
  EXPECT_FALSE(saved);
  bamf_view_set_sticky(bamf_app, FALSE);
}

TEST_F(TestBamfLauncherIcon, StickAndSave)
{
  BamfView* bamf_app = BAMF_VIEW(bamf_matcher_get_application_for_desktop_file(bamf_matcher, USC_DESKTOP.c_str(), FALSE));
  ASSERT_FALSE(bamf_view_is_sticky(bamf_app));

  bool saved = false;
  usc_icon->position_saved.connect([&saved] {saved = true;});

  usc_icon->Stick(true);
  EXPECT_TRUE(bamf_view_is_sticky(bamf_app));
  EXPECT_TRUE(usc_icon->IsSticky());
  EXPECT_TRUE(usc_icon->IsVisible());
  EXPECT_TRUE(saved);
  bamf_view_set_sticky(bamf_app, FALSE);
}

TEST_F(TestBamfLauncherIcon, Unstick)
{
  BamfView* bamf_app = BAMF_VIEW(bamf_matcher_get_application_for_desktop_file(bamf_matcher, USC_DESKTOP.c_str(), FALSE));
  ASSERT_FALSE(bamf_view_is_sticky(bamf_app));

  bool forgot = false;
  usc_icon->position_forgot.connect([&forgot] {forgot = true;});

  usc_icon->Stick(false);
  ASSERT_TRUE(bamf_view_is_sticky(bamf_app));
  ASSERT_TRUE(usc_icon->IsSticky());

  usc_icon->UnStick();
  EXPECT_FALSE(bamf_view_is_sticky(bamf_app));
  EXPECT_FALSE(usc_icon->IsSticky());
  EXPECT_FALSE(usc_icon->IsVisible());
  EXPECT_TRUE(forgot);
}

TEST_F(TestBamfLauncherIcon, RemoteUri)
{
  EXPECT_EQ(usc_icon->RemoteUri(), FavoriteStore::URI_PREFIX_APP + DesktopUtilities::GetDesktopID(USC_DESKTOP));
  EXPECT_TRUE(empty_app->RemoteUri().empty());
}

}
