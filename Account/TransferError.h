//
// Created by tommaso on 11/02/21.
//

#ifndef EASYBANK_TRANSFERERROR_H
#define EASYBANK_TRANSFERERROR_H

#include <exception>
#include <stdexcept>


class TransferError : public std::runtime_error {
public:
    TransferError(const char *error) : std::runtime_error(error) {}
};


#endif //EASYBANK_TRANSFERERROR_H
