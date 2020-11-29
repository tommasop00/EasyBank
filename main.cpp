#include <iostream>
#include "Account/MyAccount.h"


bool login(const std::vector<std::string> &s, const std::string &username, const std::string &password);

void chooseAccount(MyAccount &personalAccount);

int main() {


    std::string username;
    std::string passsword;

    std::cout << "LOGIN" << std::endl;

    const char *fileName = "/home/tommaso/Scrivania/CLionProject/EasyBank/fileTXT/loginFile.txt";

    //std::ifstream iFile(fileName);
    std::fstream iFile(fileName, std::ios::in);

    //char c = iFile.get();
    if (iFile.is_open()) {

        bool res = false;
        while (!res) {
            std::cout << "Inserisci Username ";
            std::cin >> username;
            std::cout << std::endl;
            std::cout << "Inserisci Password ";
            std::cin >> passsword;
            std::cout << std::endl;

            std::string line;
            std::vector<std::string> array;

            int count = 0;
            while (getline(iFile, line)) { //getLine <string> function
                count++;
                array = split(line, ' ');
                res = login(array, username, passsword);
                if (res) {
                    break;
                }
            }

            if (res) {
                /*   HERE if all is ok */
                MyAccount personalAccount(username, count);
                std::cout << "Benvenuto " << username << std::endl;
                chooseAccount(personalAccount);


                std::cout << "Sei Entrato con il conto di " << personalAccount.getIbans().find(
                        personalAccount.getSelectedIban())->second->getSurnameBusinessName();
                iFile.close();
            }else{
                std::cout << "Credenziali Errate" << std::endl;
                iFile.clear();
                iFile.seekg(0,std::ios::beg);
            }
        }
    }else
        throw std::runtime_error("Errore , file non aperto");





    return 0;
}

bool login(const std::vector<std::string> &s, const std::string &username, const std::string &password) {
    if (s[1] == username) {
        if (s[2] == password) {
            return true;
        }
    }
    return false;
}

void chooseAccount(MyAccount &personalAccount) {
    std::cout << "Scegli quale iban utilizzare : " << std::endl;

    std::map<int, std::string> IdIban;
    int count = 1;
    for (const auto &iban : personalAccount.getIbans()) {
        std::cout << "Digita " << count << " per selezionare il Conto di " << iban.second->getSurnameBusinessName()
                  << " Iban : " << iban.first << std::endl;
        IdIban.insert(std::make_pair(count++, iban.first));
    }
    int valSelected;
    std::cin >> valSelected;
    personalAccount.setSelectedIban(IdIban[valSelected]);
    int t;


}


