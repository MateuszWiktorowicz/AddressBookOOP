#include "AddressBook.h"


void AddressBook::registerUser()
{
    userManager.registerUser();
}

void AddressBook::loginUser()
{
      userManager.loginUser();
      addresseeManager.setIdLoggedInUser(userManager.getIdLoggedInUser());
      addresseeManager.loadAddresseesLogedInUserFromFile();
}

void AddressBook::changePasswordLoggedInUser()
{
    userManager.changePasswordLoggedInUser();
}

void AddressBook::logoutUser()
{
    userManager.logoutUser();
    addresseeManager.clearVector();
}

void AddressBook::insertNewAddressee()
{
    addresseeManager.insertNewAddressee();
}

void AddressBook::readAllAddresses()
{
    addresseeManager.readAllAddresses();
}
