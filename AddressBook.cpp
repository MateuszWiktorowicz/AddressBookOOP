#include "AddressBook.h"

void AddressBook::registerUser()
{
    User user = insertNewUser();

    users.push_back(user);
    // dopiszuseraDoPliku(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User AddressBook::insertNewUser()
{
    User user;

    user.setId(getNewUserId());

    string login;
    string password;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }

    while (isLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int AddressBook::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool AddressBook::isLoginExist(string login)
{
    for (int i = 0; i <users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }

    return false;
}

void AddressBook::readAllAddresses()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}
