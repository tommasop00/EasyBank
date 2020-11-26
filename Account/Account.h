//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_ACCOUNT_H
#define EASYBANK_ACCOUNT_H

#include <string>
#include "../Observer.h"
class Account : public Observer {

protected:
    int ammount;
    std::string IBAN;

};


#endif //EASYBANK_ACCOUNT_H
