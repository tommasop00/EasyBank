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
                                                                                                        ammount(
                                                                                                                ammount),
                                                                                                        fc(FC),
                                                                                                        nameProprietary(
                                                                                                                nameProprietary) {}

    Account(float ammount, std::string &FC, std::string &nameProprietary, int id) : ammount(ammount),
                                                                                    fc(FC),
                                                                                    nameProprietary(nameProprietary),
                                                                                    id(id) {
        auto ibanRet = this->generateNewIban();
        this->iban = ibanRet;
        FileManager fileManager("./fileTXT/accountFile.txt");
        std::string accountString =
                std::to_string(this->id) + " " + this->iban + " " + std::to_string(this->ammount) + " " + this->fc +
                " " + this->nameProprietary;
        fileManager.write(accountString);
    };



    const std::string &getIban() const {
        return iban;
    }

    const std::string &getfc() const {
        return fc;
    }

    float getAmmount() const {
        return ammount;
    }

    void setAmmount(float ammount) {
        this->ammount = ammount;
    }

    int getId() const {
        return id;
    }

    const std::string &getSurnameBusinessName() const {
        return nameProprietary;
    }

    const std::string generateNewIban();

    std::string print() const;

protected:
    int id;
    std::string iban;
    std::string fc;
    float ammount;
    std::string nameProprietary;

};


#endif //EASYBANK_ACCOUNT_H
