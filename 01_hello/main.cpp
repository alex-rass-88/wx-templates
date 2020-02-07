#include <wx/aboutdlg.h>
#include <wx/wx.h>

// Application class
class myApp : public wxApp {
 public:
  bool OnInit() override;
};

// Frame class
class myFrame : public wxFrame {
 public:
  myFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

  void OnMenuHello(wxCommandEvent& event);
  void OnMenuExit(wxCommandEvent& event);
  void OnMenuAbout(wxCommandEvent& event);
};

enum { myID_HELLO = 1001 };

// Implementations
bool myApp::OnInit() {
  auto frame = new myFrame("Hello World", wxDefaultPosition, wxSize(450, 340));
  return frame->Show();
}

myFrame::myFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
  auto menuFile = new wxMenu;
  menuFile->Append(myID_HELLO, "&Hello...\tCtrl-H",
                   "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  auto menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);
  auto menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");

  menuFile->Bind(wxEVT_COMMAND_MENU_SELECTED, &myFrame::OnMenuHello, this,
                 myID_HELLO);
  menuFile->Bind(wxEVT_COMMAND_MENU_SELECTED, &myFrame::OnMenuExit, this,
                 wxID_EXIT);
  menuHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, &myFrame::OnMenuAbout, this,
                 wxID_ABOUT);

  SetMenuBar(menuBar);
  CreateStatusBar();
  SetStatusText("Welcome to wxWidgets!");
}

void myFrame::OnMenuExit(wxCommandEvent& event) { Close(); }

void myFrame::OnMenuAbout(wxCommandEvent& event) {
  wxAboutDialogInfo info;
  info.SetName("Hello World");
  info.SetVersion("0.0.1");
  info.SetDescription("This program does something great.");

  wxAboutBox(info);
}

void myFrame::OnMenuHello(wxCommandEvent& event) {
  wxMessageBox("Hello world from wxWidgets!", "Hello");
}

// main
wxIMPLEMENT_APP(myApp);
