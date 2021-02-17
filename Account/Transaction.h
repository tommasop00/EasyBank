//
// Created by tommaso on 29/11/20.
//

#ifndef EASYBANK_TRANSACTION_H
#define EASYBANK_TRANSACTION_H


#include "../Observer.h"
#include "Account.h"
#include "MyAccount.h"
#include "TransferError.h"
#include <cmath>

class Transition : public Observer {
public:

    Transition(MyAccount *sub) : sub(sub) {
        attach();
    };

    virtual ~Transition();

    void update(float ammount, Account *acc) override;

    void update2() override;

    void detach() override;

    void attach() override;

    void doTransferExtern(FileManager &fileOriginal, FileManager &fileUpdate, std::string &iban1, std::string &iban2,
                          float ammount);

    void doTransferIntern(FileManager &fileOriginal, FileManager &fileUpdate, float ammount);


    bool checkifIbanOtherExist(FileManager &fileOriginal, std::string &iban);


private:
    MyAccount *sub;
    Account *acc;

};


#endif //EASYBANK_TRANSACTION_H
