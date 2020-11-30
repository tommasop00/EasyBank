//
// Created by tommaso on 29/11/20.
//

#include "OtherAccount.h"

void OtherAccount::detach() {
    sub->removeObserver(this);
}

void OtherAccount::update(float ammount) {

}

void OtherAccount::attach() {
    sub->addObserver(this);
}
