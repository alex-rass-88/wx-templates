#include <wx/wx.h>

class MyApp : public wxApp {
 public:
  virtual bool OnInit();

 private:
  wxFrame *m_frame;
};

bool MyApp::OnInit() {
  m_frame = new wxFrame(nullptr, wxID_ANY, L"wxDemo");
  m_frame->Show();

  return true;
}

wxDECLARE_APP(MyApp);
wxIMPLEMENT_APP(MyApp);
