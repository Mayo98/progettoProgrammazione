//
// Created by Giacomo Magistrato on 24/11/21.
//

#ifndef PROGETTO_MAINFRAME_H
#define PROGETTO_MAINFRAME_H

#include <wx/frame.h>
class MainFrame : public wxFrame{

public:
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);


        wxDECLARE_EVENT_TABLE();


};


#endif //PROGETTO_MAINFRAME_H
