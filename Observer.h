//
// Created by tommaso on 22/11/20.
//

#ifndef EASYBANK_OBSERVER_H
#define EASYBANK_OBSERVER_H

//classe Astratta Observer
class Observer {
public:
    virtual ~Observer() {};

    virtual void update(float ammount) = 0;

    virtual void detach() = 0;

    virtual void attach() = 0;

};


#endif //EASYBANK_OBSERVER_H
