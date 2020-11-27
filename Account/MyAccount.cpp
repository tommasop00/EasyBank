//
// Created by tommaso on 26/11/20.
//

#include "MyAccount.h"


int MyAccount::getId() const {
    return id;
}

void MyAccount::setId(int id) {
    MyAccount::id = id;
}

int MyAccount::getAmmount() const {
    return ammount;
}

void MyAccount::setAmmount(int ammount) {
    MyAccount::ammount = ammount;
}

const std::string &MyAccount::getUsername() const {
    return username;
}

void MyAccount::setUsername(const std::string &username) {
    MyAccount::username = username;
}

std::unique_ptr<std::vector<std::string>> MyAccount::findIbans() const {
    const char *fileName = "/home/tommaso/Scrivania/CLionProject/EasyBank/Account/accountFile.txt";
    std::ifstream iFile(fileName);
    if (iFile.is_open()) {
        std::string sLine;
        std::vector<std::vector<std::string>> ibans;
        bool find = false;
        std::vector<std::string> splitArray;
        while (getline(iFile, sLine)) {
            splitArray = spit(sLine, ' ');
            if (std::stoi(splitArray[0]) == id) {
                find = true;
                ibans.push_back(splitArray);
            }
        }
        if (find) {
            /*std::vector<std::vector<std::string>>::iterator it;
            for (it = ibans.begin(); it != ibans.end() ; it++){
                std::cout << (*it)[0] << std::endl;
                if((*it).capacity() == 6){
                    std::cout << (*it)[5] << " Nome"  << std::endl;

                }
            }*/
        } else {
            throw std::runtime_error("Non trovato alcuna riga");
        }

    } else
        throw std::runtime_error("Errore , file non aperto");


    return std::unique_ptr<std::vector<std::string>>();
}








