//
// Created by Giacomo Magistrato on 07/12/21.
//

#ifndef PROGETTO_OBSERVER_H
#define PROGETTO_OBSERVER_H


class Observer {
public:
    virtual bool update() = 0;
    virtual ~Observer() {}
};


#endif //PROGETTO_OBSERVER_H
