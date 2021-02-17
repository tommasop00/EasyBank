#include <iostream>
#include "Account/MyAccount.h"
#include "FileManager.h"
#include "Account/Transaction.h"
#include "Account/TransactionError.h"


bool login(const std::vector<std::string> &s, const std::string &username, const std::string &password);

char presentMenu(char liv);

void doTransfer(MyAccount &pa, char type);

int main() {

    std::string username;
    std::string passsword;

    std::cout << "LOGIN" << std::endl;

    FileManager fileManager("./fileTXT/loginFile.txt");
    if (fileManager.is_open()) {
        char input;
        int count;
        std::unique_ptr<MyAccount> personalAccount;
        std::unique_ptr<Transition> observerAccount;

        bool res = false;
        std::vector<std::string> arraySplit;

        while (input != 'e') {
            while (!res && input != 'e') {
                input = presentMenu(1);
                arraySplit.clear();
                switch (input) {
                    case 'l':
                        while (!res) {
                            count = 0;
                            std::cout << "Inserisci Username o digita e per uscire dal login ";
                            std::cin >> username;
                            if (username == "e") {
                                break;
                            }
                            std::cout << std::endl;
                            std::cout << "Inserisci Password ";
                            std::cin >> passsword;
                            std::cout << std::endl;

                            for (auto line : fileManager.getRowFile()) {
                                count++;
                                arraySplit = split(line, ' ');
                                res = login(arraySplit, username, passsword);
                                if (res) {
                                    break;
                                }
                            }
                            if (res) {
                                personalAccount = std::unique_ptr<MyAccount>(new MyAccount(username, count));
                                observerAccount = std::unique_ptr<Transition>(new Transition(personalAccount.get()));
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
                        for (auto line : fileManager.getRowFile()) { //getLine <string> function
                            arraySplit = split(line, ' ');
                            if (arraySplit[0] == username) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {

                            std::cout << std::endl;
                            std::cout << "Inserisci nuova Password ";
                            std::cin >> passsword;
                            std::cout << std::endl;
                            std::string tempString = username + " " + passsword;
                            fileManager.write(tempString);
                        } else {
                            std::cerr << "Username già usato, verrai rimandato al menù principale" << std::endl
                                      << std::endl;
                        }

                        break;
                }

            }
            input = (input != 'e') ? ' ' : input;
            if (input != 'e') {
                personalAccount->chooseAccount();
                while (input != 'e') {
                    input = presentMenu(2);
                    switch (input) {
                        case 'l':
                            personalAccount->chooseAccount();
                            break;
                        case 'c':
                            personalAccount->createNewCurrentAccount();
                            break;
                        case 'b':
                            try {
                                doTransfer(*personalAccount.get(), input);
                            } catch (TransactionError &e) {
                                std::cerr << e.what() << std::endl;
                            }
                            catch (std::invalid_argument &e) {
                                std::cerr << "Valore inserito errat" << std::endl;
                            }
                            break;
                        case 'o':
                            try {
                                doTransfer(*personalAccount.get(), input);
                            } catch (TransactionError &e) {
                                std::cerr << e.what() << std::endl;
                            }
                            catch (std::invalid_argument &e) {
                                std::cerr << "Valore inserito errat" << std::endl;
                            }
                            break;
                        case 'p':
                            try {
                                doTransfer(*personalAccount.get(), input);
                            } catch (TransactionError &e) {
                                std::cerr << e.what() << std::endl;
                            }
                            catch (std::invalid_argument &e) {
                                std::cerr << "Valore inserito errat" << std::endl;
                            }
                            break;
                        case 'v':
                            try {
                                doTransfer(*personalAccount.get(), input);
                            } catch (TransactionError &e) {
                                std::cerr << e.what() << std::endl;
                            }
                            catch (std::invalid_argument &e) {
                                std::cerr << "Valore inserito errato" << std::endl;
                            }
                            break;
                        case 'm':
                                std::cout << "Il saldo è di € " << personalAccount->getIbans().find(
                                        personalAccount->getSelectedIban())->second->getAmmount() << std::endl;
                            break;
                        case 'e':
                            break;

                    }
                }
            }
            if (input == 'e') {
                std::cout << "Sei Uscito";
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
            std::cout << "Premi o per effettuare un prelievo in un altro conto" << std::endl;
            std::cout << "Premi v per effettuare un versamento" << std::endl;
            std::cout << "Premi p per effettuare un prelevamento" << std::endl;
            std::cout << "Premi m per informazioni sul saldo" << std::endl;
            std::cout << "Primi l per selezionare l'_iban per effettuare le operazioni" << std::endl;
            std::cout << "Premi c per creare un nuovo conto Corrente all'interno del tuo Account" << std::endl;
            std::cout << "Primi e per uscire dall'account" << std::endl;
            break;
    }

    std::cin >> input;

    return input;

}

void doTransfer(MyAccount &pa, char type) {
    std::string ibanOther;
    std::string temp;
    float ammount;
    std::cout << "Inserire valore movimento" << std::endl;
    std::cin >> temp;
    ammount = std::stof(temp);

    if (type == 'b' || type == 'o') {
        std::cout << "Inserire iban con cui fare il movimento" << std::endl;
        std::cin >> ibanOther;

    } else if (type == 'v' || type == 'p') {
        ibanOther = pa.getSelectedIban();
    }
    if (type == 'b' || type == 'p') {
        ammount = -ammount;
    }
    pa.notify(ibanOther, ammount);

}





