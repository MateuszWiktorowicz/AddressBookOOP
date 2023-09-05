#include "AddressBook.h"

AddressBook::AddressBook()
{
    userManager.readUsersFromFile();
}

void AddressBook::registerUser()
{
    userManager.registerUser();
}

void AddressBook::readAllAddresses()
{
    userManager.readAllAddresses();
}
