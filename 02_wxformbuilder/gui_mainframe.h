#pragma once

#include "gui.h"

// Frame class
class MainFrame : public MainFrameBase {
 protected:
  // Frame events
  void m_action1ButtonOnButtonClick(wxCommandEvent& event);
  void m_action2ButtonOnButtonClick(wxCommandEvent& event);

 public:
  MainFrame(wxWindow* parent);
};
