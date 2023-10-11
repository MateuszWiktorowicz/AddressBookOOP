#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt", "Addressees.txt");
    char menuOption;

    while (true)
    {
        if (!addressBook.isUserLoggedIn())
        {
            menuOption = addressBook.choiceOptionFromMainMenu();

            switch (menuOption)
            {
            case '1':
                addressBook.registerUser();;
                break;
            case '2':
                addressBook.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
         menuOption = addressBook.choiceOptionFromUserMenu();

            switch (menuOption)
            {
            case '1':
                addressBook.insertNewAddressee();
                break;
            case '2':
                addressBook.searchAddresseeByName();
                break;
            case '3':
                addressBook.searchAddresseeBySurname();
                break;
            case '4':
                addressBook.readAllAddresses();
                break;
            case '5':
                addressBook.deleteAddressee();
                break;
            case '6':
                addressBook.editAddressee();
                break;
            case '8':
                addressBook.logoutUser();
            break;
            }
        }
    }
    return 0;
}


