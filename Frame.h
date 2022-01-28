//
// Created by Giacomo Magistrato on 30/09/21.
//

#ifndef PROGETTO_FRAME_H
#define PROGETTO_FRAME_H
#include <wx/dialog.h>
#include <wx/dialog.h>
#include <wx/gauge.h>
#include <wx/stattext.h>
#include "Observer.h"
class Frame : public wxDialog {

protected:


    bool isActive;
    wxStaticText* staticText;
    wxBoxSizer* boxSizer;


public:

    wxBoxSizer* getBoxSizer() const;
    bool getIsActive();
    //constr

    Frame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Cerca..."),
          const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300),
          long style = wxDEFAULT_DIALOG_STYLE);


    void OnExit(wxCommandEvent& event);
    wxArrayString CreateFolderList();
    virtual ~Frame();
    //bool update() override;


};

#endif //PROGETTO_FRAME_H
