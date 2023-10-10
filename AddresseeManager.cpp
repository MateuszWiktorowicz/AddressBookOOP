#include "AddresseeManager.h"

void AddresseeManager::insertNewAddressee()
{
    Addressee addressee;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    addressee = insertNewAddresseeDatas();

    addressees.push_back(addressee);
    fileWithAddressees.appendAddresseeToFile(addressee);
    fileWithAddressees.increaseLastAddresseeIdAfterInsertNewAddressee();

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

int AddresseeManager::deleteAddressee()
{
    int deleteAddresseeId = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    deleteAddresseeId = insertDeleteAddresseId();

    char sign;
    bool isAddresseExist = false;

    for (vector <Addressee>::iterator itr = addressees.begin(); itr != addressees.end(); itr++)
    {
        if (itr -> getId() == deleteAddresseeId)
        {
            isAddresseExist = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            sign = HelpfullMethods::readSign();
            if (sign == 't')
            {
                fileWithAddressees.deleteAddresseeFromFile(deleteAddresseeId);
                addressees.erase(itr);
                fileWithAddressees.setLastAddresseeIdAfterDeleteAddressee(deleteAddresseeId);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                break;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (isAddresseExist == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }



}

int AddresseeManager::insertDeleteAddresseId()
{
    int deleteAddresseeId = 0;
    cout << "Podaj numer ID Adresata: ";
    deleteAddresseeId  = HelpfullMethods::readNumber();
    return deleteAddresseeId;
}



