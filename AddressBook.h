#include <iostream>

#include "UserManager.h"
#include "AddresseeManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
    AddresseeManager addresseeManager;
public:
    AddressBook(string nameOfFileWithUsers, string nameOfFileWithAddressees)
    : userManager(nameOfFileWithUsers), addresseeManager(nameOfFileWithAddressees)

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
