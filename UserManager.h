#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "User.h"
#include "FileWithUsers.h"

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
    void registerUser();
    void readAllAddresses();
    void readUsersFromFile();

};
