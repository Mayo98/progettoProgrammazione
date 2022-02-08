//
// Created by Giacomo Magistrato on 30/09/21.
//

#include "Frame.h"
#include <wx/wx.h>
#include <wx/wxprec.h>
#include <iostream>
#include <wx/msgdlg.h>
#include <wx/filename.h>

Frame::Frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
        : wxDialog(parent, id, title, pos, size, style){
    boxSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer);
    isActive = true;
}

Frame::~Frame() {

}
void Frame::OnExit(wxCommandEvent &event) {
    Close(true);
}
void Frame::OnHello(wxCommandEvent &event) {
    Frame::CreateFolderList();
}
bool Frame::getIsActive() {
    return isActive;
}

wxBoxSizer *Frame::getBoxSizer() const {
    return boxSizer;
}

wxArrayString Frame::CreateFolderList() {

    wxArrayString elem;
    wxFileDialog* dialog =
            new wxFileDialog( this, _("Open file"), "", "","" ,
                              wxFD_MULTIPLE, wxDefaultPosition);

    if (dialog->ShowModal() == wxID_OK)
    {
        dialog->GetFilenames(elem);
    }
    dialog->Destroy();
return elem;
}



