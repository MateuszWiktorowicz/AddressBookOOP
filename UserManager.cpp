#include "UserManager.h"

void UserManager::registerUser()
{

    User user = insertNewUser();

    users.push_back(user);
    fileWithUsers.appendUserToTextFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::insertNewUser()
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

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login)
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

void UserManager::readAllAddresses()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

