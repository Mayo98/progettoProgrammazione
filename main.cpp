
#ifndef WX_PRECOMP
#include <wx/wx.h>

#include "Frame.h"
#include "MainFrame.h"

#endif
class MyApp : public wxApp
{
public:
    virtual bool OnInit() override;
    virtual int OnExit(void) override;
};
enum
{
    ID_HELLO = 1
};
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
                EVT_MENU(ID_HELLO,   MainFrame::OnHello)
                EVT_MENU(wxID_EXIT,  MainFrame::OnExit)
                EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MainFrame* mainframe = new MainFrame("Menu", wxPoint(110, 110), wxSize(500,400));
    mainframe->Show(true);

    return true;
}
int MyApp::OnExit(void) {
    close(true);
    return 0;
}
/*
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
 */

