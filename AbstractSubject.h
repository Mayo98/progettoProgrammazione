//
// Created by Giacomo Magistrato on 07/12/21.
//

#ifndef PROGETTO_ABSTRACTSUBJECT_H
#define PROGETTO_ABSTRACTSUBJECT_H

#include <list>
#include "Observer.h"
#include <wx/wx.h>
class AbstractSubject {
protected:
    //definizione lista observer
    std::list<Observer*> observers;
public:
    virtual ~AbstractSubject() {}

    virtual void addO(Observer*o) = 0;
    virtual void remove(Observer *o) = 0;
    virtual bool notify() = 0;

};


#endif //PROGETTO_ABSTRACTSUBJECT_H
