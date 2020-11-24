#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int main() {
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


    std::ifstream iFile("./fileTXT/login.txt");


    return 0;
}
