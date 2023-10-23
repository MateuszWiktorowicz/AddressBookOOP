#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <vector>

#include "FileManager.h"
#include "User.h"

class FileWithUsers : public FileManager
{

    string changeUserDataToLinesSeparatedByVerticalBar(User user);
    User loadUserData(string userDataSeparatedByBars);
public:

    FileWithUsers(string fileName) : FileManager(fileName) {};
    void appendUserToTextFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersInFIle (vector <User> &users);

};

#endif
