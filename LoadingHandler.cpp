//
// Created by Giacomo Magistrato on 07/12/21.
//

#include "LoadingHandler.h"
#include <wx/wx.h>

void LoadingHandler::upload(int initial, wxArrayString elem, int speedMs) {
    int N = elem.size();

    if (initial <= 100 and initial >= 0 and speedMs > 0) {
        setState(initial);
        setSpeed(speedMs);
        while (N > 0) {
            for (int i = 0; i < 100 / N - initial; i++) {
                if (!observers.empty()) {
                    state += 1;
                    setState(state);
                    wxMilliSleep(speedMs );
                } else {
                    break;
                }
            }
            N -= 1;
            wxMilliSleep(1000);
        }

    }

}