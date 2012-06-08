#include <gtest/gtest.h>
#include <gio/gio.h>
#include <gtk/gtk.h>
#include <NuxCore/Logger.h>
#include <Nux/Nux.h>

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  gtk_init(&argc, &argv);
  
  nux::NuxInitialize (0);
  nux::WindowThread* wnd_thread = nux::CreateNuxWindow("Tests", 300, 200, nux::WINDOWSTYLE_NORMAL, NULL, false, NULL, NULL);

  // Slightly higher as we're more likely to test things we know will fail
  nux::logging::configure_logging("<root>=error");

  // but you can still change it if you're debugging ;)
  nux::logging::configure_logging(::getenv("UNITY_LOG_SEVERITY"));

  int ret = RUN_ALL_TESTS();

  delete wnd_thread;

  return ret;
}

