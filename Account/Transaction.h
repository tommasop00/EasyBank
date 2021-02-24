//
// Created by tommaso on 20/02/21.
//

#ifndef EASYBANK_TRANSACTION_H
#define EASYBANK_TRANSACTION_H

#include <string>


class Transaction {
public:
    Transaction(const std::string &from, float amount, const std::string &to = "") : from(from), to(to),
                                                                                     amount(amount) {}

    const std::string &getFrom() const {
        return from;
    }

    const std::string &getTo() const {
        return to;
    }


    std::string toString() const;


private:
    std::string from;
    std::string to;
    float amount;
};


#endif //EASYBANK_TRANSACTION_H
