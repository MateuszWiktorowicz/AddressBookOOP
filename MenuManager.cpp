#include "MenuManager.h"

char MenuManager::choiceOptionFromMainMenu()
{
    char menuOption;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    menuOption = HelpfullMethods::readSign();

    return menuOption;
}

char MenuManager::choiceOptionFromUserMenu()
{
    char menuOption;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyswietl adresatow" << endl;
    cout << "3. Wyloguj sie" << endl;
    cout << "5. Usun osobe" << endl;
    cout << "6. Edytuj Adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    menuOption = HelpfullMethods::readSign();

    return menuOption;
}

char MenuManager::choiceOptionFromEditMenu()
{

    char choice;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    choice = HelpfullMethods::readSign();

    return choice;

}
