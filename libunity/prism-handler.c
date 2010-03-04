/* prism-handler.c generated by valac, the Vala compiler
 * generated from prism-handler.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/*
 * Copyright (C) 2009 Canonical Ltd
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
 * Authored by Gordon Allott <gord.allott@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <launcher/launcher.h>


#define UNITY_WEBAPP_TYPE_PRISM (unity_webapp_prism_get_type ())
#define UNITY_WEBAPP_PRISM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrism))
#define UNITY_WEBAPP_PRISM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismClass))
#define UNITY_WEBAPP_IS_PRISM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_PRISM))
#define UNITY_WEBAPP_IS_PRISM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_PRISM))
#define UNITY_WEBAPP_PRISM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismClass))

typedef struct _UnityWebappPrism UnityWebappPrism;
typedef struct _UnityWebappPrismClass UnityWebappPrismClass;
typedef struct _UnityWebappPrismPrivate UnityWebappPrismPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))

struct _UnityWebappPrism {
	GObject parent_instance;
	UnityWebappPrismPrivate * priv;
	char* name;
	char* id;
};

struct _UnityWebappPrismClass {
	GObjectClass parent_class;
};

struct _UnityWebappPrismPrivate {
	char* _url;
	char* _icon;
	char* webapp_dir;
};


static gpointer unity_webapp_prism_parent_class = NULL;

GType unity_webapp_prism_get_type (void);
#define UNITY_WEBAPP_PRISM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismPrivate))
enum  {
	UNITY_WEBAPP_PRISM_DUMMY_PROPERTY,
	UNITY_WEBAPP_PRISM_URL,
	UNITY_WEBAPP_PRISM_ICON
};
#define UNITY_WEBAPP_PRISM_webapp_ini_template "[Parameters]\nid=%s@unity.app\nname=%s\nuri=%s\nstatus=yes\nlocation=no\nsidebar=no\nnavigation=no"
#define UNITY_WEBAPP_PRISM_webapp_desktop_template "[Desktop Entry]\nName=%s\nType=Application\nComment=Web Application\nExec=\"prism\" -webapp %s@unity.app\nCategories=GTK;Network;\nStartupWMClass=Prism\nStartupNotify=true\nIcon=%s\n"
UnityWebappPrism* unity_webapp_prism_new (const char* address, const char* icon);
UnityWebappPrism* unity_webapp_prism_construct (GType object_type, const char* address, const char* icon);
char* unity_webapp_prism_desktop_file_path (UnityWebappPrism* self);
const char* unity_webapp_prism_get_url (UnityWebappPrism* self);
static gboolean unity_webapp_prism_check_existance_of_app (UnityWebappPrism* self);
const char* unity_webapp_prism_get_icon (UnityWebappPrism* self);
static void unity_webapp_prism_build_webapp (UnityWebappPrism* self);
static char* unity_webapp_prism_get_fav_uid (UnityWebappPrism* self);
char* unity_webapp_urlify (const char* uri);
void unity_webapp_prism_add_to_favorites (UnityWebappPrism* self);
static void unity_webapp_prism_set_url (UnityWebappPrism* self, const char* value);
static void unity_webapp_prism_set_icon (UnityWebappPrism* self, const char* value);
static GObject * unity_webapp_prism_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_webapp_prism_finalize (GObject* obj);
static void unity_webapp_prism_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_webapp_prism_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 52 "prism-handler.vala"
UnityWebappPrism* unity_webapp_prism_construct (GType object_type, const char* address, const char* icon) {
#line 102 "prism-handler.c"
	UnityWebappPrism * self;
#line 52 "prism-handler.vala"
	g_return_val_if_fail (address != NULL, NULL);
#line 52 "prism-handler.vala"
	g_return_val_if_fail (icon != NULL, NULL);
#line 54 "prism-handler.vala"
	self = (UnityWebappPrism*) g_object_new (object_type, "url", address, "icon", icon, NULL);
#line 110 "prism-handler.c"
	return self;
}


#line 52 "prism-handler.vala"
UnityWebappPrism* unity_webapp_prism_new (const char* address, const char* icon) {
#line 52 "prism-handler.vala"
	return unity_webapp_prism_construct (UNITY_WEBAPP_TYPE_PRISM, address, icon);
#line 119 "prism-handler.c"
}


#line 81 "prism-handler.vala"
char* unity_webapp_prism_desktop_file_path (UnityWebappPrism* self) {
#line 125 "prism-handler.c"
	char* result;
	char* _tmp0_;
	char* _tmp1_;
#line 81 "prism-handler.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 131 "prism-handler.c"
	result = (_tmp1_ = g_strconcat (g_get_home_dir (), _tmp0_ = g_strdup_printf ("/.webapps/%s@unity.app", self->id), NULL), _g_free0 (_tmp0_), _tmp1_);
#line 83 "prism-handler.vala"
	return result;
#line 135 "prism-handler.c"
}


#line 87 "prism-handler.vala"
static gboolean unity_webapp_prism_check_existance_of_app (UnityWebappPrism* self) {
#line 141 "prism-handler.c"
	gboolean result;
	GFile* webapp_dir_file;
#line 87 "prism-handler.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 89 "prism-handler.vala"
	if (_vala_strcmp0 (self->priv->_url, "") == 0) {
#line 148 "prism-handler.c"
		result = TRUE;
#line 91 "prism-handler.vala"
		return result;
#line 152 "prism-handler.c"
	}
#line 94 "prism-handler.vala"
	webapp_dir_file = g_file_new_for_path (self->priv->webapp_dir);
#line 95 "prism-handler.vala"
	if (g_file_query_exists (webapp_dir_file, NULL)) {
#line 158 "prism-handler.c"
		result = TRUE;
		_g_object_unref0 (webapp_dir_file);
#line 97 "prism-handler.vala"
		return result;
#line 163 "prism-handler.c"
	}
	result = FALSE;
	_g_object_unref0 (webapp_dir_file);
#line 99 "prism-handler.vala"
	return result;
#line 169 "prism-handler.c"
}


#line 102 "prism-handler.vala"
static void unity_webapp_prism_build_webapp (UnityWebappPrism* self) {
#line 175 "prism-handler.c"
	GError * _inner_error_;
	char* webapp_ini;
	char* webapp_desktop;
	GFile* webapp_directory;
	char* _tmp0_;
	GFile* _tmp1_;
	GFile* inifile;
	char* _tmp3_;
	char* _tmp2_;
	GFile* _tmp4_;
	GFile* desktop_file;
#line 102 "prism-handler.vala"
	g_return_if_fail (self != NULL);
#line 189 "prism-handler.c"
	_inner_error_ = NULL;
#line 105 "prism-handler.vala"
	webapp_ini = g_strdup_printf (UNITY_WEBAPP_PRISM_webapp_ini_template, self->id, self->name, self->priv->_url);
#line 106 "prism-handler.vala"
	webapp_desktop = g_strdup_printf (UNITY_WEBAPP_PRISM_webapp_desktop_template, self->name, self->id, self->priv->_icon);
#line 108 "prism-handler.vala"
	webapp_directory = g_file_new_for_path (self->priv->webapp_dir);
#line 197 "prism-handler.c"
	{
#line 111 "prism-handler.vala"
		g_file_make_directory_with_parents (webapp_directory, NULL, &_inner_error_);
#line 201 "prism-handler.c"
		if (_inner_error_ != NULL) {
			goto __catch6_g_error;
		}
	}
	goto __finally6;
	__catch6_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 114 "prism-handler.vala"
			g_warning ("prism-handler.vala:114: %s", e->message);
#line 215 "prism-handler.c"
			_g_error_free0 (e);
			_g_free0 (webapp_ini);
			_g_free0 (webapp_desktop);
			_g_object_unref0 (webapp_directory);
#line 115 "prism-handler.vala"
			return;
#line 222 "prism-handler.c"
		}
	}
	__finally6:
	if (_inner_error_ != NULL) {
		_g_free0 (webapp_ini);
		_g_free0 (webapp_desktop);
		_g_object_unref0 (webapp_directory);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
#line 118 "prism-handler.vala"
	inifile = (_tmp1_ = g_file_new_for_path (_tmp0_ = g_strconcat (self->priv->webapp_dir, "/webapp.ini", NULL)), _g_free0 (_tmp0_), _tmp1_);
#line 236 "prism-handler.c"
	{
		GFileOutputStream* file_stream;
		GDataOutputStream* data_stream;
#line 121 "prism-handler.vala"
		file_stream = g_file_create (inifile, G_FILE_CREATE_NONE, NULL, &_inner_error_);
#line 242 "prism-handler.c"
		if (_inner_error_ != NULL) {
			goto __catch7_g_error;
		}
#line 122 "prism-handler.vala"
		data_stream = g_data_output_stream_new ((GOutputStream*) file_stream);
#line 123 "prism-handler.vala"
		g_data_output_stream_put_string (data_stream, webapp_ini, NULL, &_inner_error_);
#line 250 "prism-handler.c"
		if (_inner_error_ != NULL) {
			_g_object_unref0 (file_stream);
			_g_object_unref0 (data_stream);
			goto __catch7_g_error;
		}
		_g_object_unref0 (file_stream);
		_g_object_unref0 (data_stream);
	}
	goto __finally7;
	__catch7_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 127 "prism-handler.vala"
			g_warning ("prism-handler.vala:127: %s", e->message);
#line 268 "prism-handler.c"
			_g_error_free0 (e);
			_g_free0 (webapp_ini);
			_g_free0 (webapp_desktop);
			_g_object_unref0 (webapp_directory);
			_g_object_unref0 (inifile);
#line 128 "prism-handler.vala"
			return;
#line 276 "prism-handler.c"
		}
	}
	__finally7:
	if (_inner_error_ != NULL) {
		_g_free0 (webapp_ini);
		_g_free0 (webapp_desktop);
		_g_object_unref0 (webapp_directory);
		_g_object_unref0 (inifile);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
#line 131 "prism-handler.vala"
	desktop_file = (_tmp4_ = g_file_new_for_path (_tmp3_ = g_strconcat (self->priv->webapp_dir, _tmp2_ = g_strdup_printf ("/%s.desktop", self->name), NULL)), _g_free0 (_tmp3_), _g_free0 (_tmp2_), _tmp4_);
#line 291 "prism-handler.c"
	{
		GFileOutputStream* file_stream;
		GDataOutputStream* data_stream;
#line 135 "prism-handler.vala"
		file_stream = g_file_create (desktop_file, G_FILE_CREATE_NONE, NULL, &_inner_error_);
#line 297 "prism-handler.c"
		if (_inner_error_ != NULL) {
			goto __catch8_g_error;
		}
#line 136 "prism-handler.vala"
		data_stream = g_data_output_stream_new ((GOutputStream*) file_stream);
#line 137 "prism-handler.vala"
		g_data_output_stream_put_string (data_stream, webapp_desktop, NULL, &_inner_error_);
#line 305 "prism-handler.c"
		if (_inner_error_ != NULL) {
			_g_object_unref0 (file_stream);
			_g_object_unref0 (data_stream);
			goto __catch8_g_error;
		}
		_g_object_unref0 (file_stream);
		_g_object_unref0 (data_stream);
	}
	goto __finally8;
	__catch8_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 140 "prism-handler.vala"
			g_warning ("prism-handler.vala:140: could not write to %s/%s.desktop", self->priv->webapp_dir, self->name);
#line 323 "prism-handler.c"
			_g_error_free0 (e);
			_g_free0 (webapp_ini);
			_g_free0 (webapp_desktop);
			_g_object_unref0 (webapp_directory);
			_g_object_unref0 (inifile);
			_g_object_unref0 (desktop_file);
#line 141 "prism-handler.vala"
			return;
#line 332 "prism-handler.c"
		}
	}
	__finally8:
	if (_inner_error_ != NULL) {
		_g_free0 (webapp_ini);
		_g_free0 (webapp_desktop);
		_g_object_unref0 (webapp_directory);
		_g_object_unref0 (inifile);
		_g_object_unref0 (desktop_file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (webapp_ini);
	_g_free0 (webapp_desktop);
	_g_object_unref0 (webapp_directory);
	_g_object_unref0 (inifile);
	_g_object_unref0 (desktop_file);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 145 "prism-handler.vala"
void unity_webapp_prism_add_to_favorites (UnityWebappPrism* self) {
#line 361 "prism-handler.c"
	LauncherFavorites* favorites;
	char* uid;
	char* _tmp0_;
	char* _tmp1_;
	char* desktop_path;
	char* _tmp3_;
	char* _tmp2_;
	char* _tmp4_;
#line 145 "prism-handler.vala"
	g_return_if_fail (self != NULL);
#line 147 "prism-handler.vala"
	favorites = _g_object_ref0 (launcher_favorites_get_default ());
#line 148 "prism-handler.vala"
	uid = unity_webapp_prism_get_fav_uid (self);
#line 149 "prism-handler.vala"
	if (_vala_strcmp0 (uid, "") != 0) {
#line 152 "prism-handler.vala"
		g_warning ("prism-handler.vala:152: %s is already a favorite", self->name);
#line 380 "prism-handler.c"
		_g_object_unref0 (favorites);
		_g_free0 (uid);
#line 153 "prism-handler.vala"
		return;
#line 385 "prism-handler.c"
	}
#line 156 "prism-handler.vala"
	desktop_path = (_tmp1_ = g_strconcat (self->priv->webapp_dir, _tmp0_ = g_strdup_printf ("/%s.desktop", self->name), NULL), _g_free0 (_tmp0_), _tmp1_);
#line 157 "prism-handler.vala"
	uid = (_tmp3_ = g_strconcat ("webapp-", _tmp2_ = g_path_get_basename (desktop_path), NULL), _g_free0 (uid), _tmp3_);
#line 391 "prism-handler.c"
	_g_free0 (_tmp2_);
#line 158 "prism-handler.vala"
	uid = (_tmp4_ = unity_webapp_urlify (uid), _g_free0 (uid), _tmp4_);
#line 161 "prism-handler.vala"
	launcher_favorites_set_string (favorites, uid, "type", "application");
#line 162 "prism-handler.vala"
	launcher_favorites_set_string (favorites, uid, "desktop_file", desktop_path);
#line 163 "prism-handler.vala"
	launcher_favorites_set_bool (favorites, uid, "enable_shadow", TRUE);
#line 164 "prism-handler.vala"
	launcher_favorites_add_favorite (favorites, uid);
#line 403 "prism-handler.c"
	_g_object_unref0 (favorites);
	_g_free0 (uid);
	_g_free0 (desktop_path);
}


#line 171 "prism-handler.vala"
static char* unity_webapp_prism_get_fav_uid (UnityWebappPrism* self) {
#line 412 "prism-handler.c"
	char* result;
	char* myuid;
	char* _tmp0_;
	char* _tmp1_;
	char* my_desktop_path;
	LauncherFavorites* favorites;
	GSList* favorite_list;
#line 171 "prism-handler.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 173 "prism-handler.vala"
	myuid = g_strdup ("");
#line 174 "prism-handler.vala"
	my_desktop_path = (_tmp1_ = g_strconcat (self->priv->webapp_dir, _tmp0_ = g_strdup_printf ("/%s.desktop", self->name), NULL), _g_free0 (_tmp0_), _tmp1_);
#line 175 "prism-handler.vala"
	favorites = _g_object_ref0 (launcher_favorites_get_default ());
#line 176 "prism-handler.vala"
	favorite_list = launcher_favorites_get_favorites (favorites);
#line 430 "prism-handler.c"
	{
		GSList* uid_collection;
		GSList* uid_it;
#line 177 "prism-handler.vala"
		uid_collection = favorite_list;
#line 436 "prism-handler.c"
		for (uid_it = uid_collection; uid_it != NULL; uid_it = uid_it->next) {
			const char* uid;
#line 177 "prism-handler.vala"
			uid = (const char*) uid_it->data;
#line 441 "prism-handler.c"
			{
				char* type;
				char* desktop_file;
#line 180 "prism-handler.vala"
				type = g_strdup (launcher_favorites_get_string (favorites, uid, "type"));
#line 181 "prism-handler.vala"
				if (_vala_strcmp0 (type, "application") != 0) {
#line 449 "prism-handler.c"
					_g_free0 (type);
#line 182 "prism-handler.vala"
					continue;
#line 453 "prism-handler.c"
				}
#line 184 "prism-handler.vala"
				desktop_file = g_strdup (launcher_favorites_get_string (favorites, uid, "desktop_file"));
#line 185 "prism-handler.vala"
				if (_vala_strcmp0 (desktop_file, my_desktop_path) == 0) {
#line 459 "prism-handler.c"
					char* _tmp2_;
#line 187 "prism-handler.vala"
					myuid = (_tmp2_ = g_strdup (uid), _g_free0 (myuid), _tmp2_);
#line 463 "prism-handler.c"
				}
				_g_free0 (type);
				_g_free0 (desktop_file);
			}
		}
	}
	result = myuid;
	_g_free0 (my_desktop_path);
	_g_object_unref0 (favorites);
#line 190 "prism-handler.vala"
	return result;
#line 475 "prism-handler.c"
}


const char* unity_webapp_prism_get_url (UnityWebappPrism* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_url;
#line 46 "prism-handler.vala"
	return result;
#line 485 "prism-handler.c"
}


static void unity_webapp_prism_set_url (UnityWebappPrism* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_url = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_url), _tmp0_);
	g_object_notify ((GObject *) self, "url");
}


const char* unity_webapp_prism_get_icon (UnityWebappPrism* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon;
#line 47 "prism-handler.vala"
	return result;
#line 503 "prism-handler.c"
}


static void unity_webapp_prism_set_icon (UnityWebappPrism* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_icon = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_icon), _tmp0_);
	g_object_notify ((GObject *) self, "icon");
}


static GObject * unity_webapp_prism_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityWebappPrism * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (unity_webapp_prism_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_WEBAPP_PRISM (obj);
	_inner_error_ = NULL;
	{
		char** _tmp1_;
		gint split_url_size;
		gint split_url_length1;
		char** _tmp0_;
		char** split_url;
		char* _tmp2_;
		char* _tmp5_;
		char* _tmp7_;
		char* _tmp6_;
		gboolean exists;
		split_url = (_tmp1_ = _tmp0_ = g_strsplit (self->priv->_url, "://", 2), split_url_length1 = _vala_array_length (_tmp0_), split_url_size = split_url_length1, _tmp1_);
#line 61 "prism-handler.vala"
		self->name = (_tmp2_ = g_strdup (split_url[1]), _g_free0 (self->name), _tmp2_);
#line 538 "prism-handler.c"
		{
			GRegex* regex;
			char* _tmp3_;
			char* _tmp4_;
#line 64 "prism-handler.vala"
			regex = g_regex_new ("(/)", 0, 0, &_inner_error_);
#line 545 "prism-handler.c"
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch9_g_regex_error;
				}
				split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
			}
#line 65 "prism-handler.vala"
			_tmp3_ = g_regex_replace (regex, self->name, (gssize) (-1), 0, "-", 0, &_inner_error_);
#line 556 "prism-handler.c"
			if (_inner_error_ != NULL) {
				_g_regex_unref0 (regex);
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch9_g_regex_error;
				}
				_g_regex_unref0 (regex);
				split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
			}
#line 65 "prism-handler.vala"
			self->name = (_tmp4_ = _tmp3_, _g_free0 (self->name), _tmp4_);
#line 569 "prism-handler.c"
			_g_regex_unref0 (regex);
		}
		goto __finally9;
		__catch9_g_regex_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
#line 67 "prism-handler.vala"
				g_warning ("prism-handler.vala:67: %s", e->message);
#line 581 "prism-handler.c"
				_g_error_free0 (e);
			}
		}
		__finally9:
		if (_inner_error_ != NULL) {
			split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
#line 70 "prism-handler.vala"
		self->id = (_tmp5_ = g_strdup (self->name), _g_free0 (self->id), _tmp5_);
#line 71 "prism-handler.vala"
		self->priv->webapp_dir = (_tmp7_ = g_strconcat (g_get_home_dir (), _tmp6_ = g_strdup_printf ("/.webapps/%s@unity.app", self->id), NULL), _g_free0 (self->priv->webapp_dir), _tmp7_);
#line 595 "prism-handler.c"
		_g_free0 (_tmp6_);
#line 74 "prism-handler.vala"
		exists = unity_webapp_prism_check_existance_of_app (self);
#line 75 "prism-handler.vala"
		if (!exists) {
#line 77 "prism-handler.vala"
			unity_webapp_prism_build_webapp (self);
#line 603 "prism-handler.c"
		}
		split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
	}
	return obj;
}


static void unity_webapp_prism_class_init (UnityWebappPrismClass * klass) {
	unity_webapp_prism_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityWebappPrismPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_webapp_prism_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_webapp_prism_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_webapp_prism_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_webapp_prism_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_WEBAPP_PRISM_URL, g_param_spec_string ("url", "url", "url", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_WEBAPP_PRISM_ICON, g_param_spec_string ("icon", "icon", "icon", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_webapp_prism_instance_init (UnityWebappPrism * self) {
	self->priv = UNITY_WEBAPP_PRISM_GET_PRIVATE (self);
}


static void unity_webapp_prism_finalize (GObject* obj) {
	UnityWebappPrism * self;
	self = UNITY_WEBAPP_PRISM (obj);
	_g_free0 (self->priv->_url);
	_g_free0 (self->priv->_icon);
	_g_free0 (self->name);
	_g_free0 (self->id);
	_g_free0 (self->priv->webapp_dir);
	G_OBJECT_CLASS (unity_webapp_prism_parent_class)->finalize (obj);
}


GType unity_webapp_prism_get_type (void) {
	static GType unity_webapp_prism_type_id = 0;
	if (unity_webapp_prism_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityWebappPrismClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_webapp_prism_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityWebappPrism), 0, (GInstanceInitFunc) unity_webapp_prism_instance_init, NULL };
		unity_webapp_prism_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityWebappPrism", &g_define_type_info, 0);
	}
	return unity_webapp_prism_type_id;
}


static void unity_webapp_prism_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityWebappPrism * self;
	self = UNITY_WEBAPP_PRISM (object);
	switch (property_id) {
		case UNITY_WEBAPP_PRISM_URL:
		g_value_set_string (value, unity_webapp_prism_get_url (self));
		break;
		case UNITY_WEBAPP_PRISM_ICON:
		g_value_set_string (value, unity_webapp_prism_get_icon (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_webapp_prism_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityWebappPrism * self;
	self = UNITY_WEBAPP_PRISM (object);
	switch (property_id) {
		case UNITY_WEBAPP_PRISM_URL:
		unity_webapp_prism_set_url (self, g_value_get_string (value));
		break;
		case UNITY_WEBAPP_PRISM_ICON:
		unity_webapp_prism_set_icon (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
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




