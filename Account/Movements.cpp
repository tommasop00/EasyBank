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


void Movements::makeMovement(float amount, char type, std::string ibanOther) {
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
        float amountAccount = allAccount.find(this->currentIban)->second->getAmount();
        if (amountAccount >= amount) {
            allAccount.find(this->currentIban)->second->setAmount(
                    allAccount.find(this->currentIban)->second->getAmount() - amount);
            allAccount.find(ibanOther)->second->setAmount(allAccount.find(ibanOther)->second->getAmount() + amount);
            logManager.addNewTransaction(this->currentIban, amount, ibanOther);
        } else {
            throw MovementError("Il movimento è maggiore del valore del conto");
        }
    } else if (type == 'o') {
        float amountAccount = allAccount.find(ibanOther)->second->getAmount();
        if (amountAccount >= amount) {
            allAccount.find(this->currentIban)->second->setAmount(
                    allAccount.find(this->currentIban)->second->getAmount() + amount);
            allAccount.find(ibanOther)->second->setAmount(allAccount.find(ibanOther)->second->getAmount() - amount);
            logManager.addNewTransaction(ibanOther, amount, this->currentIban);

        } else {
            throw MovementError("Il movimento è maggiore del valore del conto");
        }
    } else if (type == 'v') {
        allAccount.find(this->currentIban)->second->setAmount(
                allAccount.find(this->currentIban)->second->getAmount() + amount);
        logManager.addNewTransaction(this->currentIban, amount);
    } else if (type == 'p') {
        float amountAccount = allAccount.find(this->currentIban)->second->getAmount();
        if (amountAccount >= amount) {
            allAccount.find(this->currentIban)->second->setAmount(
                    allAccount.find(this->currentIban)->second->getAmount() - amount);
            logManager.addNewTransaction(this->currentIban, -amount);
        } else {
            throw MovementError("Il movimento è maggiore del valore del conto");
        }
    }

    accountManager.updateFile(allAccount);
}



