#include <iostream>
#include <vector>
#include "User.h"
#include <windows.h>
#include <fstream>
#include <sstream>
using namespace std;

class AddressBook
{
    int idLoggedInUser;
    int idLastAddress;
    int idDeletedAddress;
    string nameOfFileWithUsers;

    vector <User> users;

   User insertNewUser();
   int getNewUserId();
   bool isLoginExist();
   bool isLoginExist(string login);
   void appendUserToTextFile(User user);
   string changeUserDataToLinesSeparatedByVerticalBar(User user);
   string convertIntoString(int num);
   bool isFileEmpty(fstream &textFile);

public:
    AddressBook();
    void registerUser();
    void readAllAddresses();

};
