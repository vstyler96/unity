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
 * Authored by: Tim Penhey <tim.penhey@canonical.com>
 */

#ifndef UNITY_VARIANT_H
#define UNITY_VARIANT_H

#include <string>
#include <glib.h>

#include <NuxCore/Rect.h>

namespace unity
{
namespace variant
{

class BuilderWrapper
{
public:
  BuilderWrapper(GVariantBuilder* builder);

  BuilderWrapper& add(char const* name, bool value);
  BuilderWrapper& add(char const* name, char const* value);
  BuilderWrapper& add(char const* name, std::string const& value);
  BuilderWrapper& add(char const* name, int value);
  BuilderWrapper& add(char const* name, float value);
  BuilderWrapper& add(nux::Rect const& value);

private:
  GVariantBuilder* builder_;
};

}
}

#endif
