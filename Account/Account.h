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

    Account(std::string iban, float ammount, std::string FCVatNumber, std::string surnameBusinessName) : iban(iban),
                                                                                                         ammount(ammount),
                                                                                                         FCVatNumber(
                                                                                                                 FCVatNumber),
                                                                                                         surnameBusinessName(
                                                                                                                 surnameBusinessName) {};

    virtual ~Account() {};

    const std::string &getIban() const {
        return iban;
    }

    const std::string &getFcVatNumber() const {
        return FCVatNumber;
    }

    float getAmmount() const {
        return ammount;
    }

    const std::string &getSurnameBusinessName() const {
        return surnameBusinessName;
    }

protected:
    std::string iban;
    std::string FCVatNumber;
    float ammount;
    std::string surnameBusinessName;

};


#endif //EASYBANK_ACCOUNT_H
