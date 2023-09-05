#include <iostream>
#include <vector>
#include "HelpfullMethods.h"
#include "User.h"

#include <fstream>

using namespace std;

class FileWithUsers
{
    string nameOfFileWithUsers;
    fstream textFile;

    bool isFileEmpty();
    string changeUserDataToLinesSeparatedByVerticalBar(User user);
    User loadUserData(string userDataSeparatedByBars);
public:
    FileWithUsers();
    void appendUserToTextFile(User user);
    vector <User> readUsersFromFile();
};
