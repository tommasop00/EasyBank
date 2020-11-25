#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


bool login(std::string &s, std::string &username, std::string &password);

int main() {
    std::ifstream iFile;
    std::cout << "Hello, World!" << std::endl;
    std::string username;
    std::string passsword;

    std::cout << "LOGIN" << std::endl;
    std::cout << "Inserisci Username ";
    std::cin >> username;
    std::cout << std::endl;
    std::cout << "Inserisci Password ";
    std::cin >> passsword;
    std::cout << std::endl;


    std::cout << "Username : " << username << std::endl;
    std::cout << "Password : " << passsword << std::endl;


    const char *fileName = "/home/tommaso/Scrivania/CLionProject/EasyBank/loginFile.txt";

    iFile.open(fileName);

    //char c = iFile.get();
    if (iFile.is_open())
        std::cout << "OPEN" << std::endl;
    else
        std::cout << "ERROR" << std::endl;


    std::string line;
    int row = 0;
    bool res = false;
    while (getline(iFile, line)) {
        std::cout << line << std::endl;
        res = login(line, username, passsword);
        if (res) {
            break;
        }
    }
    std::cout << res << std::endl;
    iFile.close();


    return 0;
}

bool login(std::string &s, std::string &username, std::string &password) {
    size_t pos = 0;
    std::string token;
    pos = s.find(' ');
    token = s.substr(0, pos);
    if (token == username) {
        std::cout << token << std::endl;
        s.erase(0, pos + 1);
        if (s == password) {
            return true;
        }
    }
    return false;


}
