//
// Created by Giacomo Magistrato on 24/11/21.
//

#include "MainFrame.h"
#include "Frame.h"
#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/sizer.h>
#include <wx/window.h>

enum {
    ID_HELLO = 1
};

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style)
            : wxFrame(NULL, wxID_ANY, title, pos, size, style) {
    wxBoxSizer *boxSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer);
    boxSizer->Add(0, 0, 1, wxALL, 5);

    wxFlexGridSizer* gridSizerSlow = new wxFlexGridSizer(0, 2, 0, 15);
    gridSizerSlow->SetFlexibleDirection( wxBOTH );
    gridSizerSlow->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    boxSizer->Add(gridSizerSlow);
}
void MainFrame::OnExit(wxCommandEvent& event) {
    Close( true );
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox( "Choose your download",
                  "About Loading Bar", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Loading bar");
}



