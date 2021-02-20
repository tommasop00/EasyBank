//
// Created by tommaso on 22/11/20.
//

#ifndef EASYBANK_OBSERVER_H
#define EASYBANK_OBSERVER_H

#include <string>
#include "Account/Account.h"

//classe Astratta Observer
class Observer {
public:
    virtual ~Observer() {};

    virtual void update() = 0; // change accountUse


    virtual void detach() = 0;

    virtual void attach() = 0;

};


#endif //EASYBANK_OBSERVER_H
