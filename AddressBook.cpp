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
    userManager.loginUser();
}
