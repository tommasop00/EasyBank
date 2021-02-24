//
// Created by tommaso on 24/11/20.
//

#include "gtest/gtest.h"
#include <memory>
#include "../..//Account/User.h"
#include "../../Account/Movements.h"
#include "../../FileManager/AccountFileManager.h"
#include "../../FileManager/LogFileManager.h"


class AccountSuite : public ::testing::Test {
protected:
    int id = 1;
    std::string a = "fjdsk", b = "fjdskl", c = "fhjdks";
    Account *at = new Account(10, a, b, id, c);
    User *user = new User("prova1", 1);
    FileManager *f = new FileManager("./fileTXT/accountFile.txt");
    AccountFileManager *fileAccount = new AccountFileManager("./fileTXT/accountFile.txt");
    LogFileManager *fileLog = new LogFileManager("./fileTXT/log.txt");
    Movements *movement = new Movements(user);

};

TEST_F(AccountSuite, countRow) {
    auto lines = f->getRowFile();
    EXPECT_EQ(lines.capacity(), 8);
}

TEST_F(AccountSuite, iban) {
    std::string res = at->generateNewIban();
    EXPECT_EQ(res, "IT00A0006");
}

TEST_F(AccountSuite, movementAccount) {
    auto t = fileAccount->getAllAccountFromFile();
    EXPECT_EQ(t.size(), 10);
}


TEST_F(AccountSuite, logFile) {
    auto t = fileLog->getAllTransiction("IT00A0004");
    EXPECT_EQ(t.size(), 7);
}

TEST_F(AccountSuite, movementLog) {
    user->setSelectedIban("IT00A0002");
    movement->makeMovement(10, 'b', "IT00A0005");
    auto t = fileLog->getAllTransiction("IT00A0005");
    EXPECT_EQ(t.at(t.size() - 1).get()->toString(), "IT00A0002 10.000000 IT00A0005");
}

TEST_F(AccountSuite, utilityTEST) {
    std::string temp = "prova utility class";
    auto t = split(temp, ' ', 1);
    EXPECT_EQ(t[0], "prova");
}



