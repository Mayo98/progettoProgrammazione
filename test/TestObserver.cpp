//
// Created by Giacomo Magistrato on 07/03/22.
//

#include "TestObserver.h"


TestObserver::TestObserver(LoadingHandler *loadingHandler, int state) : loadingHandler(loadingHandler), state(state) {}

TestObserver::~TestObserver() {
    loadingHandler->remove(this);
}

bool TestObserver::update() {
    if (loadingHandler != nullptr) {
        state = loadingHandler->getState();

        if (state < 0) {
            state = 0;
        }
        if (state > 100) {
            state = 100;
        }

        return true;
    }
    else {
        return false;
    }
}

int TestObserver::getState() const {
    return state;
}

void TestObserver::setState(int state) {
    TestObserver::state = state;
}

LoadingHandler *TestObserver::getLoadingHandler() const {
    return loadingHandler;
}

void TestObserver::setLoadingHandler(LoadingHandler *loadingHandler) {
    TestObserver::loadingHandler = loadingHandler;
}


