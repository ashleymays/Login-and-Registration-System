#include "RegistrationSystem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;


void System::welcome() {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "LOGIN AND REGISTRATION SYSTEM" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "MAIN MENU: " << std::endl;
    std::cout << "  1. Login" << std::endl;
    std::cout << "  2. Sign Up" << std::endl;
    std::cout << "  3. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your option: ";
}


void System::login() {
    std::cout << std::endl << std::endl;
    std::cout << "LOG IN :: ENTER CREDENTIALS";
    std::cout << std::endl;

    // get username and password
    loginCredentials();

    if (!isRegistered()) {
        std::cout << "There is no user with this username. Press \"Enter\" to return to the main menu.";
        std::cout << std::endl;
        return;
    }
    else if (isRegistered() && !isCorrectPassword()) {
        std::cout << "The password is incorrect. Press \"Enter\" to return to the main menu." << std::endl;
        std::cout << std::endl;
        return;
    }
    else if (isRegistered() && isCorrectPassword()) {
        std::cout << "Logged in. Press \"Enter\" to continue.";
        std::cin.get();
        accountOptions();
    }
}


void System::signUp() {
    std::cout << std::endl << std::endl;
    std::cout << "SIGN UP :: ENTER CREDENTIALS";
    std::cout << std::endl;

    // get first name, last name, username, and password
    signUpCredentials();

    // read through files in folder, make sure user doesn't have an account
    if (isRegistered()) {
        std::cout << "Username taken. Press \"Enter\" to return to the main menu.";
        std::cout << std::endl << std::endl << std::endl;
        return;
    }

    createNewUserProfile();

    std::cout << "Registered. Press \"Enter\" to continue.";
    std::cin.get();
    accountOptions();
}







void System::loginCredentials() {
    std::cout << std::endl;
    std::cout << "Username: ";
    std::getline(std::cin, m_username);
    std::cout << "Password: ";
    std::getline(std::cin, m_password);
    std::cout << std::endl;
}


void System::signUpCredentials() {
    std::cout << std::endl;
    std::cout << "First Name: ";
    std::getline(std::cin, m_firstName);
    std::cout << "Last Name: ";
    std::getline(std::cin, m_lastName);
    std::cout << "Username: ";
    std::getline(std::cin, m_username);
    std::cout << "Password: ";
    std::getline(std::cin, m_password);
    std::cout << std::endl;
}


void System::createNewUserProfile() {
    // add the user's information to a new file
    std::string fileName = "User_" + m_username + ".txt";
    std::ofstream file;
    if (!isRegistered()) {
        file.open(fileName);
        if (file.is_open()) {
            file << "First Name: " << m_firstName << std::endl;
            file << "Last Name: " << m_lastName << std::endl;
            file << "Username: " << m_username << std::endl;
            file << "Password: " << m_password << std::endl;
        }
        file.close();
    }
}







bool System::isRegistered() {
    fs::path myPath( "..\\Login and Registration System" ); // relative path
    std::string fileName = "User_" + m_username + ".txt";

    // read all files in the project folder
    for (auto& file : fs::recursive_directory_iterator(myPath)) {

        // check if a file with the username exists
        if (file.path().filename() == fileName) {
            return true;
        }
    }
    return false;
}


bool System::isCorrectPassword() {
    std::ifstream read;
    std::string fileName = "User_" + m_username + ".txt";
    std::string line;

    // check if the password in the file is the same as the one entered at login
    read.open(fileName);
    while (read.is_open() && std::getline(read, line)) {
        if (line == "Password: " + m_password) {
            return true;
        }
    }
    read.close();
    return false;
}








void System::accountOptions() {
    std::cout << std::endl << std::endl << std::endl;
    int input = -1;

    while (input != 4) {
        std::cout << std::endl;
        std::cout << "ACCOUNT OPTIONS";
        std::cout << std::endl << std::endl;
        std::cout << "  1. Read User Profile" << std::endl;
        std::cout << "  2. Reset Password" << std::endl;
        std::cout << "  3. Delete User" << std::endl;
        std::cout << "  4. Sign Out" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your option: ";
        std::cin >> input;
        std::cin.get();

        switch (input) {
        case 1:
            readFile();
            std::cout << std::endl << std::endl << std::endl;
            std::cin.get();
            break;
        case 2:
            resetPassword();
            std::cout << std::endl << std::endl << std::endl;
            std::cin.get();
            break;
            
        case 3:
            deleteUser();
            std::cout << std::endl << std::endl << std::endl;
            return;
        case 4:
            std::cout << std::endl;
            std::cout << "Signed out. Press \"Enter\" to return to the main menu.";
            std::cout << std::endl << std::endl << std::endl;
            break;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.";
            std::cout << std::endl << std::endl << std::endl;
        }
    }
}


void System::readFile() {
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "USER PROFILE";
    std::cout << std::endl << std::endl;

    std::ifstream read;
    std::string fileName = "User_" + m_username + ".txt";
    std::string line;

    read.open(fileName);
    if (read.is_open()) {
        while (std::getline(read, line)) {
            std::cout << line << std::endl;
        }
    }
    read.close();
    std::cout << std::endl;
    std::cout << "Press \"Enter\" to return to account options.";
}


void System::resetPassword() {
    std::string newPassword;
    std::cout << std::endl;
    std::cout << "Enter new password: ";
    std::getline(std::cin, newPassword);

    makeTempFile(newPassword);
    overwriteUserFile();
    deleteFile("temp.txt");
    m_password = newPassword;

    std::cout << std::endl;
    if (isDeleted("temp.txt")) {
        std::cout << "Password changed successfully." << std::endl;
        std::cout << "Press \"Enter\" to return to account options.";
    }
    else {
        std::cout << "Password change failed.";
    }
}


void System::makeTempFile(std::string newPassword) {
    std::ofstream tempWrite;
    std::ifstream userRead;
    std::string userFile = "User_" + m_username + ".txt";
    std::string tempFile = "temp.txt";
    std::string passwordLine = "Password: " + m_password;
    std::string line;

    // read from the user's original file & put the info in a temporary file (except for the password line)
    tempWrite.open(tempFile, std::ios_base::app);
    userRead.open(userFile);
    while (std::getline(userRead, line)) {
        if (line != passwordLine) {
            tempWrite << line << std::endl;
        }
    }
    userRead.close();

    // add new line with the new password into the temporary file
    tempWrite << "Password: " + newPassword << std::endl;
    tempWrite.close();
}


void System::overwriteUserFile() {
    std::string line;
    std::ofstream userWrite;
    std::ifstream tempRead;
    std::string tempFile = "temp.txt";
    std::string fileName = "User_" + m_username + ".txt";

    // read from the temporary file & add the info to the original file
    tempRead.open(tempFile);
    userWrite.open(fileName);
    while (std::getline(tempRead, line)) {
        userWrite << line << std::endl;
    }
    tempRead.close();
    userWrite.close();
}



void System::deleteUser() {
    std::string userFile = "User_" + m_username + ".txt";
    deleteFile(userFile);

    // make sure the file was deleted
    if (isDeleted(userFile)) {
        std::cout << std::endl;
        std::cout << "User successfully deleted. Press \"Enter\" to return to the main menu.";
    }
    else {
        std::cout << "User still exists.";
    }
}


void System::deleteFile(std::string fileName) {
    fs::remove(fileName);
}


bool System::isDeleted(std::string fileName) {
    return fs::remove(fileName) == 0;
}