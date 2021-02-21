//
// Created by tommaso on 11/02/21.
//

#ifndef EASYBANK_MOVEMENTERROR_H
#define EASYBANK_MOVEMENTERROR_H

#include <exception>
#include <stdexcept>


class MovementError : public std::runtime_error {
public:
    MovementError(const char *error) : std::runtime_error(error) {}
};


#endif //EASYBANK_MOVEMENTERROR_H
