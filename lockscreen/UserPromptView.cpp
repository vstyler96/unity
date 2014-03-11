// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
* Copyright (C) 2014 Canonical Ltd
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
* Authored by: Andrea Azzarone <andrea.azzarone@canonical.com>
*/

#include "UserPromptView.h"

#include <boost/algorithm/string/trim.hpp>
#include <Nux/VLayout.h>

#include "LockScreenSettings.h"
#include "unity-shared/CairoTexture.h"
#include "unity-shared/TextInput.h"
#include "unity-shared/StaticCairoText.h"
#include "unity-shared/RawPixel.h"

namespace unity
{
namespace lockscreen
{
namespace
{
const RawPixel PADDING = 10_em;
const RawPixel LAYOUT_MARGIN = 10_em;
const RawPixel MSG_LAYOUT_MARGIN = 15_em;
const RawPixel PROMPT_LAYOUT_MARGIN = 5_em;
const int PROMPT_FONT_SIZE = 13;

nux::AbstractPaintLayer* CrateBackgroundLayer(int width, int height)
{
  nux::CairoGraphics cg(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t* cr = cg.GetInternalContext();

  cairo_set_source_rgba(cr, 0.1, 0.1, 0.1, 0.4);

  cg.DrawRoundedRectangle(cr,
                          1.0,
                          0, 0,
                          Settings::GRID_SIZE * 0.3,
                          width, height);

  cairo_fill_preserve(cr);

  cairo_set_source_rgba (cr, 0.4, 0.4, 0.4, 0.4);
  cairo_set_line_width (cr, 1);
  cairo_stroke (cr);

  // Create the texture layer
  nux::TexCoordXForm texxform;

  nux::ROPConfig rop;
  rop.Blend = true;
  rop.SrcBlend = GL_ONE;
  rop.DstBlend = GL_ONE_MINUS_SRC_ALPHA;

  return (new nux::TextureLayer(texture_ptr_from_cairo_graphics(cg)->GetDeviceTexture(),
                                texxform,
                                nux::color::White,
                                true,
                                rop));
}

std::string SanitizeMessage(std::string const& message)
{
  std::string msg = boost::algorithm::trim_copy(message);

  if (msg.empty())
    return msg;

  if (msg[msg.size()-1] == ':')
    msg = msg.substr(0, msg.size()-1);

  if (msg == "Password")
    return _("Password");

  if (msg == "login")
    return _("Username");

  return msg;
}

}

UserPromptView::UserPromptView(session::Manager::Ptr const& session_manager)
  : nux::View(NUX_TRACKER_LOCATION)
  , session_manager_(session_manager)
{
  user_authenticator_.echo_on_requested.connect([this](std::string const& message, PromiseAuthCodePtr const& promise){
    AddPrompt(message, /* visible */ true, promise);
  });

  user_authenticator_.echo_off_requested.connect([this](std::string const& message, PromiseAuthCodePtr const& promise){
    AddPrompt(message, /* visible */ false, promise);
  });

  user_authenticator_.message_requested.connect([this](std::string const& message){
    AddMessage(message, nux::color::White);
  });

  user_authenticator_.error_requested.connect([this](std::string const& message){
    AddMessage(message, nux::color::Red);
  });

  user_authenticator_.clear_prompts.connect([this](){
    ResetLayout();
  });

  ResetLayout();

  user_authenticator_.AuthenticateStart(session_manager_->UserName(),
                                        sigc::mem_fun(this, &UserPromptView::AuthenticationCb));
}

void UserPromptView::ResetLayout()
{
  focus_queue_.clear();

  SetLayout(new nux::VLayout());

  GetLayout()->SetLeftAndRightPadding(PADDING);
  GetLayout()->SetTopAndBottomPadding(PADDING);
  static_cast<nux::VLayout*>(GetLayout())->SetVerticalInternalMargin(LAYOUT_MARGIN);

  auto const& real_name = session_manager_->RealName();
  auto const& name = (real_name.empty() ? session_manager_->UserName() : real_name);

  unity::StaticCairoText* username = new unity::StaticCairoText(name);
  username->SetFont("Ubuntu "+std::to_string(PROMPT_FONT_SIZE));
  GetLayout()->AddView(username);

  msg_layout_ = new nux::VLayout();
  msg_layout_->SetVerticalInternalMargin(MSG_LAYOUT_MARGIN);
  msg_layout_->SetReconfigureParentLayoutOnGeometryChange(true);
  GetLayout()->AddLayout(msg_layout_);

  prompt_layout_ = new nux::VLayout();
  prompt_layout_->SetVerticalInternalMargin(PROMPT_LAYOUT_MARGIN);
  prompt_layout_->SetReconfigureParentLayoutOnGeometryChange(true);
  GetLayout()->AddLayout(prompt_layout_);

  QueueRelayout();
  QueueDraw();
}

void UserPromptView::AuthenticationCb(bool authenticated)
{
  ResetLayout();

  if (authenticated)
  {
    session_manager_->unlock_requested.emit();
  }
  else
  {
    AddMessage(_("Invalid password, please try again"), nux::color::Red);

    user_authenticator_.AuthenticateStart(session_manager_->UserName(),
                                          sigc::mem_fun(this, &UserPromptView::AuthenticationCb));
  }
}

void UserPromptView::Draw(nux::GraphicsEngine& graphics_engine, bool /* force_draw */)
{
  nux::Geometry const& geo = GetGeometry();

  graphics_engine.PushClippingRectangle(geo);
  nux::GetPainter().PaintBackground(graphics_engine, geo);

  bg_layer_.reset(CrateBackgroundLayer(geo.width, geo.height));
  nux::GetPainter().PushDrawLayer(graphics_engine, geo, bg_layer_.get());

  nux::GetPainter().PopBackground();
  graphics_engine.PopClippingRectangle();
}

void UserPromptView::DrawContent(nux::GraphicsEngine& graphics_engine, bool force_draw)
{
  nux::Geometry const& geo = GetGeometry();
  graphics_engine.PushClippingRectangle(geo);

  if (!IsFullRedraw())
  {
    bg_layer_.reset(CrateBackgroundLayer(geo.width, geo.height));
    nux::GetPainter().PushLayer(graphics_engine, geo, bg_layer_.get());
  }

  if (GetLayout())
    GetLayout()->ProcessDraw(graphics_engine, force_draw);

  if (!IsFullRedraw())
    nux::GetPainter().PopBackground();

  graphics_engine.PopClippingRectangle();
}

nux::View* UserPromptView::focus_view()
{
  if (focus_queue_.empty())
    return nullptr;

  for (auto* view : focus_queue_)
    if (view->HasKeyboardFocus())
      return view;

  return focus_queue_.front();
}

void UserPromptView::AddPrompt(std::string const& message, bool visible, PromiseAuthCodePtr const& promise)
{
  auto* text_input = new unity::TextInput();
  auto* text_entry = text_input->text_entry();

  text_input->input_hint = SanitizeMessage(message);
  text_input->hint_font_size = PROMPT_FONT_SIZE;
  text_entry->SetPasswordMode(!visible);
  text_entry->SetPasswordChar("•");
  text_entry->SetToggleCursorVisibilityOnKeyFocus(true);

  text_input->SetMinimumHeight(Settings::GRID_SIZE);
  text_input->SetMaximumHeight(Settings::GRID_SIZE);
  prompt_layout_->AddView(text_input, 1);
  focus_queue_.push_back(text_entry);

  // Don't remove it, it helps with a11y.
  if (focus_queue_.size() == 1)
    nux::GetWindowCompositor().SetKeyFocusArea(text_entry);

  text_entry->activated.connect([this, text_input, promise](){
    if (focus_queue_.size() == 1)
    {
      text_input->SetSpinnerVisible(true);
      text_input->SetSpinnerState(STATE_SEARCHING);
    }

    focus_queue_.pop_front();
    auto* text_entry = text_input->text_entry();
    text_entry->SetInputEventSensitivity(false);
    QueueRelayout();
    QueueDraw();

    std::string const& password = text_entry->GetText();
    if (promise)
      promise->set_value(password);
  });

  GetLayout()->ComputeContentPosition(0, 0);
  ComputeContentSize();
  QueueRelayout();
  QueueDraw();
}

void UserPromptView::AddMessage(std::string const& message, nux::Color const& color)
{
  auto* view = new unity::StaticCairoText("");
  view->SetFont(Settings::Instance().font_name());
  view->SetTextColor(color);
  view->SetText(message);

  msg_layout_->AddView(view);

  GetLayout()->ComputeContentPosition(0, 0);
  ComputeContentSize();
  QueueRelayout();
  QueueDraw();
}

}
}