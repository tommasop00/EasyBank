//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_ACCOUNT_H
#define EASYBANK_ACCOUNT_H

#include <string>
#include <vector>

class Account {

public:
    Account() {};

    Account(int id, const std::string &iban, float ammount, std::string &FC, std::string &nameProprietary) : _iban(
            iban),
                                                                                                             _ammount(
                                                                                                                     ammount),
                                                                                                             _fc(FC),
                                                                                                             nameProprietary(
                                                                                                                     nameProprietary) {};


    void generateNewIBanAndId() {

    }

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

protected:
    int _id;
    std::string _iban;
    std::string _fc;
    float _ammount;
    std::string nameProprietary;

};


#endif //EASYBANK_ACCOUNT_H
