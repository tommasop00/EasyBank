//
// Created by tommaso on 29/11/20.
//

#ifndef EASYBANK_TRANSITION_H
#define EASYBANK_TRANSITION_H


#include "../Observer.h"
#include "Account.h"
#include "User.h"
#include "TransactionError.h"
#include <cmath>

class Transition : public Observer {
public:

    Transition(User *sub) : sub(sub) {
        attach();
    };

    virtual ~Transition() {
        this->detach();
    };

    void update(float ammount, std::string ibanOther) override;

    void update2() override;

    void detach() override;

    void attach() override;

    void doTransferExtern(FileManager &fileOriginal, FileManager &fileUpdate, std::string &iban1, std::string &iban2,
                          float ammount);

    void doTransferIntern(FileManager &fileOriginal, FileManager &fileUpdate, float ammount);


    bool checkifIbanOtherExist(FileManager &fileOriginal, std::string &iban);


private:
    User *sub;
    Account *acc;

};


#endif //EASYBANK_TRANSITION_H
