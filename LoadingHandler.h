//
// Created by Giacomo Magistrato on 07/12/21.
//

#ifndef PROGETTO_LOADINGHANDLER_H
#define PROGETTO_LOADINGHANDLER_H

#include "AbstractSubject.h"
#include <wx/wx.h>
#include <wx/utils.h>

class LoadingHandler : public AbstractSubject {

public:
    int state, speed;
    //constr and distr

    LoadingHandler() { this->state = 0; }

    virtual ~LoadingHandler() {};

    virtual void upload(int initial,wxArrayString elem, int speedMs);

    //get e set delle var
    int getState() const {
        return LoadingHandler::state;
    }

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int speedMs) {
        LoadingHandler::speed = speedMs;
    }

    //chiamo notify per avvertire obs del cambio stato
    bool setState(int stat) {
        this->state = stat;
        return notify();
    }
    bool getObs(){
        if(observers.empty())
            return false;
        else
            return true;

    }

};

#endif //PROGETTO_LOADINGHANDLER_H
