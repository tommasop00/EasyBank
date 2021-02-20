//
// Created by tommaso on 26/11/20.
//

#include "User.h"
#include "MovementError.h"
#include "../FileManager/AccountFileManager.h"
#include <iostream>
#include <memory>


const std::map<std::string, std::unique_ptr<Account>> &User::getIbans() const {
    return ibans;
}

const std::string &User::getSelectedIban() const {
    return selectedIban;
}

void User::setSelectedIban(const std::string &selectedIbanmain) {
    selectedIban = selectedIbanmain;
    this->notify();
}

std::map<std::string, std::unique_ptr<Account>> User::findIbans() const {
    FileManager file("./fileTXT/accountFile.txt");
    if (file.is_open()) {
        std::string sLine;
        std::map<std::string, std::unique_ptr<Account>> ibans;
        bool find = false;
        std::vector<std::string> splitArray;
        int count = 0;
        for (auto sLine : file.getRowFile()) {
            if (sLine != "") {
                splitArray = split(sLine, ' ', 5);
                count++;
                if (std::stoi(splitArray[0]) == this->user.second) {
                    float ammount = std::stof(splitArray[2]);
                    std::unique_ptr<Account> tempAccount(
                            new Account(ammount, splitArray[3], splitArray[4], count, splitArray[1]));
                    find = true;
                    ibans.insert(std::make_pair(splitArray[1], std::move(tempAccount)));
                }
            }
        }
        if (find) {
            return ibans;
        }

    } else {
        throw std::runtime_error("Errore , file non aperto");
    }
    return std::map<std::string, std::unique_ptr<Account>>();


}


void User::notify() {
    for (auto itr : this->getObservers()) {
        itr->update();
    }
}

void User::addObserver(Observer *ob) {
    observers.push_back(ob);
}

void User::removeObserver(Observer *ob) {
    observers.remove(ob);
}

void User::clearObserver() {
    observers.clear();
}

const std::list<Observer *> &User::getObservers() const {
    return observers;
}

float User::getAmount() const {
    AccountFileManager fileManager("./fileTXT/accountFile.txt");
    return fileManager.getAmmount(selectedIban);
}

const std::pair<std::string, int> &User::getUser() const {
    return user;
}

void User::pushIban(std::unique_ptr<Account> a) {
    ibans.insert(std::make_pair(a->getIban(), std::move(a)));
    this->notify();
}


















