//
// Created by Giacomo Magistrato on 07/12/21.
//

#ifndef PROGETTO_LOADINGHANDLER_H
#define PROGETTO_LOADINGHANDLER_H

#include "AbstractSubject.h"
#include <wx/wx.h>
#include <wx/utils.h>

class LoadingHandler : public AbstractSubject {
//privati
private:
    int state, speed;
    std::list<Observer*> observers;
public:

    //constr and distr

    LoadingHandler() { this->state = 0; }

    virtual ~LoadingHandler() {};

    void upload(int initial,wxArrayString elem, int speedMs) ;

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

    //Subject

    void addO(Observer*o) override{
        observers.push_back(o);
    }
    void remove(Observer *o) override{ observers.remove(o); }

    virtual void notify() override{
        //scorro lista observers e invoco il loro update
        for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
            (*itr)->update();
        }
    }

    //chiamo notify per avvertire obs del cambio stato
    void setState(int stat) {
        this->state = stat;
        notify();
    }
    bool getObs(){
        if(observers.empty())
            return false;
        else
            return true;

    }
};

#endif //PROGETTO_LOADINGHANDLER_H
