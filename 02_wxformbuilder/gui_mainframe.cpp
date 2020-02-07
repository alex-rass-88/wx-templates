#include "gui_mainframe.h"
#include <wx/msgdlg.h>

MainFrame::MainFrame(wxWindow* parent) : MainFrameBase(parent) {}

void MainFrame::m_action1ButtonOnButtonClick(wxCommandEvent& event) {
  wxMessageBox("Action 1 button pressed");
}

void MainFrame::m_action2ButtonOnButtonClick(wxCommandEvent& event) {
  wxMessageBox("Action 2 button pressed");
}
