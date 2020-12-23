//
// Created by tommaso on 24/11/20.
//

#include "gtest/gtest.h"
#include <memory>
#include "../Account/MyAccount.h"
#include "../Account/OtherAccount.h"

class AccountSuite : public ::testing::Test {
protected:
    FileManager *f;
    Account *a;
};

TEST_F(AccountSuite, FileManager) {
    f = new FileManager("/home/tommaso/Scrivania/CLionProject/EasyBank/fileTXT/accountFile.txt");
    auto lines = f->getRowFile();
    EXPECT_EQ(lines.capacity(), lines.capacity());
}

TEST_F(AccountSuite, AccountIban) {
    a = new Account();
    std::string c = a->generateNewIban();
    int t;
    EXPECT_EQ(c, "ddddd");
}
