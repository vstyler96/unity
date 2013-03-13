// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2011 Canonical Ltd
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
 * Authored by: Marco Trevisan (Treviño) <3v1n0@ubuntu.com>
 */

#include <list>
#include <algorithm>
#include <gmock/gmock.h>
#include <UnityCore/Variant.h>

using namespace std;
using namespace testing;
using namespace unity;
using namespace unity::glib;

namespace
{

bool IsVariant(Variant const& variant)
{
  return g_variant_get_type_string (variant) != NULL;
}

bool IsFloating(Variant const& variant)
{
  return g_variant_is_floating (variant);
}

bool IsSameVariant(Variant const& v1, Variant const& v2)
{
  GVariant *gv1 = v1;
  GVariant *gv2 = v2;

  return gv1 == gv2;
}

bool ValuesEqual(Variant const& v1, Variant const& v2)
{
  return g_variant_equal ((GVariant*)v1, (GVariant*)v2);
}

TEST(TestGLibVariant, Construct)
{
  Variant v (g_variant_new_string ("foo"));

  EXPECT_TRUE(IsVariant(v));
  EXPECT_FALSE(IsFloating(v));
}

TEST(TestGLibVariant, ConstructSteal)
{
  GVariant *gv = g_variant_new_string ("qoo");
  g_variant_ref_sink (gv);
  Variant v (gv, StealRef());

  EXPECT_TRUE(IsVariant(v));
  EXPECT_FALSE(IsFloating(v));
}

TEST(TestGLibVariant, Copy)
{
  Variant v1 (g_variant_new_string ("bar"));
  Variant v2 (v1);

  EXPECT_TRUE(IsVariant(v1));
  EXPECT_TRUE(IsVariant(v2));
  EXPECT_FALSE(IsFloating(v1));
  EXPECT_FALSE(IsFloating(v2));
  EXPECT_TRUE(IsSameVariant(v1, v2));
  EXPECT_TRUE(ValuesEqual(v1, v2));
}

TEST(TestGLibVariant, KeepsRef)
{
  GVariant *gv = g_variant_new_int32 (456);
  g_variant_ref_sink (gv);

  Variant v (gv);

  EXPECT_TRUE(IsVariant(v));
  EXPECT_FALSE(IsFloating(v));

  g_variant_unref (gv);

  EXPECT_TRUE(IsVariant(v));
  EXPECT_FALSE(IsFloating(v));
  EXPECT_EQ(v.GetInt(), 456);
}

TEST(TestGLibVariant, UseGVariantMethod)
{
  Variant v (g_variant_new_int32 (123));

  EXPECT_TRUE(IsVariant(v));
  EXPECT_FALSE(IsFloating(v));
  EXPECT_EQ(v.GetInt(), 123);

  EXPECT_TRUE(g_variant_is_of_type (v, G_VARIANT_TYPE ("i")));
}

TEST(TestGLibVariant, HintsMap)
{
  GVariantBuilder b;

  g_variant_builder_init (&b, G_VARIANT_TYPE ("a{sv}"));
  variant::BuilderWrapper bw (&b);
  bw.add ("string-key", "string-value");
  bw.add ("int-key", 123);
  bw.add ("bool-key", true);
  bw.add ("last", "foo");

  GVariant *dict_variant = g_variant_builder_end (&b);
  Variant dict (g_variant_new_tuple (&dict_variant, 1));

  EXPECT_TRUE(IsVariant(dict));
  EXPECT_FALSE(IsFloating(dict));

  HintsMap hints;
  EXPECT_TRUE(dict.ASVToHints (hints));

  EXPECT_EQ(hints["string-key"].GetString(), "string-value");
  EXPECT_EQ(hints["int-key"].GetInt(), 123);
  EXPECT_EQ(hints["bool-key"].GetBool(), true);
  EXPECT_EQ(hints["last"].GetString(), "foo");

  // throw away all references to the original variant
  dict = g_variant_new_string ("bar");
  EXPECT_TRUE(IsVariant(dict));
  EXPECT_FALSE(IsFloating(dict));
  EXPECT_EQ(dict.GetString(), "bar");

  // this has to still work
  EXPECT_EQ(hints["string-key"].GetString(), "string-value");
  EXPECT_EQ(hints["int-key"].GetInt(), 123);
  EXPECT_EQ(hints["bool-key"].GetBool(), true);
  EXPECT_EQ(hints["last"].GetString(), "foo");
}

TEST(TestGLibVariant, GetString)
{
  Variant v1(g_variant_new_string("Unity"));
  EXPECT_EQ(v1.GetString(), "Unity");

  Variant v2(g_variant_new("(s)", "Rocks"));
  EXPECT_EQ(v2.GetString(), "Rocks");

  Variant v3(g_variant_new("(si)", "!!!", G_MININT));
  EXPECT_EQ(v3.GetString(), "");
}

TEST(TestGLibVariant, GetInt)
{
  gint32 value = g_random_int_range(G_MININT, G_MAXINT);
  Variant v1(g_variant_new_int32(value));
  EXPECT_EQ(v1.GetInt(), value);

  value = g_random_int_range(G_MININT, G_MAXINT);
  Variant v2(g_variant_new("(i)", value));
  EXPECT_EQ(v2.GetInt(), value);

  Variant v3(g_variant_new("(is)", value, "fooostring"));
  EXPECT_EQ(v3.GetInt(), 0);
}

TEST(TestGLibVariant, GetUInt)
{
  guint32 value = g_random_int();
  Variant v1(g_variant_new_uint32(value));
  EXPECT_EQ(v1.GetUInt(), value);

  value = g_random_int();
  Variant v2(g_variant_new("(u)", value));
  EXPECT_EQ(v2.GetUInt(), value);

  Variant v3(g_variant_new("(ui)", value, G_MAXINT));
  EXPECT_EQ(v3.GetUInt(), 0);
}

TEST(TestGLibVariant, GetBool)
{
  gboolean value = (g_random_int() % 2) ? TRUE : FALSE;
  Variant v1(g_variant_new_boolean(value));
  EXPECT_EQ(v1.GetBool(), (value != FALSE));

  value = (g_random_int() % 2) ? TRUE : FALSE;
  Variant v2(g_variant_new("(b)", value));
  EXPECT_EQ(v2.GetBool(), (value != FALSE));

  Variant v3(g_variant_new("(bs)", value, "fooostring"));
  EXPECT_EQ(v3.GetBool(), false);
}




} // Namespace
