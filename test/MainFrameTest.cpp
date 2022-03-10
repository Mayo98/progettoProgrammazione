//
// Created by Giacomo Magistrato on 16/02/22.
/*
#include <gtest/gtest.h>
// /#include <gmock/gmock.h>
#include <iostream>
#include "../LoadingHandler.h"
#include "../MainFrame.h"
#include "../MainFrame.cpp"


class MainFrameTest: public ::testing::Test {

};

TEST(MainFrameTest, OpenClose) {

    MainFrame* mainFrame = new MainFrame("Main menu", wxPoint(50, 50), wxSize(400,200));
    mainFrame->Show(true);

    ASSERT_EQ(mainFrame->IsShown(), 1);

    wxCommandEvent* event = new wxCommandEvent();
    mainFrame->OnExit(*event);

    ASSERT_EQ(mainFrame->IsShown(), 0);

    mainFrame->Destroy();
}

TEST(MainFrameTest, CloseLoading) {

    MainFrame* mainFrame = new MainFrame("Main menu", wxPoint(50, 50), wxSize(400,200));
    mainFrame->Show(true);

    LoadingHandler* loadingHandler = new LoadingHandler();

    loadingHandler->addO(mainFrame);
    mainFrame->setLoadingHandler(loadingHandler);
    wxArrayString elem;
    elem.Add("one");
    elem.Add("two");
    loadingHandler->upload(0, elem, 100);

    wxCommandEvent* event = new wxCommandEvent();
    mainFrame->OnExit(*event);

    ASSERT_EQ(mainFrame->IsShown(), 0);

    mainFrame->Destroy();
    delete loadingHandler;
}
*/