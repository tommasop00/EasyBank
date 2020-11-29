//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_MYACCOUNT_H
#define EASYBANK_MYACCOUNT_H

#include <string>
#include "../Subject.h"
#include <memory>
#include <vector>
#include <map>
#include <stdexcept>
#include <fstream>
#include "../MethodClass.h"
#include "Account.h"


class MyAccount : public Subject {

public:

    MyAccount(const std::string username, const int id) : Subject(), user(std::make_pair(username, id)) {
        this->ibans = this->findIbans();
    }

    const std::string &getSelectedIban() const;

    void setSelectedIban(const std::string &selectedIban);

    const std::map<std::string, std::unique_ptr<Account>> &getIbans() const;

    virtual ~MyAccount() {}

    std::map<std::string, std::unique_ptr<Account>> findIbans() const;

    void addObserver(
            std::unique_ptr<Observer> ob) override;//TODO come parametro ci potrebbre stare di passsare direttamente il vettore

    void notify() override;

private:
    std::pair<std::string, int> user;
    std::map<std::string, std::unique_ptr<Account>> ibans;
    std::string selectedIban;
};


#endif //EASYBANK_MYACCOUNT_H
