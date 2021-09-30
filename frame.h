//
// Created by Giacomo Magistrato on 30/09/21.
//

#ifndef PROGETTO_FRAME_H
#define PROGETTO_FRAME_H
#include <wx/dialog.h>
#include <wx/dialog.h>
#include <wx/gauge.h>
#include <wx/stattext.h>

class frame : public wxDialog{

protected:

    frame(wxWindow *parent, wxWindowID id, const wxString &titolo, const wxPoint &pos, const wxSize &size, int style);

    wxGauge* gauge;
    wxStaticText* staticText;
    wxBoxSizer* boxSizer;


public:
    wxGauge *GetGauge(){return gauge;}
    wxStaticText* GetStaticText(){return staticText;}
    wxBoxSizer* getBoxSizer() const;

    //constr
    frame(wxWindow * parent, wxWindowID id, const wxString& titolo ,
          const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300),
          long style = wxDEFAULT_DIALOG_STYLE);

    virtual ~frame();
};

#endif //PROGETTO_FRAME_H
