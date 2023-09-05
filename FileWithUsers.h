#include <iostream>
#include <vector>
#include "HelpfullMethods.h"
#include "User.h"

#include <fstream>

using namespace std;

class FileWithUsers
{
    const string nameOfFileWithUsers;

    bool isFileEmpty();
    string changeUserDataToLinesSeparatedByVerticalBar(User user);
    User loadUserData(string userDataSeparatedByBars);
public:
    FileWithUsers(string NAMEOFFILEWITHUSERS) : nameOfFileWithUsers(NAMEOFFILEWITHUSERS) {};
    void appendUserToTextFile(User user);
    vector <User> readUsersFromFile();
};
