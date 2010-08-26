/* test-appinfo-manager.c generated by valac 0.9.7, the Vala compiler
 * generated from test-appinfo-manager.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
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
 * Authored by Mikkel Kamstrup Erlandsen <mikkel.kamstrup@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <unity.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <config.h>
#include <gee.h>
#include <gobject/gvaluecollector.h>


#define UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE (unity_tests_unit_app_info_manager_suite_get_type ())
#define UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE, UnityTestsUnitAppInfoManagerSuite))
#define UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE, UnityTestsUnitAppInfoManagerSuiteClass))
#define UNITY_TESTS_UNIT_IS_APP_INFO_MANAGER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE))
#define UNITY_TESTS_UNIT_IS_APP_INFO_MANAGER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE))
#define UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE, UnityTestsUnitAppInfoManagerSuiteClass))

typedef struct _UnityTestsUnitAppInfoManagerSuite UnityTestsUnitAppInfoManagerSuite;
typedef struct _UnityTestsUnitAppInfoManagerSuiteClass UnityTestsUnitAppInfoManagerSuiteClass;
typedef struct _UnityTestsUnitAppInfoManagerSuitePrivate UnityTestsUnitAppInfoManagerSuitePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData;
typedef struct _UnityTestsUnitParamSpecAppInfoManagerSuite UnityTestsUnitParamSpecAppInfoManagerSuite;

struct _UnityTestsUnitAppInfoManagerSuite {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UnityTestsUnitAppInfoManagerSuitePrivate * priv;
};

struct _UnityTestsUnitAppInfoManagerSuiteClass {
	GTypeClass parent_class;
	void (*finalize) (UnityTestsUnitAppInfoManagerSuite *self);
};

struct _UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	GMainLoop* mainloop;
	UnityAppInfoManager* manager;
	GAppInfo* appinfo;
	GError * e;
	GError * _inner_error_;
};

struct _UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	GMainLoop* mainloop;
	char* old_datadir;
	UnityAppInfoManager* manager;
	GAppInfo* info;
	GError * e;
	GeeList* categories;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	GError * _inner_error_;
};

struct _UnityTestsUnitParamSpecAppInfoManagerSuite {
	GParamSpec parent_instance;
};


static gpointer unity_tests_unit_app_info_manager_suite_parent_class = NULL;

gpointer unity_tests_unit_app_info_manager_suite_ref (gpointer instance);
void unity_tests_unit_app_info_manager_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_app_info_manager_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_app_info_manager_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_app_info_manager_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_app_info_manager_suite (const GValue* value);
GType unity_tests_unit_app_info_manager_suite_get_type (void) G_GNUC_CONST;
enum  {
	UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE_DUMMY_PROPERTY
};
UnityTestsUnitAppInfoManagerSuite* unity_tests_unit_app_info_manager_suite_new (void);
UnityTestsUnitAppInfoManagerSuite* unity_tests_unit_app_info_manager_suite_construct (GType object_type);
void unity_tests_unit_app_info_manager_suite_test_allocation (void);
static void _unity_tests_unit_app_info_manager_suite_test_allocation_gdata_test_func (gpointer self);
void unity_tests_unit_app_info_manager_suite_test_clear_empty (void);
static void _unity_tests_unit_app_info_manager_suite_test_clear_empty_gdata_test_func (gpointer self);
void unity_tests_unit_app_info_manager_suite_test_sync_lookup_missing (void);
static void _unity_tests_unit_app_info_manager_suite_test_sync_lookup_missing_gdata_test_func (gpointer self);
void unity_tests_unit_app_info_manager_suite_test_async_lookup_missing (void);
static void _unity_tests_unit_app_info_manager_suite_test_async_lookup_missing_gdata_test_func (gpointer self);
void unity_tests_unit_app_info_manager_suite_test_sync_lookup_ok (void);
static void _unity_tests_unit_app_info_manager_suite_test_sync_lookup_ok_gdata_test_func (gpointer self);
void unity_tests_unit_app_info_manager_suite_test_async_lookup_ok (void);
static void _unity_tests_unit_app_info_manager_suite_test_async_lookup_ok_gdata_test_func (gpointer self);
void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing (GMainLoop* mainloop, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_finish (GAsyncResult* _res_);
static void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_data_free (gpointer _data);
static void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_co (UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData* data);
void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok (GMainLoop* mainloop, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_finish (GAsyncResult* _res_);
static void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_data_free (gpointer _data);
static void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_co (UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData* data);
static void unity_tests_unit_app_info_manager_suite_finalize (UnityTestsUnitAppInfoManagerSuite* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void _unity_tests_unit_app_info_manager_suite_test_allocation_gdata_test_func (gpointer self) {
	unity_tests_unit_app_info_manager_suite_test_allocation ();
}


static void _unity_tests_unit_app_info_manager_suite_test_clear_empty_gdata_test_func (gpointer self) {
	unity_tests_unit_app_info_manager_suite_test_clear_empty ();
}


static void _unity_tests_unit_app_info_manager_suite_test_sync_lookup_missing_gdata_test_func (gpointer self) {
	unity_tests_unit_app_info_manager_suite_test_sync_lookup_missing ();
}


static void _unity_tests_unit_app_info_manager_suite_test_async_lookup_missing_gdata_test_func (gpointer self) {
	unity_tests_unit_app_info_manager_suite_test_async_lookup_missing ();
}


static void _unity_tests_unit_app_info_manager_suite_test_sync_lookup_ok_gdata_test_func (gpointer self) {
	unity_tests_unit_app_info_manager_suite_test_sync_lookup_ok ();
}


static void _unity_tests_unit_app_info_manager_suite_test_async_lookup_ok_gdata_test_func (gpointer self) {
	unity_tests_unit_app_info_manager_suite_test_async_lookup_ok ();
}


UnityTestsUnitAppInfoManagerSuite* unity_tests_unit_app_info_manager_suite_construct (GType object_type) {
	UnityTestsUnitAppInfoManagerSuite* self;
	self = (UnityTestsUnitAppInfoManagerSuite*) g_type_create_instance (object_type);
	g_test_add_data_func ("/Unit/AppInfoManager/Allocation", NULL, _unity_tests_unit_app_info_manager_suite_test_allocation_gdata_test_func);
	g_test_add_data_func ("/Unit/AppInfoManager/ClearEmpty", NULL, _unity_tests_unit_app_info_manager_suite_test_clear_empty_gdata_test_func);
	g_test_add_data_func ("/Unit/AppInfoManager/SyncLookupMissing", NULL, _unity_tests_unit_app_info_manager_suite_test_sync_lookup_missing_gdata_test_func);
	g_test_add_data_func ("/Unit/AppInfoManager/AsyncLookupMissing", NULL, _unity_tests_unit_app_info_manager_suite_test_async_lookup_missing_gdata_test_func);
	g_test_add_data_func ("/Unit/AppInfoManager/SyncLookupOk", NULL, _unity_tests_unit_app_info_manager_suite_test_sync_lookup_ok_gdata_test_func);
	g_test_add_data_func ("/Unit/AppInfoManager/AsyncLookupOk", NULL, _unity_tests_unit_app_info_manager_suite_test_async_lookup_ok_gdata_test_func);
	return self;
}


UnityTestsUnitAppInfoManagerSuite* unity_tests_unit_app_info_manager_suite_new (void) {
	return unity_tests_unit_app_info_manager_suite_construct (UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE);
}


void unity_tests_unit_app_info_manager_suite_test_allocation (void) {
	UnityAppInfoManager* manager;
	manager = unity_app_info_manager_get_instance ();
	g_assert (UNITY_IS_APP_INFO_MANAGER (manager));
	_g_object_unref0 (manager);
}


void unity_tests_unit_app_info_manager_suite_test_clear_empty (void) {
	UnityAppInfoManager* manager;
	manager = unity_app_info_manager_get_instance ();
	unity_app_info_manager_clear (manager);
	unity_app_info_manager_clear (manager);
	_g_object_unref0 (manager);
}


void unity_tests_unit_app_info_manager_suite_test_sync_lookup_missing (void) {
	UnityAppInfoManager* manager;
	GAppInfo* _tmp0_;
	manager = unity_app_info_manager_get_instance ();
	g_assert ((_tmp0_ = unity_app_info_manager_lookup (manager, "_foobar.desktop")) == NULL);
	_g_object_unref0 (_tmp0_);
	_g_object_unref0 (manager);
}


void unity_tests_unit_app_info_manager_suite_test_async_lookup_missing (void) {
	GMainLoop* mainloop;
	mainloop = g_main_loop_new (NULL, FALSE);
	unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing (mainloop, NULL, NULL);
	g_main_loop_run (mainloop);
	_g_main_loop_unref0 (mainloop);
}


static void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_data_free (gpointer _data) {
	UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData* data;
	data = _data;
	_g_main_loop_unref0 (data->mainloop);
	g_slice_free (UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData, data);
}


static gpointer _g_main_loop_ref0 (gpointer self) {
	return self ? g_main_loop_ref (self) : NULL;
}


void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing (GMainLoop* mainloop, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData* _data_;
	_data_ = g_slice_new0 (UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_data_free);
	_data_->mainloop = _g_main_loop_ref0 (mainloop);
	unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_co (_data_);
}


void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_finish (GAsyncResult* _res_) {
	UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_co (data);
}


static gboolean unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_co (UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupMissingData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 3:
		goto _state_3;
	}
	_state_0:
	data->manager = unity_app_info_manager_get_instance ();
	{
		data->_state_ = 3;
		unity_app_info_manager_lookup_async (data->manager, "_foobar.desktop", unity_tests_unit_app_info_manager_suite_do_test_async_lookup_missing_ready, data);
		return FALSE;
		_state_3:
		data->appinfo = unity_app_info_manager_lookup_finish (data->manager, data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			goto __catch5_g_error;
		}
		g_assert (data->appinfo == NULL);
		_g_object_unref0 (data->appinfo);
	}
	goto __finally5;
	__catch5_g_error:
	{
		data->e = data->_inner_error_;
		data->_inner_error_ = NULL;
		{
			g_error ("test-appinfo-manager.vala:82: Error reading desktop file: %s", data->e->message);
			_g_error_free0 (data->e);
		}
	}
	__finally5:
	if (data->_inner_error_ != NULL) {
		_g_object_unref0 (data->manager);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	g_main_loop_quit (data->mainloop);
	_g_object_unref0 (data->manager);
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


void unity_tests_unit_app_info_manager_suite_test_sync_lookup_ok (void) {
	char* old_datadir;
	UnityAppInfoManager* manager;
	GAppInfo* info;
	GeeList* categories;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	old_datadir = g_strdup (g_get_user_data_dir ());
	manager = unity_app_info_manager_get_instance ();
	g_setenv ("XDG_DATA_HOME", TESTUNITDIR "/data", TRUE);
	g_debug ("test-appinfo-manager.vala:95: XDG %s", TESTUNITDIR "/data");
	info = unity_app_info_manager_lookup (manager, "ubuntu-about.desktop");
	g_assert (info != NULL);
	g_assert (G_IS_APP_INFO (info));
	g_assert (_vala_strcmp0 ("About Ubuntu", g_app_info_get_name (info)) == 0);
	categories = unity_app_info_manager_get_categories (manager, "ubuntu-about.desktop");
	g_assert (categories != NULL);
	g_assert (_vala_strcmp0 (_tmp0_ = (char*) gee_list_get (categories, 0), "GNOME") == 0);
	_g_free0 (_tmp0_);
	g_assert (_vala_strcmp0 (_tmp1_ = (char*) gee_list_get (categories, 1), "Application") == 0);
	_g_free0 (_tmp1_);
	g_assert (_vala_strcmp0 (_tmp2_ = (char*) gee_list_get (categories, 2), "Core") == 0);
	_g_free0 (_tmp2_);
	g_setenv ("XDG_DATA_HOME", old_datadir, TRUE);
	_g_object_unref0 (categories);
	_g_object_unref0 (info);
	_g_object_unref0 (manager);
	_g_free0 (old_datadir);
}


void unity_tests_unit_app_info_manager_suite_test_async_lookup_ok (void) {
	GMainLoop* mainloop;
	mainloop = g_main_loop_new (NULL, FALSE);
	unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok (mainloop, NULL, NULL);
	g_main_loop_run (mainloop);
	_g_main_loop_unref0 (mainloop);
}


static void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_data_free (gpointer _data) {
	UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData* data;
	data = _data;
	_g_main_loop_unref0 (data->mainloop);
	g_slice_free (UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData, data);
}


void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok (GMainLoop* mainloop, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData* _data_;
	_data_ = g_slice_new0 (UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_data_free);
	_data_->mainloop = _g_main_loop_ref0 (mainloop);
	unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_co (_data_);
}


void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_finish (GAsyncResult* _res_) {
	UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_co (data);
}


static gboolean unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_co (UnityTestsUnitAppInfoManagerSuiteDoTestAsyncLookupOkData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 4:
		goto _state_4;
	}
	_state_0:
	data->old_datadir = g_strdup (g_get_user_data_dir ());
	data->manager = unity_app_info_manager_get_instance ();
	g_setenv ("XDG_DATA_HOME", TESTUNITDIR "/data", TRUE);
	{
		data->_state_ = 4;
		unity_app_info_manager_lookup_async (data->manager, "ubuntu-about.desktop", unity_tests_unit_app_info_manager_suite_do_test_async_lookup_ok_ready, data);
		return FALSE;
		_state_4:
		data->info = unity_app_info_manager_lookup_finish (data->manager, data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			goto __catch6_g_error;
		}
		g_assert (G_IS_APP_INFO (data->info));
		g_assert (_vala_strcmp0 ("About Ubuntu", g_app_info_get_name (data->info)) == 0);
		_g_object_unref0 (data->info);
	}
	goto __finally6;
	__catch6_g_error:
	{
		data->e = data->_inner_error_;
		data->_inner_error_ = NULL;
		{
			g_error ("test-appinfo-manager.vala:131: Error reading desktop file: %s", data->e->message);
			_g_error_free0 (data->e);
		}
	}
	__finally6:
	if (data->_inner_error_ != NULL) {
		_g_object_unref0 (data->manager);
		_g_free0 (data->old_datadir);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	data->categories = unity_app_info_manager_get_categories (data->manager, "ubuntu-about.desktop");
	g_assert (data->categories != NULL);
	g_assert (_vala_strcmp0 (data->_tmp0_ = (char*) gee_list_get (data->categories, 0), "GNOME") == 0);
	_g_free0 (data->_tmp0_);
	g_assert (_vala_strcmp0 (data->_tmp1_ = (char*) gee_list_get (data->categories, 1), "Application") == 0);
	_g_free0 (data->_tmp1_);
	g_assert (_vala_strcmp0 (data->_tmp2_ = (char*) gee_list_get (data->categories, 2), "Core") == 0);
	_g_free0 (data->_tmp2_);
	g_setenv ("XDG_DATA_HOME", data->old_datadir, TRUE);
	g_main_loop_quit (data->mainloop);
	_g_object_unref0 (data->categories);
	_g_object_unref0 (data->manager);
	_g_free0 (data->old_datadir);
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


static void unity_tests_unit_value_app_info_manager_suite_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void unity_tests_unit_value_app_info_manager_suite_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		unity_tests_unit_app_info_manager_suite_unref (value->data[0].v_pointer);
	}
}


static void unity_tests_unit_value_app_info_manager_suite_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = unity_tests_unit_app_info_manager_suite_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer unity_tests_unit_value_app_info_manager_suite_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* unity_tests_unit_value_app_info_manager_suite_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		UnityTestsUnitAppInfoManagerSuite* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = unity_tests_unit_app_info_manager_suite_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* unity_tests_unit_value_app_info_manager_suite_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	UnityTestsUnitAppInfoManagerSuite** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = unity_tests_unit_app_info_manager_suite_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* unity_tests_unit_param_spec_app_info_manager_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	UnityTestsUnitParamSpecAppInfoManagerSuite* spec;
	g_return_val_if_fail (g_type_is_a (object_type, UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer unity_tests_unit_value_get_app_info_manager_suite (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE), NULL);
	return value->data[0].v_pointer;
}


void unity_tests_unit_value_set_app_info_manager_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitAppInfoManagerSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		unity_tests_unit_app_info_manager_suite_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_app_info_manager_suite_unref (old);
	}
}


void unity_tests_unit_value_take_app_info_manager_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitAppInfoManagerSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_app_info_manager_suite_unref (old);
	}
}


static void unity_tests_unit_app_info_manager_suite_class_init (UnityTestsUnitAppInfoManagerSuiteClass * klass) {
	unity_tests_unit_app_info_manager_suite_parent_class = g_type_class_peek_parent (klass);
	UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE_CLASS (klass)->finalize = unity_tests_unit_app_info_manager_suite_finalize;
}


static void unity_tests_unit_app_info_manager_suite_instance_init (UnityTestsUnitAppInfoManagerSuite * self) {
	self->ref_count = 1;
}


static void unity_tests_unit_app_info_manager_suite_finalize (UnityTestsUnitAppInfoManagerSuite* obj) {
	UnityTestsUnitAppInfoManagerSuite * self;
	self = UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE (obj);
}


GType unity_tests_unit_app_info_manager_suite_get_type (void) {
	static volatile gsize unity_tests_unit_app_info_manager_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_app_info_manager_suite_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { unity_tests_unit_value_app_info_manager_suite_init, unity_tests_unit_value_app_info_manager_suite_free_value, unity_tests_unit_value_app_info_manager_suite_copy_value, unity_tests_unit_value_app_info_manager_suite_peek_pointer, "p", unity_tests_unit_value_app_info_manager_suite_collect_value, "p", unity_tests_unit_value_app_info_manager_suite_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitAppInfoManagerSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_app_info_manager_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitAppInfoManagerSuite), 0, (GInstanceInitFunc) unity_tests_unit_app_info_manager_suite_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType unity_tests_unit_app_info_manager_suite_type_id;
		unity_tests_unit_app_info_manager_suite_type_id = g_type_register_fundamental (g_type_fundamental_next (), "UnityTestsUnitAppInfoManagerSuite", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&unity_tests_unit_app_info_manager_suite_type_id__volatile, unity_tests_unit_app_info_manager_suite_type_id);
	}
	return unity_tests_unit_app_info_manager_suite_type_id__volatile;
}


gpointer unity_tests_unit_app_info_manager_suite_ref (gpointer instance) {
	UnityTestsUnitAppInfoManagerSuite* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void unity_tests_unit_app_info_manager_suite_unref (gpointer instance) {
	UnityTestsUnitAppInfoManagerSuite* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
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




