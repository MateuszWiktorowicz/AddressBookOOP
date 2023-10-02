#include "AddresseeManager.h"

void AddresseeManager::insertNewAddressee()
{
    Addressee addressee;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    addressee = insertNewAddresseeDatas();

    addressees.push_back(addressee);
    fileWithAddressees.appendAddresseeToFile(addressee);
    fileWithAddressees.setLastAddresseId();

}

Addressee AddresseeManager::insertNewAddresseeDatas()
{
    Addressee addressee;

    addressee.setId(fileWithAddressees.getLastAddresseeId() + 1);
    addressee.setUserId(ID_LOGGED_IN_USER);

    cout << "Podaj imie: ";
    addressee.setName(HelpfullMethods::readLine());
    addressee.setName(HelpfullMethods::uppercaseFirstLetterLowercaseElseLetters(addressee.getName()));

    cout << "Podaj nazwisko: ";
    addressee.setSurname(HelpfullMethods::readLine());
    addressee.setSurname (HelpfullMethods::uppercaseFirstLetterLowercaseElseLetters(addressee.getSurname()));

    cout << "Podaj numer telefonu: ";
    addressee.setPhone(HelpfullMethods::readLine());

    cout << "Podaj email: ";
    addressee.setEmail(HelpfullMethods::readLine());

    cout << "Podaj adres: ";
    addressee.setAddress(HelpfullMethods::readLine());

    return addressee;
}

void AddresseeManager::readAllAddresses()
{
    for (size_t i = 0; i < addressees.size(); i++)
    {
        cout << addressees[i].getId() << endl;
        cout << addressees[i].getUserId() << endl;
        cout << addressees[i].getName() << endl;
        cout << addressees[i].getSurname() << endl;
        cout << addressees[i].getPhone() << endl;
        cout << addressees[i].getEmail() << endl;
        cout << addressees[i].getAddress() << endl;
    }
}
