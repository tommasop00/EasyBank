//
// Created by tommaso on 20/02/21.
//

#ifndef EASYBANK_TRANSACTION_H
#define EASYBANK_TRANSACTION_H

#include <string>


class Transaction {
public:
    Transaction(const std::string &from, float ammount, const std::string &to = "") : from(from), to(to),
                                                                                      ammount(ammount) {}

    const std::string &getFrom() const {
        return from;
    }

    const std::string &getTo() const {
        return to;
    }

    float getAmmount() const {
        return ammount;
    }

    std::string print() const;


private:
    std::string from;
    std::string to;
    float ammount;
};


#endif //EASYBANK_TRANSACTION_H
