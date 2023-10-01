#include <iostream>
#include <vector>
#include "HelpfullMethods.h"
#include "User.h"

#include <fstream>

using namespace std;

class FileWithUsers
{
    const string NAME_OF_FILE_WITH_USERS;

    bool isFileEmpty();
    string changeUserDataToLinesSeparatedByVerticalBar(User user);
    User loadUserData(string userDataSeparatedByBars);
public:
    FileWithUsers(string nameOfFileWithUsers) : NAME_OF_FILE_WITH_USERS(nameOfFileWithUsers) {};
    void appendUserToTextFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersInFIle (vector <User>& users);

};
