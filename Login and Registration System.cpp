/*
    Login and Registration System
    Create by Ashley Mays
*/

#include <iostream>
#include "RegistrationSystem.h"


int main() {
    System sys;
    int input = -1;

    while (input != 3) {
        sys.welcome();
        std::cin >> input;
        std::cin.get();
        switch (input) {
        case 1:
            sys.login();
            std::cin.get();
            break;
        case 2:
            sys.signUp();
            std::cin.get();
            break;
        case 3:
            break;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again." << std::endl << std::endl;
        }
    }

    std::cout << std::endl << "Thank you for using the Login and Registration System!" << std::endl;
    std::cout << "Created by Ashley Mays" << std::endl;

    std::cin.get();
}