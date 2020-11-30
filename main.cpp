#include <iostream>
#include "Account/MyAccount.h"


bool login(const std::vector<std::string> &s, const std::string &username, const std::string &password);

void chooseAccount(MyAccount *personalAccount);

char presentMenu(const char liv);

int main() {


    std::string username;
    std::string passsword;

    std::cout << "LOGIN" << std::endl;

    const char *fileName = "/home/tommaso/Scrivania/CLionProject/EasyBank/fileTXT/loginFile.txt";

    //std::ifstream iFile(fileName);
    std::fstream iFile(fileName, std::ios::in | std::ios::app);

    //char c = iFile.get();
    if (iFile.is_open()) {
        char input;
        int count;
        MyAccount *personalAccount;
        bool res = false;
        std::string line;
        std::vector<std::string> arraySplit;

        while (input != 'e') {
            while (!res && input != 'e') {
                count = 0;
                input = presentMenu(1);
                arraySplit.clear();
                switch (input) {
                    case 'l':
                        while (!res) {
                            std::cout << "Inserisci Username o digita e per uscire dal login ";
                            std::cin >> username;
                            if (username == "e") {
                                break;
                            }
                            std::cout << std::endl;
                            std::cout << "Inserisci Password ";
                            std::cin >> passsword;
                            std::cout << std::endl;


                            while (getline(iFile, line)) { //getLine <string> function
                                count++;
                                arraySplit = split(line, ' ');
                                res = login(arraySplit, username, passsword);
                                if (res) {
                                    break;
                                }
                            }
                            if (res) {
                                personalAccount = std::move(new MyAccount(username, count));
                                std::cout << "Benvenuto " << username << std::endl;
                            } else {
                                std::cout << "Credenziali Errate" << std::endl;

                            }
                        }
                        break;
                    case 's':
                        std::cout << "Inserisci nuovo Username o digita e per uscire dal login ";
                        std::cin >> username;
                        if (username == "e") {
                            break;
                        }
                        bool found = false;
/*                        while (getline(iFile, line)) { //getLine <string> function
                            count++;
                            arraySplit = split(line, ' ');
                            if (arraySplit[0] ==  username){
                                found = true;
                                break;
                            }
                        }*/
                        if (!found) {
                            std::cout << std::endl;
                            std::cout << "Inserisci nuova Password ";
                            std::cin >> passsword;
                            std::cout << std::endl;
                            iFile << username << " " << passsword << std::endl;
                        } else {
                            std::cout << "Username già usato, verrai rimandato al menù principale" << std::endl
                                      << std::endl;
                            iFile.clear();
                            iFile.seekg(0, std::ios::beg);
                        }

                        break;
                }
            }
            input = (input != 'e') ? ' ' : input;

            while (input != 'e') {

                if (res) {

                    chooseAccount(personalAccount);
                    std::cout << "Sei Entrato con il conto di " << personalAccount->getIbans().find(
                            personalAccount->getSelectedIban())->second->getSurnameBusinessName() << std::endl;


                    while (input != 'e') {
                        input = presentMenu(1);
                    }
                    if (input == 'e') {
                        std::cout << "Sei Uscito";
                    }

                    iFile.close();
                }
            }
        }
    }else
        throw std::runtime_error("Errore , file non aperto");





    return 0;
}

bool login(const std::vector<std::string> &s, const std::string &username, const std::string &password) {
    if (s[0] == username) {
        if (s[1] == password) {
            return true;
        }
    }
    return false;
}

void chooseAccount(MyAccount *personalAccount) {
    std::cout << "Scegli quale iban utilizzare : " << std::endl;
    std::map<int, std::string> IdIban;
    int count = 1;
    for (const auto &iban : personalAccount->getIbans()) {
        std::cout << "Digita " << count << " per selezionare il Conto di " << iban.second->getSurnameBusinessName()
                  << " Iban : " << iban.first << std::endl;
        IdIban.insert(std::make_pair(count++, iban.first));
    }
    int valSelected;
    std::cin >> valSelected;
    personalAccount->setSelectedIban(IdIban[valSelected]);

}

char presentMenu(const char liv) {

    char input;

    switch (liv) {
        case 1:
            std::cout << "Primi l per eleguire il login" << std::endl;
            std::cout << "Premi s per registratre un nuovo profilo" << std::endl;
            std::cout << "Primi e per chiudere l'applicazione" << std::endl;
            break;
        case 2:
            std::cout << "Premi b per effettuare un bonifico" << std::endl;
            std::cout << "Primi l per selezionare l'iban per effettuare le operazioni" << std::endl;
            std::cout << "Premi c per creare un nuovo conto Corrente all'interno del tuo Account" << std::endl;
            std::cout << "Primi e per uscire dall'account" << std::endl;
            break;
    }

    std::cin >> input;

    return input;

}

bool makeATransfer(MyAccount &personalAccount) {
    return true;
}




