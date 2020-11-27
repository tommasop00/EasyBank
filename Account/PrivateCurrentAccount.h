//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_PRIVATECURRENTACCOUNT_H
#define EASYBANK_PRIVATECURRENTACCOUNT_H

#include <string>
#include "Account.h"

class PrivateCurrentAccount : public Account {

private:
    std::string FiscalCode;
    std::string Name;
    std::string Surname;

};


#endif //EASYBANK_PRIVATECURRENTACCOUNT_H
