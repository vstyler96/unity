# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
# Copyright 2012 Canonical
# Author: Thomi Richards
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 3, as published
# by the Free Software Foundation.

"""Autopilot test case class for Unity-specific tests."""

from __future__ import absolute_import

from autopilot.testcase import AutopilotTestCase
from dbus import DBusException
import os
from tempfile import mktemp
from testtools.content import text_content
from testtools.matchers import Equals

from unity.emulators.dash import Dash
from unity.emulators.hud import Hud
from unity.emulators.launcher import LauncherController
from unity.emulators.panel import PanelController
from unity.emulators.switcher import Switcher
from unity.emulators.window_manager import WindowManager
from unity.emulators.workspace import WorkspaceManager
from unity.emulators.unity import (
    set_log_severity,
    start_log_to_file,
    reset_logging,
    )



class UnityTestCase(AutopilotTestCase):
    """Unity test case base class, with improvments specific to Unity tests."""

    def __init__(self, *args):
        super(UnityTestCase, self).__init__(*args)

    def setUp(self):
        super(UnityTestCase, self).setUp()
        self._setUpUnityLogging()
        self._initial_workspace_num = self.workspace.current_workspace
        self.addCleanup(self.check_test_behavior)
        #
        # Setting this here since the show desktop feature seems to be a bit
        # ropey. Once it's been proven to work reliably we can remove this line:
        self.set_unity_log_level("unity.plugin", "DEBUG")

    def check_test_behavior(self):
        """Fail the test if it did something naughty.

        This includes leaving the dash or the hud open, changing the current
        workspace, or leaving the system in show_desktop mode.

        """
        well_behaved = True
        reasons = []

        # Have we switched workspace?
        if self.workspace.current_workspace != self._initial_workspace_num:
            well_behaved = False
            reasons.append("The test changed the active workspace from %d to %d." \
                % (self._initial_workspace_num, self.workspace.current_workspace))
            self.workspace.switch_to(self._initial_workspace_num)
        # Have we left the dash open?
        if self.dash.visible:
            well_behaved = False
            reasons.append("The test left the dash open.")
            self.dash.ensure_hidden()
        # ... or the hud?
        if self.hud.visible:
            well_behaved = False
            reasons.append("The test left the hud open.")
            self.hud.ensure_hidden()
        # Are we in show desktop mode?
        if self.window_manager.showdesktop_active:
            well_behaved = False
            reasons.append("The test left the system in show_desktop mode.")
            self.window_manager.leave_show_desktop()

        if not well_behaved:
            self.fail("/n".join(reasons))

    @property
    def dash(self):
        if not getattr(self, '__dash', None):
            self.__dash = Dash()
        return self.__dash

    @property
    def hud(self):
        if not getattr(self, '__hud', None):
            self.__hud = Hud();
        return self.__hud

    @property
    def launcher(self):
        if not getattr(self, '__launcher', None):
            self.__launcher = self._get_launcher_controller()
        return self.__launcher

    @property
    def panels(self):
        if not getattr(self, '__panels', None):
            self.__panels = self._get_panel_controller()
        return self.__panels

    @property
    def switcher(self):
        if not getattr(self, '__switcher', None):
            self.__switcher = Switcher()
        return self.__switcher

    @property
    def window_manager(self):
        if not getattr(self, '__window_manager', None):
            self.__window_manager = self._get_window_manager()
        return self.__window_manager

    @property
    def workspace(self):
        if not getattr(self, '__workspace', None):
            self.__workspace = WorkspaceManager()
        return self.__workspace

    def _get_launcher_controller(self):
        controllers = LauncherController.get_all_instances()
        self.assertThat(len(controllers), Equals(1))
        return controllers[0]

    def _get_panel_controller(self):
        controllers = PanelController.get_all_instances()
        self.assertThat(len(controllers), Equals(1))
        return controllers[0]

    def _get_window_manager(self):
        managers = WindowManager.get_all_instances()
        self.assertThat(len(managers), Equals(1))
        return managers[0]

    def _setUpUnityLogging(self):
        self._unity_log_file_name = mktemp(prefix=self.shortDescription())
        start_log_to_file(self._unity_log_file_name)
        self.addCleanup(self._tearDownUnityLogging)

    def _tearDownUnityLogging(self):
        # If unity dies, our dbus interface has gone, and reset_logging will fail
        # but we still want our log, so we ignore any errors.
        try:
            reset_logging()
        except DBusException:
            pass
        with open(self._unity_log_file_name) as unity_log:
            self.addDetail('unity-log', text_content(unity_log.read()))
        os.remove(self._unity_log_file_name)
        self._unity_log_file_name = ""

    def set_unity_log_level(self, component, level):
        """Set the unity log level for 'component' to 'level'.

        Valid levels are: TRACE, DEBUG, INFO, WARNING and ERROR.

        Components are dotted unity component names. The empty string specifies
        the root logging component.
        """
        valid_levels = ('TRACE', 'DEBUG', 'INFO', 'WARN', 'WARNING', 'ERROR')
        if level not in valid_levels:
            raise ValueError("Log level '%s' must be one of: %r" % (level, valid_levels))
        set_log_severity(component, level)
