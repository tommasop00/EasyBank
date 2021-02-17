//
// Created by tommaso on 11/02/21.
//

#ifndef EASYBANK_TRANSACTIONERROR_H
#define EASYBANK_TRANSACTIONERROR_H

#include <exception>
#include <stdexcept>


class TransactionError : public std::runtime_error {
public:
    TransactionError(const char *error) : std::runtime_error(error) {}
};


#endif //EASYBANK_TRANSACTIONERROR_H
