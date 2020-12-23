//
// Created by tommaso on 26/11/20.
//

#include "Account.h"
#include <memory>
#include <iostream>

const std::string Account::generateNewIban() {
    std::unique_ptr<FileManager> fileManager;
    try {
        fileManager = std::move(std::unique_ptr<FileManager>(
                new FileManager("/home/tommaso/Scrivania/CLionProject/EasyBank/fileTXT/accountFile.txt")));
        auto lines = fileManager->getRowFile();
        int count = 0;
        std::string line = "";
        while (lines[count] != "") {
            line = lines[count];
            count++;
        }
        std::cout << "line " << line << std::endl;
        auto lineSplit = split(line, ' ');
        auto ibanSplit = split(lineSplit[1], 'A');//Splitta l'iban in modo da separare il codice conto
        std::string cod = std::to_string(std::stoi(ibanSplit[1]) + 1);
        for (int i = cod.size(); i < 4; i++) {
            cod = "0" + cod;
        }

        std::string ibanReturn = "IT00A" + cod;
        return ibanReturn;
    } catch (std::runtime_error e) {
        std::cout << "Errore" << e.what() << std::endl;
    }
}
