//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_ACCOUNT_H
#define EASYBANK_ACCOUNT_H

#include <string>
#include <utility>
#include <vector>
#include "../FileManager/FileManager.h"

class Account {

public:

    Account(float ammount, std::string &FC, std::string &nameProprietary, int &id, std::string &iban) : id(id),
                                                                                                        iban(iban),
                                                                                                        amount(
                                                                                                                ammount),
                                                                                                        fc(FC),
                                                                                                        nameProprietary(
                                                                                                                nameProprietary) {}

    Account(float ammount, std::string &FC, std::string &nameProprietary, int id) : amount(ammount),
                                                                                    fc(FC),
                                                                                    nameProprietary(nameProprietary),
                                                                                    id(id) {
        auto ibanRet = this->generateNewIban();
        this->iban = ibanRet;
        FileManager fileManager("./fileTXT/accountFile.txt");
        std::string accountString =
                std::to_string(this->id) + " " + this->iban + " " + std::to_string(this->amount) + " " + this->fc +
                " " + this->nameProprietary;
        fileManager.write(accountString);
    };


    const std::string &getIban() const {
        return iban;
    }

    const std::string &getfc() const {
        return fc;
    }

    float getAmount() const {
        return amount;
    }

    void setAmount(float amount) {
        this->amount = amount;
    }

    int getId() const {
        return id;
    }

    const std::string &getSurnameBusinessName() const {
        return nameProprietary;
    }

    const std::string generateNewIban();

    std::string toString() const;

protected:
    int id;
    std::string iban;
    std::string fc;
    float amount;
    std::string nameProprietary;

};


#endif //EASYBANK_ACCOUNT_H
