//
// Created by tommaso on 29/11/20.
//

#include "Movements.h"
#include "../FileManager/AccountFileManager.h"
#include "../FileManager/LogFileManager.h"

void Movements::detach() {
    sub->removeObserver(this);
}


void Movements::attach() {
    sub->addObserver(this);
}


void Movements::update() {
    this->currentIban = this->sub->getSelectedIban();
}


void Movements::makeMovement(float ammount, char type, std::string ibanOther) {
    const char *path1 = "./fileTXT/accountFile.txt";

    const char *pathlog = "./fileTXT/log.txt";

    AccountFileManager accountManager(path1);
    LogFileManager logManager(pathlog, "a+");
    auto allAccount = accountManager.getAllAccountFromFile();
    if (ibanOther != "") {
        if (allAccount.find(ibanOther) == allAccount.end())
            throw MovementError("Iban non trovato");
    }
    if (type == 'b') {
        float ammountAccount = allAccount.find(this->currentIban)->second->getAmmount();
        if (ammountAccount >= ammount) {
            allAccount.find(this->currentIban)->second->setAmmount(
                    allAccount.find(this->currentIban)->second->getAmmount() - ammount);
            allAccount.find(ibanOther)->second->setAmmount(allAccount.find(ibanOther)->second->getAmmount() + ammount);
            logManager.addNewTransaction(this->currentIban, ammount, ibanOther);
        } else {
            throw MovementError("Il movimento è maggiore del valore del conto");
        }
    } else if (type == 'o') {
        float ammountAccount = allAccount.find(ibanOther)->second->getAmmount();
        if (ammountAccount >= ammount) {
            allAccount.find(this->currentIban)->second->setAmmount(
                    allAccount.find(this->currentIban)->second->getAmmount() + ammount);
            allAccount.find(ibanOther)->second->setAmmount(allAccount.find(ibanOther)->second->getAmmount() - ammount);
            logManager.addNewTransaction(ibanOther, ammount, this->currentIban);

        } else {
            throw MovementError("Il movimento è maggiore del valore del conto");
        }
    } else if (type == 'v') {
        allAccount.find(this->currentIban)->second->setAmmount(
                allAccount.find(this->currentIban)->second->getAmmount() + ammount);
        logManager.addNewTransaction(this->currentIban, ammount);
    } else if (type == 'p') {
        float ammountAccount = allAccount.find(this->currentIban)->second->getAmmount();
        if (ammountAccount >= ammount) {
            allAccount.find(this->currentIban)->second->setAmmount(
                    allAccount.find(this->currentIban)->second->getAmmount() - ammount);
            logManager.addNewTransaction(this->currentIban, -ammount);
        } else {
            throw MovementError("Il movimento è maggiore del valore del conto");
        }
    }

    accountManager.updateFile(allAccount);
}



