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
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    menuOption = HelpfullMethods::readSign();

    return menuOption;
}
