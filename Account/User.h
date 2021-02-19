//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_USER_H
#define EASYBANK_USER_H

#include <string>
#include "../Subject.h"
#include <memory>
#include <vector>
#include <map>
#include <stdexcept>
#include "../Utility.h"
#include "Account.h"
#include <list>


class User : public Subject {

public:

    User(const std::string username, int id) : Subject(), user(std::make_pair(username, id)) {
        this->ibans = this->findIbans();
    }

    const std::string &getSelectedIban() const;

    void setSelectedIban(const std::string &selectedIban);

    const std::map<std::string, std::unique_ptr<Account>> &getIbans() const;

    void pushIban(std::unique_ptr<Account> a);

    virtual ~User() {};

    std::map<std::string, std::unique_ptr<Account>> findIbans() const;

    void addObserver(Observer *ob) override;

    void removeObserver(Observer *ob) override;

    void notify(std::string iban, float ammount) override;

    void notify2() override;

    void clearObserver() override;

    //void createNewCurrentAccount();


    void chooseAccount();

    const std::list<Observer *> &getObservers() const;

    void getAmount() const;

    const std::pair<std::string, int> &getUser() const;

private:
    std::pair<std::string, int> user;
    std::map<std::string, std::unique_ptr<Account>> ibans;
    std::string selectedIban;
    std::list<Observer *> observers;
};


#endif //EASYBANK_USER_H
