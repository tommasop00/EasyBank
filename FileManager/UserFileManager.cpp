//
// Created by tommaso on 19/02/21.
//

#include "UserFileManager.h"

int UserFileManager::login(std::string &username, std::string &password) {
    std::vector<std::string> arraySplit;
    int count = 0;
    for (auto line : this->getRowFile()) {
        count++;
        arraySplit = split(line, ' ');
        if (arraySplit[0] == username) {
            if (arraySplit[1] == password) {
                return count;
            }
        }

    }
    return 0;
}

bool UserFileManager::findUsername(std::string &username) {
    std::vector<std::string> arraySplit;
    for (auto line : this->getRowFile()) {
        arraySplit = split(line, ' ');
        if (arraySplit[0] == username) {
            return true;
        }
    }
    return false;
}
