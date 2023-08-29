#include <iostream>
#include <vector>
#include "User.h"
#include <windows.h>

using namespace std;

class AddressBook
{
    int idLoggedInUser;
    int idLastAddress;
    int idDeletedAddress;

    vector <User> users;

   User insertNewUser();
   int getNewUserId();
   bool isLoginExist();
   bool isLoginExist(string login);

public:
    void registerUser();
    void readAllAddresses();

};
