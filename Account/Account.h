//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_ACCOUNT_H
#define EASYBANK_ACCOUNT_H

#include <string>
#include <utility>
#include <vector>
#include "../FileManager.h"

class Account {

public:
    Account(float &ammount, std::string &FC, std::string &nameProprietary, int &id) : _ammount(ammount),
                                                                                      _fc(FC),
                                                                                      nameProprietary(nameProprietary),
                                                                                      _id(id) {
        auto ibanRet = this->generateNewIban();
        this->_iban = ibanRet;
        FileManager fileManager("./fileTXT/accountFile.txt");
        std::string accountString =
                std::to_string(this->_id) + " " + this->_iban + " " + std::to_string(this->_ammount) + " " + this->_fc +
                " " + this->nameProprietary;
        fileManager.write(accountString);
    };

    Account(float &ammount, std::string &FC, std::string &nameProprietary, int &id, std::string &iban) : _id(id),
                                                                                                         _iban(iban),
                                                                                                         _ammount(
                                                                                                                 ammount),
                                                                                                         _fc(FC),
                                                                                                         nameProprietary(
                                                                                                                 nameProprietary) {};

    Account() {};

    virtual ~Account() {};


    const std::string &getIban() const {
        return _iban;
    }

    const std::string &getfc() const {
        return _fc;
    }

    float getAmmount() const {
        return _ammount;
    }

    void setAmmount(float ammount) {
        _ammount = ammount;
    }

    const std::string &getSurnameBusinessName() const {
        return nameProprietary;
    }

    const std::string generateNewIban();

protected:
    int _id;
    std::string _iban;
    std::string _fc;
    float _ammount;
    std::string nameProprietary;

};


#endif //EASYBANK_ACCOUNT_H
