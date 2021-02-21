#include <iostream>
#include "Account/User.h"
#include "FileManager/FileManager.h"
#include "Account/Movements.h"
#include "Account/MovementError.h"
#include "FileManager/UserFileManager.h"
#include "FileManager/LogFileManager.h"


bool login(const std::vector<std::string> &s, const std::string &username, const std::string &password);

char presentMenu(char liv);

void doTransfer(User *pa, Movements *movementObj, char type);

void createNewCurrentAccount(User *userAccount, Movements *movements);

void chooseAccount(User *userAccount, Movements *movements);


int main() {

    std::string username;
    std::string passsword;

    std::cout << "LOGIN" << std::endl;

    try {
        UserFileManager fileManager("./fileTXT/loginFile.txt");
        if (fileManager.is_open()) {
            char input;
            int count;
            std::unique_ptr<User> userAccount;
            std::unique_ptr<Movements> movementObj;

            int res = 0;
            std::vector<std::string> arraySplit;

            while (input != 'e') {
                while (res == 0 && input != 'e') {
                    input = presentMenu(1);
                    arraySplit.clear();
                    switch (input) {
                        case 'l':
                            while (res == 0) {
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

                                res = fileManager.login(username, passsword); //se ok ritorna id sennò 0
                                if (res != 0) {
                                    userAccount = std::unique_ptr<User>(new User(username, res));
                                    movementObj = std::unique_ptr<Movements>(
                                            new Movements(userAccount.get()));
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
                            bool found = fileManager.findUsername(username);
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
                    chooseAccount(userAccount.get(), movementObj.get());
                    while (input != 'e') {
                        input = presentMenu(2);
                        switch (input) {
                            case 'l':
                                chooseAccount(userAccount.get(), movementObj.get());
                                break;
                            case 'c':
                                createNewCurrentAccount(userAccount.get(), movementObj.get());
                                break;
                            case 'b':
                            case 'o':
                            case 'p':
                            case 'v':
                                try {
                                    doTransfer(userAccount.get(), movementObj.get(), input);
                                } catch (MovementError &e) {
                                    std::cerr << e.what() << std::endl;
                                }
                                catch (std::invalid_argument &e) {
                                    std::cerr << "Valore inserito errati" << std::endl;
                                }

                                break;
                            case 't':
                                try {
                                    LogFileManager logManager("./fileTXT/log.txt");
                                    auto allLog = logManager.getallTransiction(userAccount->getSelectedIban());
                                    for (const auto &log : allLog) {
                                        std::cout << log->print() << std::endl;
                                    }
                                } catch (std::runtime_error &e) {
                                    std::cerr << e.what() << std::endl;
                                }
                                break;
                            case 'm':
                                std::cout << "IL saldo è di € " + std::to_string(userAccount->getAmount()) << std::endl;
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
        } else
            throw std::runtime_error("Errore , file non aperto");
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }





    return 0;
}

void chooseAccount(User *userAccount, Movements *movements) {
    auto &ibans = userAccount->getIbans();
    int count = 1;
    std::map<int, std::string> IdIban;

    if (ibans.size() > 0) {
        std::cout << "Scegli quale iban utilizzare : " << std::endl;
        for (const auto &iban : ibans) {
            std::cout << "Digita " << count << " per selezionare il Conto di "
                      << iban.second->getSurnameBusinessName()
                      << " Iban : " << iban.first << std::endl;
            IdIban.insert(std::make_pair(count++, iban.first));
        }
        std::cout << "Digita 0 per creare un nuovo Conto" << std::endl;
        int valSelected;
        do {
            std::cin >> valSelected;
            if (valSelected == 0) {
                createNewCurrentAccount(userAccount, movements);
            } else if (ibans.size() >= valSelected && valSelected > 0) {
                userAccount->setSelectedIban(IdIban[(valSelected)]);
                std::cout << "Sei Entrato con il conto di " << userAccount->getIbans().find(
                        userAccount->getSelectedIban())->second->getSurnameBusinessName() << std::endl;
            } else {
                std::cout << "Carattere non valido, inserire un valore valido" << std::endl;
            }
        } while (valSelected < 0 || valSelected > userAccount->getSelectedIban().size());

    } else {
        std::cout << "Nessun Conto Presente per questo Account" << std::endl;
        std::cout << "Crea un nuovo Conto" << std::endl;
        createNewCurrentAccount(userAccount, movements);
    }
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
            std::cout << "Premi t per informazioni sui propri movimenti" << std::endl;
            std::cout << "Primi l per selezionare l'iban per effettuare le operazioni" << std::endl;
            std::cout << "Premi c per creare un nuovo conto Corrente all'interno del tuo Account" << std::endl;
            std::cout << "Primi e per uscire dall'account" << std::endl;
            break;
    }

    std::cin >> input;

    return input;

}

void doTransfer(User *pa, Movements *movementObj, char type) {
    std::string ibanOther;
    std::string temp;
    float ammount;
    std::cout << "Inserire valore movimento" << std::endl;
    std::cin >> temp;
    ammount = std::stof(temp);

    if (type == 'b' || type == 'o') {
        std::cout << "Inserire iban con cui fare il movimento" << std::endl;
        std::cin >> ibanOther;
        movementObj->makeMovement(ammount, type, ibanOther);

    } else if (type == 'v' || type == 'p') {
        ibanOther = pa->getSelectedIban();
        movementObj->makeMovement(ammount, type);
    }
}

void createNewCurrentAccount(User *userAccount, Movements *movements) {
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
                std::unique_ptr<Account> a(new Account(ammountFloat, fc, name, userAccount->getUser().second));
                userAccount->setSelectedIban(a->getIban());
                userAccount->pushIban(std::move(a));
            } else {
                correctValue = false;
                std::cout << "Valori non validi" << std::endl;
            }

        } catch (std::invalid_argument &e) {
            std::cerr << "caratteri non validi" << std::endl;
            correctValue = false;

        }

    }


}





