#include <iostream>

#include "UserManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
public:
    AddressBook(string nameOfFileWithUsers) : userManager(nameOfFileWithUsers)
    {
        userManager.loadUsersFromFile();
    };

    void registerUser();
    int loginUser();
    void readAllAddresses();
    void changePasswordLoggedInUser();
    void logoutUser();

};
