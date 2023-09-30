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
    for (size_t i = 0; i <users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }

    return false;
}

int UserManager::loginUser()
{
    User user;
    string log = "", pass = "";

    cout <<  "Podaj login: ";
    log = HelpfullMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == log)
        {
            for (int numOfAttempts = 3; numOfAttempts > 0; numOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numOfAttempts << ": ";
                pass = HelpfullMethods::readLine();

                if (itr -> getPassword() == pass)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idLoggedInUser = itr -> getId();
                    return  idLoggedInUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changePasswordLoggedInUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = HelpfullMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == idLoggedInUser)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersInFIle(users);
}


void UserManager::logoutUser()
{

    idLoggedInUser = 0;
}

int UserManager::getIdLoggedInUser()
{
    return idLoggedInUser;
}
