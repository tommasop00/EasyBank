//
// Created by tommaso on 26/11/20.
//

#include "MyAccount.h"
#include "../FileManager.h"
#include <iostream>


const std::map<std::string, std::unique_ptr<Account>> &MyAccount::getIbans() const {
    return ibans;
}

const std::string &MyAccount::getSelectedIban() const {
    return selectedIban;
}

void MyAccount::setSelectedIban(const std::string &selectedIban) {
    MyAccount::selectedIban = selectedIban;
}

std::map<std::string, std::unique_ptr<Account>> MyAccount::findIbans() const {
    const char *fileName = "/home/tommaso/Scrivania/CLionProject/EasyBank/fileTXT/accountFile.txt";
    FileManager file(fileName);
    if (file.is_open()) {
        std::string sLine;
        std::map<std::string, std::unique_ptr<Account>> ibans;
        bool find = false;
        std::vector<std::string> splitArray;
        int count = 0;
        for (auto sLine : file.getRowFile()) {
            if (sLine != "") {
                splitArray = split(sLine, ' ', 5);
                std::unique_ptr<Account> tempAccount(
                        new Account(count++, splitArray[1], std::stof(splitArray[2]), splitArray[3],
                                    splitArray[4]));
                if (std::stoi(splitArray[0]) == this->user.second) {
                    find = true;
                    ibans.insert(std::make_pair(splitArray[1], std::move(tempAccount)));
                } else {

                }
            }
        }
        if (find) {
            //file.close();
            return ibans;
        }

    } else {
        //file.close();
        throw std::runtime_error("Errore , file non aperto");
    }


}

void MyAccount::notify() {

}

void MyAccount::addObserver(Observer *ob) {
    observers.push_back(ob);
}

void MyAccount::removeObserver(Observer *ob) {
    observers.remove(ob);
}

void MyAccount::clearObserver() {
    observers.clear();
}

const std::list<Observer *> &MyAccount::getObservers() const {
    return observers;
}

void MyAccount::choosAccount() {
    std::cout << "Scegli quale _iban utilizzare : " << std::endl;

    std::map<int, std::string> IdIban;
    int count = 1;
    for (const auto &iban : getIbans()) {
        std::cout << "Digita " << count << " per selezionare il Conto di " << iban.second->getSurnameBusinessName()
                  << " Iban : " << iban.first << std::endl;
        IdIban.insert(std::make_pair(count++, iban.first));
    }
    int valSelected;
    std::cin >> valSelected;
    selectedIban = (IdIban[valSelected]);
}

void MyAccount::createNewCurrentAccount() {
    std::cout << "Inserisci ";

}













