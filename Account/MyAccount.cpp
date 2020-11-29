//
// Created by tommaso on 26/11/20.
//

#include "MyAccount.h"
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
    std::fstream file(fileName, std::ios::in | std::ios::app);
    if (file.is_open()) {
        std::string sLine;
        std::map<std::string, std::unique_ptr<Account>> ibans;
        bool find = false;
        std::vector<std::string> splitArray;
        while (getline(file, sLine)) {
            splitArray = split(sLine, ' ');
            if (std::stoi(splitArray[0]) == this->user.second) {
                find = true;
                std::unique_ptr<Account> tempAccount(
                        new Account(splitArray[1], std::stof(splitArray[2]), splitArray[3], splitArray[4]));
                ibans.insert(std::make_pair(splitArray[1], std::move(tempAccount)));
            }
        }
        if (find) {
/*            for (auto it = ibans.begin(); it != ibans.end() ; it++){
                std::cout << (*it)[0] << std::endl;
                if((*it).capacity() == 6){
                    std::cout << (*it)[5] << " Nome"  << std::endl;

                }
            }*/
            file.close();
            return ibans;
        } else {
            //TODO add conto
            file.close();
            throw std::runtime_error("Non trovato alcuna riga");
        }

    } else {
        file.close();
        throw std::runtime_error("Errore , file non aperto");
    }


}

void MyAccount::notify() {

}

void MyAccount::addObserver(std::unique_ptr<Observer> ob) {

}












