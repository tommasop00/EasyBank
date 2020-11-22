//
// Created by tommaso on 22/11/20.
//

#ifndef EASYBANK_SUBJECT_H
#define EASYBANK_SUBJECT_H


class Subject {
public:
    virtual ~Subject() {} ;
    virtual void subscribe() = 0;
    virtual void unsubscribe() = 0;

    virtual void notify() = 0;
};


#endif //EASYBANK_SUBJECT_H
