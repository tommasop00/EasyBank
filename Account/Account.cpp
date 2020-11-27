//
// Created by tommaso on 26/11/20.
//

#include "Account.h"

int Account::getAmmount() const {
    return ammount;
}

void Account::setAmmount(int ammount) {
    Account::ammount = ammount;
}

const std::vector<std::string> &Account::getIbans() const {
    return ibans;
}

void Account::setIbans(const std::vector<std::string> &ibans) {
    Account::ibans = ibans;
}
