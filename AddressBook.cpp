#include "AddressBook.h"

AddressBook::AddressBook()
{
    nameOfFileWithUsers = "Users.txt";
}


void AddressBook::registerUser()
{
    User user = insertNewUser();

    users.push_back(user);
    appendUserToTextFile(user);

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

void AddressBook::appendUserToTextFile(User user)
{
    fstream textFile;
    string userDatasLine = "";
    textFile.open(nameOfFileWithUsers.c_str(), ios::app);

    if (textFile.good() == true)
    {
        userDatasLine = changeUserDataToLinesSeparatedByVerticalBar(user);

        if (isFileEmpty(textFile) == true)
        {
            textFile << userDatasLine;
        }
        else
        {
            textFile << endl << userDatasLine ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nameOfFileWithUsers << " i zapisac w nim danych." << endl;
    textFile.close();
}

string AddressBook::changeUserDataToLinesSeparatedByVerticalBar(User user)
{
    string userDatasLine = "";

    userDatasLine += convertIntoString(user.getId())+ '|';
    userDatasLine += user.getLogin() + '|';
    userDatasLine += user.getPassword() + '|';

    return userDatasLine;
}

string AddressBook::convertIntoString(int num)
{
    ostringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

bool AddressBook::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
