#include <iostream>

#include "UserManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
public:
    AddressBook(string nameOfFileWithUsers) : userManager(nameOfFileWithUsers)
    {
        userManager.readUsersFromFile();
    };

    void registerUser();
    void readAllAddresses();

};
