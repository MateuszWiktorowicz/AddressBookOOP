#include <iostream>

#include "UserManager.h"
#include "AddresseeManager.h"
#include "MenuManager.h"

using namespace std;

class AddressBook
{
    MenuManager menuManager;
    UserManager userManager;
    AddresseeManager *addresseeManager;
    const string NAME_OF_FILE_WITH_ADDRESSEES;
public:
    AddressBook(string nameOfFileWithUsers, string nameOfFileWithAddressees)
    : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_ADDRESSEES(nameOfFileWithAddressees)
    {
        addresseeManager = NULL;
    };
    ~AddressBook()
    {
      delete addresseeManager;
      addresseeManager = NULL;
    };

    void registerUser();
    void loginUser();
    void readAllAddresses();
    void changePasswordLoggedInUser();
    void logoutUser();
    void insertNewAddressee();
    void loadAddresseesLogedInUserFromFile();
    bool isUserLoggedIn();
    char choiceOptionFromMainMenu();
    char choiceOptionFromUserMenu();

};
