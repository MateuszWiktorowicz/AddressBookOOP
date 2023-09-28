#include "AddresseeManager.h"

int AddresseeManager::insertNewAddressee()
{
    Addressee addressee;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    addressee = insertNewAddresseeDatas(idLoggedInUser, lastAddresseeId);

    addressees.push_back(addressee);
    fileWithAddressees.appendAddresseeToFile(addressee);

    return ++lastAddresseeId;
}

Addressee AddresseeManager::insertNewAddresseeDatas(int idLoggedInUser, int lastAddresseeId)
{
    Addressee addressee;

    addressee.setId(++lastAddresseeId);
    addressee.setUserId(idLoggedInUser);

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

int AddresseeManager::loadAddresseesLogedInUserFromFile()
{
    fileWithAddressees.loadAddresseesLogedInUserFromFile(addressees, idLoggedInUser);
}

void AddresseeManager::setIdLoggedInUser(int id)
{
    idLoggedInUser = id;
};

void AddresseeManager::setLastAddresseeId(int id)
{
    lastAddresseeId = id;
}

int AddresseeManager::getIdLoggedInUser()
{
    return idLoggedInUser;
}

int AddresseeManager::getLastAddresseeId()
{
    return lastAddresseeId;
}

void AddresseeManager::readAllAddresses()
{
    cout << addressees.size();
    for (int i = 0; i < addressees.size(); i++)
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
