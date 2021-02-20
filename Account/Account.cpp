//
// Created by tommaso on 26/11/20.
//

#include "Account.h"
#include <memory>

const std::string Account::generateNewIban() {
    FileManager fileManager("./fileTXT/accountFile.txt");
    auto lines = fileManager.getRowFile();
    std::string line = lines[lines.size() - 1];
    auto lineSplit = split(line, ' ');
    auto ibanSplit = split(lineSplit[1], 'A');//Splitta l'iban in modo da separare il codice conto
    std::string cod = std::to_string(std::stoi(ibanSplit[1]) + 1);
    for (int i = cod.size(); i < 4; i++) {
        cod = "0" + cod;
    }

    std::string ibanReturn = "IT00A" + cod;
    return ibanReturn;

}

std::string Account::print() const {
    return iban + " " + std::to_string(ammount) + " " + fc + " " + nameProprietary;
}


