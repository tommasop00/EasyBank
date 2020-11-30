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

    Account(int id, std::string iban, float ammount, std::string FC, std::string nameProprietary) : iban(iban),
                                                                                                    ammount(ammount),
                                                                                                    fc(fc),
                                                                                                    nameProprietary(
                                                                                                            nameProprietary) {};

    virtual ~Account() {};

    const std::string &getIban() const {
        return iban;
    }

    const std::string &getfc() const {
        return fc;
    }

    float getAmmount() const {
        return ammount;
    }

    const std::string &getSurnameBusinessName() const {
        return nameProprietary;
    }

protected:
    int id;
    std::string iban;
    std::string fc;
    float ammount;
    std::string nameProprietary;

};


#endif //EASYBANK_ACCOUNT_H
