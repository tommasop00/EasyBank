//
// Created by tommaso on 20/02/21.
//

#include "Transaction.h"

std::string Transaction::toString() const {
    return from + " " + std::to_string(amount) + " " + to;
}
