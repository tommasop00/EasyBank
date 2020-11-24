//
// Created by tommaso on 24/11/20.
//

#include <string>

#ifndef EASYBANK_ACCOUNT_H
#define EASYBANK_ACCOUNT_H


#include "../Subject.h"

class Account : public Subject {

protected:
    std::string IBAN;
};


#endif //EASYBANK_ACCOUNT_H
