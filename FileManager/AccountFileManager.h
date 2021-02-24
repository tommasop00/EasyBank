//
// Created by tommaso on 19/02/21.
//

#ifndef EASYBANK_ACCOUNTFILEMANAGER_H
#define EASYBANK_ACCOUNTFILEMANAGER_H


#include "FileManager.h"
#include "../Account/Account.h"
#include <map>
#include <memory>


class AccountFileManager : public FileManager {
public:
    AccountFileManager(const char *filename, const char *type = "a+") : FileManager(filename, type) {}

    virtual ~AccountFileManager() {};

    std::map<std::string, std::unique_ptr<Account>> getAllAccountFromFile();

    void updateFile(std::map<std::string, std::unique_ptr<Account>> &allAccount);

    float getAmmount(const std::string iban);


private:
};


#endif //EASYBANK_ACCOUNTFILEMANAGER_H
