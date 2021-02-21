//
// Created by tommaso on 20/02/21.
//

#ifndef EASYBANK_LOGFILEMANAGER_H
#define EASYBANK_LOGFILEMANAGER_H


#include "FileManager.h"
#include <memory>
#include "../Account/Transaction.h"

class LogFileManager : public FileManager {
public:
    LogFileManager(const char *filename, const char *type = "a+") : FileManager(filename, type) {}

    std::vector<std::unique_ptr<Transaction>> getallTransiction(const std::string &iban);

    void addNewTransaction(std::string f, float a, std::string t = "");

};


#endif //EASYBANK_LOGFILEMANAGER_H
