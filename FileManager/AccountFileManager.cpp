//
// Created by tommaso on 19/02/21.
//

#include "AccountFileManager.h"
#include <iostream>

std::map<std::string, std::unique_ptr<Account>> AccountFileManager::getAllAccountFromFile() {
    std::map<std::string, std::unique_ptr<Account>> ret;
    auto ibanAccounts = this->getRowFile();
    std::vector<std::string> arraySplit;
    for (auto account : ibanAccounts) {
        arraySplit = split(account, ' ', 5);
        float ammount = std::stof(arraySplit[2]);
        int id = std::stoi(arraySplit[0]);
        std::unique_ptr<Account> a(new Account(ammount, arraySplit[3], arraySplit[4], id, arraySplit[1]));
        ret.insert(std::make_pair(arraySplit[1], std::move(a)));
    }
    return ret;
}


void AccountFileManager::updateFile(std::map<std::string, std::unique_ptr<Account>> &allAccount) {
    const char *path1 = "./fileTXT/accountFile.txt";
    const char *path2 = "./fileTXT/accountFile2.txt";
    const char *path3 = "./fileTXT/accountFile3.txt";
    bool first;
    FileManager fileManager2(path2);

    for (const auto &account: allAccount) {
        std::string temp = std::to_string(account.second->getId()) + " " + account.second->getIban() + " " +
                           std::to_string(account.second->getAmmount()) + " " + account.second->getfc() + " " +
                           account.second->getSurnameBusinessName();
        if (first == false) {
            fileManager2.write(temp, true);

            first = true;
        } else {
            fileManager2.write(temp);
        }
    }

    if (rename(path1, path3) != 0) {
        throw std::runtime_error("Errore nel rinomina");
    }
    if (rename(path2, path1) != 0) {
        throw std::runtime_error("Errore nel rinomina");
    }
    if (remove(path3) != 0) {
        throw std::runtime_error("Errore nella cancellazione");
    }
}

float AccountFileManager::getAmmount(const std::string iban) {
    auto t = this->getAllAccountFromFile();
    return t.find(iban)->second->getAmmount();
}



