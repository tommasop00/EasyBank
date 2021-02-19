//
// Created by tommaso on 26/11/20.
//

#include "User.h"
#include "TransactionError.h"
#include <iostream>
#include <memory>


const std::map<std::string, std::unique_ptr<Account>> &User::getIbans() const {
    return ibans;
}

const std::string &User::getSelectedIban() const {
    return selectedIban;
}

void User::setSelectedIban(const std::string &selectedIbanmain) {
    selectedIban = selectedIbanmain;
    this->notify2();
}

std::map<std::string, std::unique_ptr<Account>> User::findIbans() const {
    const char *fileName = "./fileTXT/accountFile.txt";
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
                count++;
                if (std::stoi(splitArray[0]) == this->user.second) {
                    float ammount = std::stof(splitArray[2]);
                    std::unique_ptr<Account> tempAccount(
                            new Account(ammount, splitArray[3], splitArray[4], count, splitArray[1]));
                    find = true;
                    ibans.insert(std::make_pair(splitArray[1], std::move(tempAccount)));
                }
            }
        }
        if (find) {
            return ibans;
        }

    } else {
        //file.close();
        throw std::runtime_error("Errore , file non aperto");
    }
    return std::map<std::string, std::unique_ptr<Account>>();


}

void User::notify(std::string iban, float ammount) { //TODO upgrade accountOBJ
    for (auto itr : this->getObservers()) {
        itr->update(ammount, iban);
    }
    std::cout << "OK" << std::endl;
}


void User::notify2() {
    for (auto itr : this->getObservers()) {
        itr->update2();
    }
}

void User::addObserver(Observer *ob) {
    observers.push_back(ob);
}

void User::removeObserver(Observer *ob) {
    observers.remove(ob);
}

void User::clearObserver() {
    observers.clear();
}

const std::list<Observer *> &User::getObservers() const {
    return observers;
}

/*void User::chooseAccount() {
    std::cout << "Scegli quale iban utilizzare : " << std::endl;
    std::map<int, std::string> IdIban;
    int count = 1;
    for (const auto &iban : this->getIbans()) {
        std::cout << "Digita " << count << " per selezionare il Conto di " << iban.second->getSurnameBusinessName()
                  << " Iban : " << iban.first << std::endl;
        IdIban.insert(std::make_pair(count++, iban.first));
    }
    if (count == 1) {
        std::cout << "Nessun Conto Presente per questo Account" << std::endl;
        std::cout << "Crea un nuovo Conto" << std::endl;

        createNewCurrentAccount();
    } else {
        std::cout << "Digita 0 per creare un nuovo Conto" << std::endl;
        int valSelected;
        do {
            std::cin >> valSelected;
            if (valSelected == 0) {
                this->createNewCurrentAccount();
            } else if (this->getIbans().size() >= valSelected && valSelected > 0) {
                this->setSelectedIban(IdIban[(valSelected)]);
                std::cout << "Sei Entrato con il conto di " << this->getIbans().find(
                        this->getSelectedIban())->second->getSurnameBusinessName() << std::endl;
            } else {
                std::cout << "Carattere non valido, inserire un valore valido" << std::endl;
            }
        } while (valSelected < 0 || valSelected > this->getSelectedIban().size());
    }
}*/

/*void User::createNewCurrentAccount() {
    bool correctValue = false;
    while (!correctValue) {
        std::string ammount, fc, name;
        std::cout << "Inserisca valore conto iniziale" << std::endl;
        std::cin >> ammount;
        std::cout << "Inserisca il suo codice fiscale" << std::endl;
        std::cin >> fc;
        std::cout << "Inserisca il suo nome" << std::endl;
        std::cin >> name;
        float ammountFloat;
        try {
            ammountFloat = std::stof(ammount);
            if (ammountFloat != 0) {
                correctValue = true;
                std::unique_ptr<Account> a(new Account(ammountFloat, fc, name, this->user.second));
                this->selectedIban = a->getIban();
                this->ibans.insert(std::make_pair(a->getIban(), std::move(a)));
                this->notify2();

            } else {
                correctValue = false;
                std::cout << "Valori non validi" << std::endl;
            }

        } catch (std::invalid_argument &e) {
            std::cerr << "caratteri non validi" << std::endl;
            correctValue = false;

        }

    }


}*/

void User::getAmount() const {
    FileManager fileManager("./fileTXT/accountFile.txt");

    std::vector<std::string> arraySplit;
    for (auto line : fileManager.getRowFile()) {
        arraySplit = split(line, ' ', 4);
        if (arraySplit[1] == this->getSelectedIban()) {
            std::cout << "Il saldo è di € " << this->getIbans().find(
                    this->getSelectedIban())->second->getAmmount() << std::endl;
            break;
        }
    }
}

const std::pair<std::string, int> &User::getUser() const {
    return user;
}

void User::pushIban(std::unique_ptr<Account> a) {
    ibans.insert(std::make_pair(a->getIban(), std::move(a)));
    this->notify2();
}

















