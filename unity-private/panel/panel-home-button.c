/* panel-home-button.c generated by valac, the Vala compiler
 * generated from panel-home-button.vala, do not modify */

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
 * Authored by Mirco Müller <mirco.mueller@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <unity.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <clutter/clutter.h>


#define UNITY_PANEL_TYPE_HOME_BUTTON (unity_panel_home_button_get_type ())
#define UNITY_PANEL_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButton))
#define UNITY_PANEL_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonClass))
#define UNITY_PANEL_IS_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_HOME_BUTTON))
#define UNITY_PANEL_IS_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_HOME_BUTTON))
#define UNITY_PANEL_HOME_BUTTON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonClass))

typedef struct _UnityPanelHomeButton UnityPanelHomeButton;
typedef struct _UnityPanelHomeButtonClass UnityPanelHomeButtonClass;
typedef struct _UnityPanelHomeButtonPrivate UnityPanelHomeButtonPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_TESTING_TYPE_OBJECT_REGISTRY (unity_testing_object_registry_get_type ())
#define UNITY_TESTING_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistry))
#define UNITY_TESTING_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))
#define UNITY_TESTING_IS_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_IS_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_OBJECT_REGISTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))

typedef struct _UnityTestingObjectRegistry UnityTestingObjectRegistry;
typedef struct _UnityTestingObjectRegistryClass UnityTestingObjectRegistryClass;
#define _unity_testing_object_registry_unref0(var) ((var == NULL) ? NULL : (var = (unity_testing_object_registry_unref (var), NULL)))

struct _UnityPanelHomeButton {
	CtkButton parent_instance;
	UnityPanelHomeButtonPrivate * priv;
	UnityThemeImage* theme_image;
};

struct _UnityPanelHomeButtonClass {
	CtkButtonClass parent_class;
};

struct _UnityPanelHomeButtonPrivate {
	UnityShell* _shell;
};


static gpointer unity_panel_home_button_parent_class = NULL;

GType unity_panel_home_button_get_type (void);
#define UNITY_PANEL_HOME_BUTTON_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonPrivate))
enum  {
	UNITY_PANEL_HOME_BUTTON_DUMMY_PROPERTY,
	UNITY_PANEL_HOME_BUTTON_SHELL
};
gpointer unity_testing_object_registry_ref (gpointer instance);
void unity_testing_object_registry_unref (gpointer instance);
GParamSpec* unity_testing_param_spec_object_registry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_testing_value_set_object_registry (GValue* value, gpointer v_object);
void unity_testing_value_take_object_registry (GValue* value, gpointer v_object);
gpointer unity_testing_value_get_object_registry (const GValue* value);
GType unity_testing_object_registry_get_type (void);
UnityTestingObjectRegistry* unity_testing_object_registry_get_default (void);
void unity_testing_object_registry_register (UnityTestingObjectRegistry* self, const char* name, GObject* object);
UnityPanelHomeButton* unity_panel_home_button_new (UnityShell* shell);
UnityPanelHomeButton* unity_panel_home_button_construct (GType object_type, UnityShell* shell);
UnityShell* unity_panel_home_button_get_shell (UnityPanelHomeButton* self);
static void unity_panel_home_button_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static void unity_panel_home_button_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width, float* nat_width);
static gboolean unity_panel_home_button_on_button_press (UnityPanelHomeButton* self, ClutterEvent* event);
static gboolean unity_panel_home_button_on_button_release (UnityPanelHomeButton* self, ClutterEvent* event);
static void unity_panel_home_button_set_shell (UnityPanelHomeButton* self, UnityShell* value);
static gboolean _unity_panel_home_button_on_button_press_clutter_actor_button_press_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean _unity_panel_home_button_on_button_release_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static GObject * unity_panel_home_button_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_panel_home_button_finalize (GObject* obj);
static void unity_panel_home_button_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_panel_home_button_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPanelHomeButton* unity_panel_home_button_construct (GType object_type, UnityShell* shell) {
	UnityPanelHomeButton * self;
	UnityTestingObjectRegistry* _tmp0_;
	g_return_val_if_fail (shell != NULL, NULL);
	self = (UnityPanelHomeButton*) g_object_new (object_type, "reactive", TRUE, "shell", shell, NULL);
	unity_testing_object_registry_register (_tmp0_ = unity_testing_object_registry_get_default (), "PanelHomeButton", (GObject*) self);
	_unity_testing_object_registry_unref0 (_tmp0_);
	return self;
}


UnityPanelHomeButton* unity_panel_home_button_new (UnityShell* shell) {
	return unity_panel_home_button_construct (UNITY_PANEL_TYPE_HOME_BUTTON, shell);
}


