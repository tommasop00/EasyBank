#include <iostream>
#include <string>
#include <vector>
#include "Account/MyAccount.h"


bool login(const std::vector<std::string> &s, const std::string &username, const std::string &password);

int main() {


    std::string username;
    std::string passsword;

    std::cout << "LOGIN" << std::endl;

    const char *fileName = "/home/tommaso/Scrivania/CLionProject/EasyBank/loginFile.txt";

    std::ifstream iFile(fileName);

    //char c = iFile.get();
    if (iFile.is_open()){

        bool res = false;
        while(!res) {
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
                array = spit(line, ' ');
                res = login(array, username, passsword);
                if (res) {
                    break;
                }
            }

            if (res) {
                /*   HERE if all is ok */
                MyAccount account(username, count);
                std::cout << "Benvenuto " << username << std::endl;
                array.push_back(std::to_string(count));

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


