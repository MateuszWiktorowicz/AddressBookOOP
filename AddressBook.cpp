#include "AddressBook.h"


void AddressBook::registerUser()
{
    userManager.registerUser();
}

void AddressBook::loginUser()
{
      userManager.loginUser();
      if (userManager.isUserLoggedIn())
      {
          addresseeManager = new AddresseeManager(NAME_OF_FILE_WITH_ADDRESSEES, userManager.getIdLoggedInUser());
      }

}

void AddressBook::changePasswordLoggedInUser()
{
    userManager.changePasswordLoggedInUser();
}

void AddressBook::logoutUser()
{
    userManager.logoutUser();
    delete addresseeManager;
    addresseeManager = NULL;
}

void AddressBook::insertNewAddressee()
{
    if (userManager.isUserLoggedIn())
    {
        addresseeManager -> insertNewAddressee();
    }
    else
    {
           cout << "Musisz sie zalogowac" << endl;
           system("pause");
    }

}

void AddressBook::readAllAddresses()
{
    if (userManager.isUserLoggedIn())
    {
        addresseeManager -> readAllAddresses();
        system("pause");
    }
    else
    {
           cout << "Musisz sie zalogowac" << endl;
           system("pause");
    }

}

void AddressBook::deleteAddressee()
{
   addresseeManager -> deleteAddressee();
}

bool AddressBook::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

char AddressBook::choiceOptionFromMainMenu()
{
   return MenuManager::choiceOptionFromMainMenu();
}

char AddressBook::choiceOptionFromUserMenu()
{
   return MenuManager::choiceOptionFromUserMenu();
}

void AddressBook::editAddressee()
{
    addresseeManager -> editAddressee();
}

void AddressBook::searchAddresseeByName()
{
    addresseeManager -> searchAddresseeByName();
}

void AddressBook::searchAddresseeBySurname()
{
    addresseeManager -> searchAddresseeBySurname();
}