static void unity_panel_home_button_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityPanelHomeButton * self;
	float cwidth = 0.0F;
	float cheight = 0.0F;
	float lwidth = 0.0F;
	float pheight = 0.0F;
	CtkPadding _tmp0_ = {0};
	CtkPadding pad;
	self = (UnityPanelHomeButton*) base;
	pad = (_tmp0_.top = (float) 0, _tmp0_);
	lwidth = (float) unity_shell_get_launcher_width_foobar (self->priv->_shell);
	pheight = (float) unity_shell_get_panel_height_foobar (self->priv->_shell);
	clutter_actor_get_preferred_size ((ClutterActor*) self->theme_image, &cwidth, &cheight, &cwidth, &cheight);
	if ((lwidth - cwidth) <= 0.0f) {
		pad.left = 0.0f;
		pad.right = pad.left;
	} else {
		pad.left = (((*box).x2 - (*box).x1) - cwidth) / 2.0f;
		pad.right = pad.left;
	}
	if ((pheight - cheight) <= 0.0f) {
		pad.top = 0.0f;
		pad.bottom = pad.top;
	} else {
		pad.top = (((*box).y2 - (*box).y1) - cheight) / 2.0f;
		pad.bottom = pad.top;
	}
	ctk_actor_set_padding ((CtkActor*) self, &pad);
	CLUTTER_ACTOR_CLASS (unity_panel_home_button_parent_class)->allocate ((ClutterActor*) CTK_BUTTON (self), box, flags);
}


static void unity_panel_home_button_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width, float* nat_width) {
	UnityPanelHomeButton * self;
	self = (UnityPanelHomeButton*) base;
	*min_width = (float) unity_shell_get_launcher_width_foobar (self->priv->_shell);
	*nat_width = (float) unity_shell_get_launcher_width_foobar (self->priv->_shell);
}


static gboolean unity_panel_home_button_on_button_press (UnityPanelHomeButton* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	result = TRUE;
	return result;
}


static gboolean unity_panel_home_button_on_button_release (UnityPanelHomeButton* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	unity_shell_show_unity (self->priv->_shell);
	result = TRUE;
	return result;
}


UnityShell* unity_panel_home_button_get_shell (UnityPanelHomeButton* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_panel_home_button_set_shell (UnityPanelHomeButton* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


static gboolean _unity_panel_home_button_on_button_press_clutter_actor_button_press_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	return unity_panel_home_button_on_button_press (self, event);
}


static gboolean _unity_panel_home_button_on_button_release_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	return unity_panel_home_button_on_button_release (self, event);
}


static GObject * unity_panel_home_button_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPanelHomeButton * self;
	parent_class = G_OBJECT_CLASS (unity_panel_home_button_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PANEL_HOME_BUTTON (obj);
	{
		UnityThemeImage* _tmp0_;
		self->theme_image = (_tmp0_ = g_object_ref_sink (unity_theme_image_new ("distributor-logo")), _g_object_unref0 (self->theme_image), _tmp0_);
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->theme_image);
		clutter_actor_show ((ClutterActor*) self->theme_image);
		g_signal_connect_object ((ClutterActor*) self, "button-press-event", (GCallback) _unity_panel_home_button_on_button_press_clutter_actor_button_press_event, self, 0);
		g_signal_connect_object ((ClutterActor*) self, "button-release-event", (GCallback) _unity_panel_home_button_on_button_release_clutter_actor_button_release_event, self, 0);
	}
	return obj;
}


static void unity_panel_home_button_class_init (UnityPanelHomeButtonClass * klass) {
	unity_panel_home_button_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPanelHomeButtonPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_panel_home_button_real_allocate;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_width = unity_panel_home_button_real_get_preferred_width;
	G_OBJECT_CLASS (klass)->get_property = unity_panel_home_button_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_panel_home_button_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_panel_home_button_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_panel_home_button_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PANEL_HOME_BUTTON_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_panel_home_button_instance_init (UnityPanelHomeButton * self) {
	self->priv = UNITY_PANEL_HOME_BUTTON_GET_PRIVATE (self);
}


static void unity_panel_home_button_finalize (GObject* obj) {
	UnityPanelHomeButton * self;
	self = UNITY_PANEL_HOME_BUTTON (obj);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->theme_image);
	G_OBJECT_CLASS (unity_panel_home_button_parent_class)->finalize (obj);
}


GType unity_panel_home_button_get_type (void) {
	static volatile gsize unity_panel_home_button_type_id__volatile = 0;
	if (g_once_init_enter (&unity_panel_home_button_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPanelHomeButtonClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_panel_home_button_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPanelHomeButton), 0, (GInstanceInitFunc) unity_panel_home_button_instance_init, NULL };
		GType unity_panel_home_button_type_id;
		unity_panel_home_button_type_id = g_type_register_static (CTK_TYPE_BUTTON, "UnityPanelHomeButton", &g_define_type_info, 0);
		g_once_init_leave (&unity_panel_home_button_type_id__volatile, unity_panel_home_button_type_id);
	}
	return unity_panel_home_button_type_id__volatile;
}


static void unity_panel_home_button_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPanelHomeButton * self;
	self = UNITY_PANEL_HOME_BUTTON (object);
	switch (property_id) {
		case UNITY_PANEL_HOME_BUTTON_SHELL:
		g_value_set_object (value, unity_panel_home_button_get_shell (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_panel_home_button_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPanelHomeButton * self;
	self = UNITY_PANEL_HOME_BUTTON (object);
	switch (property_id) {
		case UNITY_PANEL_HOME_BUTTON_SHELL:
		unity_panel_home_button_set_shell (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




