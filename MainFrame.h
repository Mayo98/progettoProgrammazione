//
// Created by Giacomo Magistrato on 24/11/21.
//

#ifndef PROGETTO_MAINFRAME_H
#define PROGETTO_MAINFRAME_H

#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
class MainFrame : public wxFrame{
protected:
    wxGauge* gauge;
    wxStaticText* staticText;

public:
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

        wxButton* button1;
        wxGauge *GetGauge(){return gauge;}
        wxStaticText* GetStaticText(){return staticText;}
        wxDECLARE_EVENT_TABLE();
        void ButtonSearchClicked(wxCommandEvent &event);

};


#endif //PROGETTO_MAINFRAME_H
