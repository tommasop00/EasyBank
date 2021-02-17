//
// Created by tommaso on 22/11/20.
//

#ifndef EASYBANK_SUBJECT_H
#define EASYBANK_SUBJECT_H

#include <vector>
#include "Observer.h"
#include <memory>


class Subject {
public:
    virtual ~Subject() {};

    virtual void addObserver(Observer *ob) = 0;

    virtual void removeObserver(Observer *ob) = 0;

    virtual void clearObserver() = 0;

    virtual void notify(std::string iban, float ammount) = 0; //make transfer

    virtual void notify2() = 0; // change iban


protected:

};


#endif //EASYBANK_SUBJECT_H
