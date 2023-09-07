#include "AddressBook.h"


void AddressBook::registerUser()
{
    userManager.registerUser();
}

void AddressBook::readAllAddresses()
{
    userManager.readAllAddresses();
}

int AddressBook::loginUser()
{
      userManager.setIdLoggedInUser(userManager.loginUser());
}

void AddressBook::changePasswordLoggedInUser()
{
    userManager.changePasswordLoggedInUser();
}

void AddressBook::logoutUser()
{
    userManager.logoutUser();
}
