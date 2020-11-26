//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_PRIVATEACCOUNT_H
#define EASYBANK_PRIVATEACCOUNT_H

#include <string>
#include "Account.h"
class PrivateAccount : public Account {

private:
    std::string FiscalCode;
    std::string Name;
    std::string Surname;

};


#endif //EASYBANK_PRIVATEACCOUNT_H
