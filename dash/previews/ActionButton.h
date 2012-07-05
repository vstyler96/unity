// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright 2011 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3, as
 * published by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the applicable version of the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of both the GNU Lesser General Public
 * License version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Gordon Allott <gord.allott@canonical.com>
 *
 */

#ifndef ACTIONBUTTON_H
#define ACTIONBUTTON_H

#include <Nux/Nux.h>
#include <Nux/CairoWrapper.h>
#include <Nux/Button.h>

namespace unity
{
namespace dash
{

class ActionButton : public nux::Button
{
public:
  ActionButton(std::string const& label, NUX_FILE_LINE_PROTO);
  ~ActionButton();

protected:
  virtual long ComputeContentSize();
  virtual void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);

  void Init();
  void InitTheme();
  void RedrawTheme(nux::Geometry const& geom, cairo_t* cr, nux::ButtonVisualState faked_state);
  void RedrawFocusOverlay(nux::Geometry const& geom, cairo_t* cr);

  typedef std::unique_ptr<nux::CairoWrapper> NuxCairoPtr;

  NuxCairoPtr prelight_;
  NuxCairoPtr active_;
  NuxCairoPtr normal_;
  NuxCairoPtr focus_;

  nux::Geometry cached_geometry_;

private:
  std::string label_;
};

} // namespace dash
} // namespace unity

#endif // ACTIONBUTTON_H
