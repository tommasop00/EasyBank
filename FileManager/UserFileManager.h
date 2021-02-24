//
// Created by tommaso on 19/02/21.
//

#ifndef EASYBANK_USERFILEMANAGER_H
#define EASYBANK_USERFILEMANAGER_H

#include <string>
#include <vector>
#include "FileManager.h"


class UserFileManager : public FileManager {

public:
    UserFileManager(const char *filename, const char *type = "a+") : FileManager(filename, type) {}

    virtual ~UserFileManager() {}

    int login(std::string &username, std::string &password);

    bool findUsername(std::string &username);

};


#endif //EASYBANK_USERFILEMANAGER_H
