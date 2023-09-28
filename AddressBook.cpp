#include "AddressBook.h"


void AddressBook::registerUser()
{
    userManager.registerUser();
}

void AddressBook::readAllAddresses()
{
    addresseeManager.readAllAddresses();
}

void AddressBook::loginUser()
{
      userManager.setIdLoggedInUser(userManager.loginUser());
      addresseeManager.setIdLoggedInUser(userManager.getIdLoggedInUser());
      addresseeManager.setLastAddresseeId(addresseeManager.loadAddresseesLogedInUserFromFile());

}

void AddressBook::changePasswordLoggedInUser()
{
    userManager.changePasswordLoggedInUser();
}

void AddressBook::logoutUser()
{
    userManager.logoutUser();
}

void AddressBook::insertNewAddressee()
{
    vector <Addressee> addressees;
    addresseeManager.insertNewAddressee();
}

