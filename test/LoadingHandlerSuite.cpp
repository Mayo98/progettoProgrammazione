//
// Created by Giacomo Magistrato on 23/02/22.
//


#include <gtest/gtest.h>
#include "TestObserver.h"
#include "../LoadingHandler.h"

class LoadingHandlerSuite: public ::testing::Test {

};

TEST(LoadingHandlerSuite, State) {

    LoadingHandler* loadingHandler = new LoadingHandler();
    TestObserver* testObserver = new TestObserver(loadingHandler, 0);

    ASSERT_EQ(0, testObserver->getState());

    loadingHandler->addO(testObserver);
    loadingHandler->setState(35);

    ASSERT_EQ(35, testObserver->getState());
}

TEST(LoadingHandlerSuite, MaxState) {

    LoadingHandler* loadingHandler = new LoadingHandler();
    TestObserver* testObserver = new TestObserver(loadingHandler, 0);

    loadingHandler->addO(testObserver);
    loadingHandler->setState(100);

    ASSERT_EQ(100, testObserver->getState());
}

TEST(LoadingHandlerSuite, OverState) {

    LoadingHandler* loadingHandler = new LoadingHandler();
    TestObserver* testObserver = new TestObserver(loadingHandler, 0);

    loadingHandler->addO(testObserver);
    loadingHandler->setState(121);

    ASSERT_EQ(100, testObserver->getState());
}

TEST(LoadingHandlerSuite, UnderState) {

    LoadingHandler* loadingHandler = new LoadingHandler();
    TestObserver* testObserver = new TestObserver(loadingHandler, 0);

    loadingHandler->addO(testObserver);
    loadingHandler->setState(-3);

    ASSERT_EQ(0, testObserver->getState());
}
