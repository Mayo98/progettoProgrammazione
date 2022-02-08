//
// Created by Giacomo Magistrato on 24/11/21.
//
#include "wx/init.h"
#include "MainFrame.h"
#include "Frame.h"
#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/window.h>
#include <wx/dir.h>
#include <iostream>
#include "LoadingHandler.h"

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

    //Button Cerca
    button1 = new wxButton(this, wxID_ANY, _("Cerca File"), wxPoint(50,50), wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    button1->Bind(wxEVT_BUTTON, &MainFrame::ButtonSearchClicked, this);
    boxSizer->Add(gridSizerSlow);
    boxSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer);

    //Barra caricamento
    gauge = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition , wxDLG_UNIT(this, wxSize(-1,-1)), wxGA_TEXT);
    gauge->SetValue(0);
    boxSizer->Add(gauge, 3, wxALL|wxEXPAND, 15);
    staticText = new wxStaticText(this, wxID_ANY, _("0 %"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    boxSizer->Add(staticText, 1, wxALL|wxALIGN_CENTER);

}
void MainFrame::OnExit(wxCommandEvent& event) {
    //loadingHandler->remove(this);
    Close( true );
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox( "Choose your upload",
                  "About Loading Bar", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Loading bar");
}

void MainFrame::ButtonSearchClicked(wxCommandEvent &event) {
    Frame *frame = new Frame(this);
    wxArrayString elem = frame->CreateFolderList();
    int speed = elem.Count() * 10;
    LoadingHandler*loadingHandler1 = new LoadingHandler();
    loadingHandler1->addO(this);
    this->setLoadingHandler(loadingHandler1);
    loadingHandler->upload(0,elem, speed);

}

MainFrame::~MainFrame() {
    loadingHandler->remove(this);
}
LoadingHandler *MainFrame::getLoadingHandler() const{
    return MainFrame::loadingHandler;
}
void MainFrame::setLoadingHandler(LoadingHandler *loadingHandler1) {
    MainFrame::loadingHandler = loadingHandler1;
}
bool MainFrame::getIsActive() {
    return MainFrame::isActive;
}
bool MainFrame::update() {

    if (loadingHandler != nullptr) {

        int state = loadingHandler->getState();
        if (state < 0) {
            state = 0;
        }
        //wxMessageBox("ci sono");
        //wxString msg = wxString::Format(wxT("my value is %d"), state);
        //wxMessageBox(msg, wxT("a message"), wxOK | wxCENTRE , this);
        if (state > 100) {
            state = 100;
        }

        gauge->SetValue(state);

        //this->Refresh();
        //this->Update();

        std::string s = std::to_string(state);
        staticText->SetLabel(s + " %");

        if (state == gauge->GetRange()){

            button1->SetLabel("Finish");
        }
        wxYield();

        return isActive;
    }
    else
        return false;
}



