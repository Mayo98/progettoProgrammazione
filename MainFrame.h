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
    LoadingHandler* loadingHandler;
    wxListBox* listBox;
    bool isActive = true;
    bool added = false;

public:
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void setLoadingHandler(LoadingHandler *loadingHandler);
        LoadingHandler *getLoadingHandler() const;
        virtual ~MainFrame() override;

        wxGauge *GetGauge(){return gauge;}

        wxButton* button1;

        //wxStaticText* GetStaticText(){return staticText;}

        void ButtonSearchClicked(wxCommandEvent &event);
        bool getIsActive();
        bool getIsAdded(){return this->added;}
        bool update() override;
wxDECLARE_EVENT_TABLE();
};


#endif //PROGETTO_MAINFRAME_H
