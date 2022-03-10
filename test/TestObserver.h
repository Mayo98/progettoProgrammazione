//
// Created by Giacomo Magistrato on 07/03/22.
//

#ifndef PROGETTO_TESTOBSERVER_H
#define PROGETTO_TESTOBSERVER_H

#include "../Observer.h"
#include "../LoadingHandler.h"

class TestObserver: public Observer {
public:
    TestObserver(LoadingHandler *loadingHandler, int state);
    virtual ~TestObserver();

    bool update() override;

    int getState() const;
    void setState(int state);

    LoadingHandler *getLoadingHandler() const;
    void setLoadingHandler(LoadingHandler *loadingHandler);

private:
    LoadingHandler* loadingHandler;
    int state;
};


#endif //PROGETTO_TESTOBSERVER_H
