//
// Created by Giacomo Magistrato on 07/12/21.
//

#ifndef PROGETTO_ABSTRACTSUBJECT_H
#define PROGETTO_ABSTRACTSUBJECT_H

#include <list>
#include "Observer.h"

class AbstractSubject {
protected:
    std::list<Observer*> observers;
public:
    virtual ~AbstractSubject() {}
    void addO(Observer*o){observers.push_back(o);}
    virtual void remove(Observer *o) { observers.remove(o); }
    bool notify();

};


#endif //PROGETTO_ABSTRACTSUBJECT_H
