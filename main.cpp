// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};
enum
{
    ID_Hello = 1
};
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
    int i, max = 433;

    wxFrame* frame1 = new wxFrame(NULL, wxID_ANY, wxT("blah blah"));
    this->SetTopWindow(frame);
    frame->Show(true);

    wxProgressDialog* dialog = new wxProgressDialog(wxT("Wait..."), wxT("Keep waiting..."), max, frame, wxPD_AUTO_HIDE | wxPD_APP_MODAL);
}

MyFrame::MyFrame()
        : wxFrame(NULL, wxID_ANY, "Carica File")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Progress Bar");
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
bool myApp :: OnInit(){
    int i, max = 433;

    wxFrame* frame = new wxFrame(NULL, wxID_ANY, wxT("blah blah"));
    this->SetTopWindow(frame);
    frame->Show(true);

    wxProgressDialog* dialog = new wxProgressDialog(wxT("Wait..."), wxT("Keep waiting..."), max, frame, wxPD_AUTO_HIDE | wxPD_APP_MODAL);

    for(int i = 0; i < max; i++){
        wxMilliSleep(5); //here are computations
        if(i%23) dialog->Update(i);
    }
    dialog->Update(max);
    delete dialog;

    return true;
}

int myApp :: OnExit(){

    return 0;
}