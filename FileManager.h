#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <vector>
#include "HelpfullMethods.h"
#include "User.h"
#include "Addressee.h"

#include <fstream>

using namespace std;

class FileManager
{
protected:
    bool isFileEmpty(fstream &textFile);
};

class FileWithUsers :public FileManager
{
    const string NAME_OF_FILE_WITH_USERS;
    string changeUserDataToLinesSeparatedByVerticalBar(User user);
    User loadUserData(string userDataSeparatedByBars);
public:
    FileWithUsers(string nameOfFileWithUsers) : NAME_OF_FILE_WITH_USERS(nameOfFileWithUsers) {};
    void appendUserToTextFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersInFIle (vector <User>& users);

};

class FileWithAddressees :public FileManager
{
    const string NAME_OF_FILE_WITH_ADDRESSEES;
    string NAME_OF_TEMPORARY_FILE_WITH_ADDRESSEE = "temporaryAddresseesFile.txt";
    int lastAddresseeId;

    string changeAddresseDataToLinesSeparatedByVerticalBar(Addressee addressee);
    int loadAddresseeIdFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar);
    Addressee getAddresseeData(string addresseeDatasSeparatedByBar);
    int getIdUserFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar);
    void deleteOutOfDateFileWithAddressees();
    void changeTemporaryAddresseesFileNameToAddresseesFileName();
    int getFromFileLastAddresseeId();

public:
    FileWithAddressees(string nameOfFileWithAddressees) : NAME_OF_FILE_WITH_ADDRESSEES(nameOfFileWithAddressees) {lastAddresseeId = 0;};
    vector <Addressee> loadAddresseesLogedInUserFromFile(int idLoggedInUser);
    void appendAddresseeToFile(Addressee addressee);
    int getLastAddresseeId();
    void increaseLastAddresseeIdAfterInsertNewAddressee();
    void deleteAddresseeFromFile(int deleteAddresseeId);
    void setLastAddresseeIdAfterDeleteAddressee(int deleteAddresseeId);
    int setLastAddresseeId(int id);
    void updateAddresseeDataInFile(Addressee addressee);


};

#endif
