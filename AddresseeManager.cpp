#include "AddresseeManager.h"

void AddresseeManager::insertNewAddressee()
{
    Addressee addressee;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    addressee = insertNewAddresseeDatas();

    addressees.push_back(addressee);
    fileWithAddressees.appendAddresseeToFile(addressee);

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

void AddresseeManager::deleteAddressee()
{
    int deleteAddresseeId = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "Podaj id adresata" << endl;
    deleteAddresseeId = HelpfullMethods::readNumber();

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

void AddresseeManager::editAddressee()
{
    system("cls");

    int editAddresseeId = 0;
    string lineWithAddresseeData = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "Podaj id adresata" << endl;
    editAddresseeId = HelpfullMethods::readNumber();

    char choice;
    bool isAddresseeExist = false;

    for (vector <Addressee>::iterator itr = addressees.begin(); itr != addressees.end(); itr++)
    {
        if (itr -> getId() == editAddresseeId)
        {
            isAddresseeExist = true;
            choice = MenuManager::choiceOptionFromEditMenu();

            switch (choice)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                itr -> setName(HelpfullMethods::readLine());
                itr -> setName(HelpfullMethods::uppercaseFirstLetterLowercaseElseLetters(itr -> getName()));
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                itr -> setSurname(HelpfullMethods::readLine());
                itr -> setSurname(HelpfullMethods::uppercaseFirstLetterLowercaseElseLetters(itr -> getSurname()));
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                itr -> setPhone(HelpfullMethods::readLine());
                break;
            case '4':
                cout << "Podaj nowy email: ";
                itr -> setEmail(HelpfullMethods::readLine());
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                itr -> setAddress(HelpfullMethods::readLine());
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
            if (choice != 6)
            {
                fileWithAddressees.updateAddresseeDataInFile(*itr);
            }
        }
    }
    if (isAddresseeExist == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

void AddresseeManager::searchAddresseeByName()
{
    string nameOfOfAddresseeLookingFor = "";
    int numOfAddressees = 0;

    system("cls");
    if (!addressees.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        nameOfOfAddresseeLookingFor = HelpfullMethods::readLine();
        nameOfOfAddresseeLookingFor = HelpfullMethods::uppercaseFirstLetterLowercaseElseLetters(nameOfOfAddresseeLookingFor);

        for (vector <Addressee>::iterator  itr = addressees.begin(); itr != addressees.end(); itr++)
        {
            if (itr -> getName() == nameOfOfAddresseeLookingFor)
            {
                displayAddresseeData(*itr);
                numOfAddressees++;
            }
        }
        displayQuantitySearchedAddressees(numOfAddressees);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AddresseeManager::displayQuantitySearchedAddressees(int numOfAddressees)
{
    if (numOfAddressees == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << numOfAddressees << endl << endl;
}

void AddresseeManager::displayAddresseeData(Addressee addressee)
{
    cout << endl << "Id:                 " << addressee.getId() << endl;
    cout << "Imie:               " << addressee.getName() << endl;
    cout << "Nazwisko:           " << addressee.getSurname() << endl;
    cout << "Numer telefonu:     " << addressee.getPhone() << endl;
    cout << "Email:              " << addressee.getEmail() << endl;
    cout << "Adres:              " << addressee.getAddress() << endl;
}

void AddresseeManager::searchAddresseeBySurname()
{
    string surnameOfOfAddresseeLookingFor = "";
    int numOfAddressees = 0;
    system("cls");
    if (!addressees.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O Nazwisku <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        surnameOfOfAddresseeLookingFor = HelpfullMethods::readLine();
        surnameOfOfAddresseeLookingFor = HelpfullMethods::uppercaseFirstLetterLowercaseElseLetters(surnameOfOfAddresseeLookingFor);

        for (vector <Addressee>::iterator  itr = addressees.begin(); itr != addressees.end(); itr++)
        {
            if (itr -> getSurname() == surnameOfOfAddresseeLookingFor)
            {
                displayAddresseeData(*itr);
                numOfAddressees++;
            }
        }
        displayQuantitySearchedAddressees(numOfAddressees);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}
