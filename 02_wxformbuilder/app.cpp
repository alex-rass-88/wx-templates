#include <wx/app.h>
#include "gui_mainframe.h"

// Application class
class myApp : public wxApp {
 public:
  bool OnInit() override;
};

// Implementations
bool myApp::OnInit() {
  auto frame = new MainFrame(nullptr);
  return frame->Show();
}

// main
wxIMPLEMENT_APP(myApp);
