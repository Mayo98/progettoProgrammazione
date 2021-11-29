//
// Created by Giacomo Magistrato on 30/09/21.
//

#include "Frame.h"
#include <wx/wx.h>
#include <wx/wxprec.h>
#include <iostream>


Frame::Frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
        : wxDialog(parent, id, title, pos, size, style){
    boxSizer = new wxBoxSizer(wxVERTICAL_HATCH);
    this->SetSizer(boxSizer);

    gauge = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxGA_TEXT);
    gauge->SetValue(0);

    boxSizer->Add(gauge, 3, wxALL|wxEXPAND, 15);
    staticText = new wxStaticText(this, wxID_ANY, _("0 %"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    boxSizer->Add(staticText, 1, wxALL|wxALIGN_CENTER_VERTICAL);

    isActive = true;
}

Frame::~Frame() {

}
void Frame::OnExit(wxCommandEvent &event) {
    Close(true);
}
bool Frame::getIsActive() {
    return isActive;
}

wxBoxSizer *Frame::getBoxSizer() const {
    return boxSizer;
}
