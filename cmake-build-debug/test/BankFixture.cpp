//
// Created by tommaso on 24/11/20.
//

#include "gtest/gtest.h"
#include <memory>
#include "../..//Account/MyAccount.h"
#include "../../Account/Transaction.h"

class AccountSuite : public ::testing::Test {
protected:
    FileManager *f;
    Account *a;
};

TEST_F(AccountSuite, t) {
    f = new FileManager("/home/tommaso/Scrivania/CLionProject/EasyBank/fileTXT/accountFile.txt");
    auto lines = f->getRowFile();
    EXPECT_EQ(lines.capacity(), 5);
}

TEST_F(AccountSuite, f) {
    a = new Account();
    std::string c = a->generateNewIban();
    int t;
    EXPECT_EQ(c, "IT00A0004");
}
