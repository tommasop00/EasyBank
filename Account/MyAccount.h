//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_MYACCOUNT_H
#define EASYBANK_MYACCOUNT_H

#include <string>
#include "../Subject.h"
#include <memory>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "AccountFactory.h"
#include "../MethodClass.h"

class MyAccount : public Subject {

public:

    MyAccount(const std::string &username, const int id) : Subject(), username(username), id(id) {
        this->ibans = this->findIbans();
    }

    int getId() const;

    void setId(int id);

    int getAmmount() const;

    void setAmmount(int ammount);

    const std::string &getUsername() const;

    void setUsername(const std::string &username);

    std::unique_ptr<std::vector<std::string>> findIbans() const;

    virtual ~MyAccount() {}


    void addObserver(
            std::unique_ptr<Observer> ob) override;//TODO come parametro ci potrebbre stare di passsare direttamente il vettore

    void notify() override;

private:
    int id;
    int ammount{};
    std::string username;
    std::unique_ptr<std::vector<std::string>> ibans;


};


#endif //EASYBANK_MYACCOUNT_H
