#include <iostream>

#include "UserManager.h"
#include "AddresseeManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
    AddresseeManager addresseeManager;
public:
    AddressBook(string nameOfFileWithUsers) : userManager(nameOfFileWithUsers)
    {
        userManager.loadUsersFromFile();
    };

    void registerUser();
    void loginUser();
    void readAllAddresses();
    void changePasswordLoggedInUser();
    void logoutUser();
    void insertNewAddressee();
    void loadAddresseesLogedInUserFromFile();

};
