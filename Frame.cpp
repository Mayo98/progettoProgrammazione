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

wxArrayString Frame::CreateFolderList() {

    wxArrayString *elem;
    wxFileDialog* dialog = new wxFileDialog(this);

    if (dialog->ShowModal() == wxID_OK)
    {
        /*
        dialog->GetFilenames(*elem);
        wxLogMessage(dialog->GetSize())
        int count = elem->Count();
         */
        dialog->GetFilenames(*elem);
        int count = elem->Count();

        /*
         for(size_t i=0; i < dialog->GetSize(); ++i)
         {
         wxString str = elem->Item(i);
         cout<<"str["<<i<<"] = "<<str.c_str().AsChar()<<endl;
         }
         */
    }
    dialog->Destroy();
return *elem;
}



