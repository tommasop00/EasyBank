//
// Created by tommaso on 24/11/20.
//

#include "gtest/gtest.h"
#include <memory>
#include "../Account/MyAccount.h"
#include "../Account/OtherAccount.h"

class AccountSuite : public ::testing::Test {
protected:
    virtual void SetUp() {
        a.addObserver(&b);
        a.addObserver(&b);

    }

    //GameCharacter c;
    MyAccount a(

    "",10);
    OtherAccount b;
};

TEST_F(AccountSuite, TestMove) {
    a.clearObserver();
    std::list<Observer *> list;
    list.clear();
    EXPECT_EQ(a.getObservers(), list) << "Non Uguali 1";
    //EXPECT_EQ(24, 12) << "NOn Ugauli 2";
}