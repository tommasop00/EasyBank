#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


bool login(std::string &s, std::string &username, std::string &password);

int main() {


    std::string username;
    std::string passsword;

    std::cout << "LOGIN" << std::endl;

    const char *fileName = "/home/tommaso/CLionProjects/EasyBank/loginFile.txt";

    std::ifstream iFile(fileName);

    //char c = iFile.get();
    if (iFile.is_open()){

        bool res = false;
        while(!res){

            std::cout << "Inserisci Username ";
            std::cin >> username;
            std::cout << std::endl;
            std::cout << "Inserisci Password ";
            std::cin >> passsword;
            std::cout << std::endl;

            std::string line;
            while (getline(iFile, line)) {
                res = login(line, username, passsword);
                if (res) {
                    break;
                }
            }

            if(res) {
                std::cout << "Benvenuto " << username << std::endl;
                iFile.close();
            }else{
                std::cout << "Credenziali Errate" << std::endl;
                iFile.clear();
                iFile.seekg(0,std::ios::beg);
            }

        }
    }else
        std::cout << "ERROR" << std::endl;





    return 0;
}

bool login(std::string &s, std::string &username, std::string &password) {
    size_t pos = 0;
    std::string token;
    pos = s.find(' ');
    token = s.substr(0, pos);
    if (token == username) {
        s.erase(0, pos + 1);
        if (s == password) {
            return true;
        }
    }
    return false;
}
