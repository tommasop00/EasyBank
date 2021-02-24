//
// Created by tommaso on 29/11/20.
//

#ifndef EASYBANK_MOVEMENTS_H
#define EASYBANK_MOVEMENTS_H


#include "../Observer.h"
#include "Account.h"
#include "User.h"
#include "MovementError.h"
#include <cmath>

class Movements : public Observer {
public:

    Movements(User *sub) : sub(sub) {
        attach();
    };

    virtual ~Movements() {
        detach();
    };

    void makeMovement(float amount, char type, std::string ibanOther = "");

    void update() override;

    void detach() override;

    void attach() override;


private:
    User *sub;
    std::string currentIban;
};


#endif //EASYBANK_MOVEMENTS_H
