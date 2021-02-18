//
// Created by tommaso on 29/11/20.
//

#include "Transaction.h"

void Transition::detach() {
    sub->removeObserver(this);
}


void Transition::attach() {
    sub->addObserver(this);
}

void Transition::update(float ammount, std::string ibanOther) {
    const char *path1 = "./fileTXT/accountFile.txt";
    const char *path2 = "./fileTXT/accountFile2.txt";
    const char *path3 = "./fileTXT/accountFile3.txt";
    const char *pathlog = "./fileTXT/log.txt";

    FileManager fileManager(path1);
    FileManager fileManagerLog(pathlog, "a+");
    FileManager fileManager2(path2, "a");

    std::vector<std::string> arraySplit;
    std::string log;
    if (checkifIbanOtherExist(fileManager, ibanOther)) {
        //region extern
        if (ibanOther != this->acc->getIban()) {
            if (ammount < 0) {
                ammount = std::fabs(ammount);
                for (auto line : fileManager.getRowFile()) {
                    arraySplit = split(line, ' ', 4);
                    if (arraySplit[1] == this->acc->getIban()) {
                        float t = std::stof(arraySplit[2]);
                        if (t > ammount) {
                            std::string tempIban = this->acc->getIban();
                            this->doTransferExtern(fileManager, fileManager2, tempIban, ibanOther, ammount);
                            log = this->acc->getIban() + " >> " + std::to_string(ammount) + " >> " + ibanOther;
                            fileManagerLog.write(log);
                        } else {
                            if (remove(path2) != 0) {
                                throw std::runtime_error("Errore nella cancellazione");
                            }
                            throw TransactionError("Il bonifico è maggiore del valore del conto");
                        }

                        break;
                    }
                }
            } else if (ammount > 0) {
                for (auto line : fileManager.getRowFile()) {
                    arraySplit = split(line, ' ', 4);
                    if (arraySplit[1] == ibanOther) {
                        float t = std::stof(arraySplit[2]);
                        if (t > ammount) {
                            std::string tempIban = this->acc->getIban();
                            this->doTransferExtern(fileManager, fileManager2, ibanOther, tempIban, ammount);
                            log = this->acc->getIban() + " << " + std::to_string(ammount) + " << " + ibanOther;
                            fileManagerLog.write(log);
                        } else {
                            if (remove(path2) != 0) {
                                throw std::runtime_error("Errore nella cancellazione");
                            }
                            throw TransactionError("Il prelievo è maggiore del valore del conto");
                        }

                        break;
                    }
                }
            } else {
                if (remove(path2) != 0) {
                    throw std::runtime_error("Errore nella cancellazione");
                }
                throw TransactionError("Non è possibile fare un tranferimento pari a 0");
            }
        }
            //endregion
            //region intern
        else {
            if (ammount < 0) {
                float absAmmount = std::fabs(ammount);;
                for (auto line : fileManager.getRowFile()) {
                    arraySplit = split(line, ' ', 4);
                    if (arraySplit[1] == this->acc->getIban()) {
                        float t = std::stof(arraySplit[2]);
                        if (t > absAmmount) {
                            this->doTransferIntern(fileManager, fileManager2, ammount);
                            log = this->acc->getIban() + " >> " + std::to_string(absAmmount);
                            fileManagerLog.write(log);
                        } else {
                            if (remove(path2) != 0) {
                                throw std::runtime_error("Errore nella cancellazione");
                            }
                            throw TransactionError("Il bonifico è maggiore del valore del conto");
                        }

                        break;
                    }
                }

            } else if (ammount > 0) {
                doTransferIntern(fileManager, fileManager2, ammount);
                log = this->acc->getIban() + " << " + std::to_string(ammount);
                fileManagerLog.write(log);
            } else {
                if (remove(path2) != 0) {
                    throw std::runtime_error("Errore nella cancellazione");
                }
                throw TransactionError("Non è possibile fare un tranferimento pari a 0");
            }
        }
        //endregion
        if (rename(path1, path3) != 0) {
            throw std::runtime_error("Errore nel rinomina");
        }
        if (rename(path2, path1) != 0) {
            throw std::runtime_error("Errore nel rinomina");
        }
        if (remove(path3) != 0) {
            throw std::runtime_error("Errore nella cancellazione");
        }
    } else {
        throw TransactionError("Iban non esistente");
    }


}


void Transition::update2() {
    this->acc = this->sub->getIbans().find(this->sub->getSelectedIban())->second.get();
}


bool Transition::checkifIbanOtherExist(FileManager &fileOriginal, std::string &iban) {
    std::vector<std::string> arraySplit;
    for (auto line : fileOriginal.getRowFile()) {
        arraySplit = split(line, ' ', 4);
        if (arraySplit[1] == iban) {
            return true;
        }
    }
    return false;
}

void
Transition::doTransferExtern(FileManager &fileOriginal, FileManager &fileUpdate, std::string &iban1, std::string &iban2,
                             float ammount) {
    std::vector<std::string> arraySplit;
    std::vector<std::string> rowFile = fileOriginal.getRowFile();
    std::string copyline;
    std::string s;
    bool first = false;
    for (auto line : rowFile) {
        copyline = line;
        arraySplit = split(line, ' ', 4);
        float temp = std::stof(arraySplit[2]);
        if (arraySplit[1] == iban2) {
            s = arraySplit[0] + " " + arraySplit[1] + " " + std::to_string(temp + ammount) + " " + arraySplit[3];
        } else if (arraySplit[1] == iban1) {
            s = arraySplit[0] + " " + arraySplit[1] + " " + std::to_string(temp - ammount) + " " + arraySplit[3];
        } else {
            s = copyline;
        }

        if (first == false) {
            fileUpdate.write(s, true);
            first = true;
        } else {
            fileUpdate.write(s);

        }
    }

}

void Transition::doTransferIntern(FileManager &fileOriginal, FileManager &fileUpdate, float ammount) {
    std::vector<std::string> arraySplit;
    std::vector<std::string> rowFile = fileOriginal.getRowFile();
    std::string copyline;
    std::string s;
    bool first = false;
    for (auto line : rowFile) {
        copyline = line;
        arraySplit = split(line, ' ', 4);
        float temp = std::stof(arraySplit[2]);
        if (arraySplit[1] == this->acc->getIban()) {
            s = arraySplit[0] + " " + arraySplit[1] + " " + std::to_string(temp + ammount) + " " + arraySplit[3];
        } else {
            s = copyline;
        }

        if (first == false) {
            fileUpdate.write(s, true);
            first = true;
        } else {
            fileUpdate.write(s);

        }
    }
}



