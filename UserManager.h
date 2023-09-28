#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "User.h"
#include "FileWithUsers.h"
#include "helpfullMethods.h"

using namespace std;

class UserManager
{
    int idLoggedInUser;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User insertNewUser();
    int getNewUserId();
    bool isLoginExist(string login);
    User loadUserData(string userDataSeparatedByBars);
public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers) {};
    void registerUser();

    void loadUsersFromFile();
    int loginUser();
    void changePasswordLoggedInUser();
    void setIdLoggedInUser(int id);
    int getIdLoggedInUser();
    void logoutUser();

};
