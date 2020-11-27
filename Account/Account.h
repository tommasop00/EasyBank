//
// Created by tommaso on 26/11/20.
//

#ifndef EASYBANK_ACCOUNT_H
#define EASYBANK_ACCOUNT_H

#include <string>
#include <vector>
#include "../Observer.h"

class Account : public Observer {

public:
    int getAmmount() const;

    void setAmmount(int ammount);

    const std::vector<std::string> &getIbans() const;

    void setIbans(const std::vector<std::string> &ibans);

protected:
    std::vector<std::string> ibans;
    int ammount;

};


#endif //EASYBANK_ACCOUNT_H
