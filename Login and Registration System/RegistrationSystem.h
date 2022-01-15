#ifndef Registration_System_hpp
#define Registration_System_hpp

#include <string>

class System {
public:
    void welcome();
    void login();
    void signUp();

private:
    void loginCredentials();
    void signUpCredentials();
    void createNewUserProfile();
    bool isRegistered();
    bool isCorrectPassword();
    void accountOptions();
    void readFile();
    void resetPassword();
    void makeTempFile(std::string newPassword);
    void overwriteUserFile();
    void deleteUser();
    void deleteFile(std::string fileName);
    bool isDeleted(std::string fileName);

    std::string m_username;
    std::string m_password;
    std::string m_firstName;
    std::string m_lastName;
};

#endif
