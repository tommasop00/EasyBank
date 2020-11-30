//
// Created by tommaso on 29/11/20.
//

#ifndef EASYBANK_OTHERACCOUNT_H
#define EASYBANK_OTHERACCOUNT_H


#include "../Observer.h"
#include "Account.h"
#include "MyAccount.h"

class OtherAccount : public Account, public Observer {
public:

    OtherAccount(int id, std::string iban, float ammount, std::string FC, std::string nameProprietary, MyAccount *sub)
            : Account(id, iban, ammount, fc, nameProprietary), Observer(), sub(sub) {};

    void update(float ammount) override;

    void detach() override;

    void attach() override;

private:
    MyAccount *sub;
};


#endif //EASYBANK_OTHERACCOUNT_H
