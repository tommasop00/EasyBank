//
// Created by tommaso on 20/02/21.
//

#include "LogFileManager.h"

std::vector<std::unique_ptr<Transaction>> LogFileManager::getallTransiction(const std::string &iban) {
    std::vector<std::unique_ptr<Transaction>> ret;
    auto allLog = this->getRowFile();
    std::vector<std::string> arraySplit;
    for (auto log : allLog) {
        arraySplit = split(log, ' ', 3);

        if (arraySplit[0] == iban || arraySplit[2] == iban) {
            float ammount = std::stof(arraySplit[1]);
            if (arraySplit.size() == 3) {
                std::unique_ptr<Transaction> t(new Transaction(arraySplit[0], ammount, arraySplit[2]));
                ret.push_back(std::move(t));
            } else {
                std::unique_ptr<Transaction> t(new Transaction(arraySplit[0], ammount));
                ret.push_back(std::move(t));
            }
        }
    }
    return ret;
}

void LogFileManager::addNewTransaction(std::string f, float a, std::string t) {
    std::string temp = f + " " + std::to_string(a);
    if (t != "") {
        temp += " " + t;
    }
    this->write(temp);
}

