//
// Created by tommaso on 24/11/20.
//

#include "gtest/gtest.h"

class BankSuite : public ::testing::Test {
protected:
    virtual void SetUp() {
        /*c.setXPos(10);
        c.setYPos(10);
        c.setFighting(true);*/
    }
    //GameCharacter c;
};

TEST_F(BankSuite, TestMove) {

    EXPECT_EQ(10, 11) << "Non Uguali 1";
    EXPECT_EQ(24, 12) << "NOn Ugauli 2";
}