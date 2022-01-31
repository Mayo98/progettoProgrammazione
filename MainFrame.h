//
// Created by Giacomo Magistrato on 24/11/21.
//

#ifndef PROGETTO_MAINFRAME_H
#define PROGETTO_MAINFRAME_H

#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include "Observer.h"
#include "LoadingHandler.h"
class MainFrame : public wxFrame, public Observer{
protected:
    wxGauge* gauge;
    wxStaticText* staticText;
    bool isActive;

public:
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

        LoadingHandler* loadingHandler;
        wxButton* button1;
        wxGauge *GetGauge(){return gauge;}
        wxStaticText* GetStaticText(){return staticText;}
        wxDECLARE_EVENT_TABLE();
        void ButtonSearchClicked(wxCommandEvent &event);
        bool getIsActive();
        LoadingHandler *getLoadingHandler() const;
        void setLoadingHandler(LoadingHandler *loadingHandler);

        bool update() override;
        virtual ~MainFrame();
};


#endif //PROGETTO_MAINFRAME_H
