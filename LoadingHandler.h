//
// Created by Giacomo Magistrato on 07/12/21.
//

#ifndef PROGETTO_LOADINGHANDLER_H
#define PROGETTO_LOADINGHANDLER_H

#include "AbstractSubject.h"

class LoadingHandler : public AbstractSubject {

public:

    int state, speed;
    //constr and distr

    LoadingHandler() { this->state = 0; }
    virtual ~LoadingHandler() { }

    virtual void upload(int initial, int speed);

    //get e set delle var
    int getState() const {
        return state;
    }

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int speed) {
        LoadingHandler::speed = speed;
    }

    //chiamo notify per avvertire obs del cambio stato
    bool setState(int state) {
        this->state = state;
        return notify();
    }

};


#endif //PROGETTO_LOADINGHANDLER_H
