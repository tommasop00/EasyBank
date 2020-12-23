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
    Account(int &id, float &ammount, std::string &FC, std::string &nameProprietary) : _id(id), _ammount(ammount),
                                                                                      _fc(FC),
                                                                                      nameProprietary(nameProprietary) {
        this->_iban = this->generateNewIban();
    };

    Account(int &id, std::string &iban, float &ammount, std::string &FC, std::string &nameProprietary) : _id(id),
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
