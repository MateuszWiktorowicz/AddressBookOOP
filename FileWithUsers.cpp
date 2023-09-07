#include "FileWithUsers.h"


void FileWithUsers::appendUserToTextFile(User user)
{
    fstream textFile;
    string userDatasLine = "";
    textFile.open(nameOfFileWithUsers.c_str(), ios::app);

    if (textFile.good() == true)
    {
        userDatasLine = changeUserDataToLinesSeparatedByVerticalBar(user);

        if (isFileEmpty() == true)
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

bool FileWithUsers::isFileEmpty()
{
    fstream textFile;
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string FileWithUsers::changeUserDataToLinesSeparatedByVerticalBar(User user)
{
    string userDatasLine = "";
    userDatasLine += HelpfullMethods::convertIntoString(user.getId())+ '|';
    userDatasLine += user.getLogin() + '|';
    userDatasLine += user.getPassword() + '|';

    return userDatasLine;
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    fstream textFile;
    User user;
    vector <User> users;
    string userDataSeparatedByBars = "";


    textFile.open(nameOfFileWithUsers.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, userDataSeparatedByBars))
        {
            user = loadUserData(userDataSeparatedByBars);
            users.push_back(user);
        }

    }
    textFile.close();
    return users;
}

User FileWithUsers::loadUserData(string userDataSeparatedByBars)
{
    User user;
    string singleUserData = "";
    int numOfSingleUserData = 1;

    for (int charPosition = 0; charPosition < userDataSeparatedByBars.length(); charPosition++)
    {
        if (userDataSeparatedByBars[charPosition] != '|')
        {
            singleUserData += userDataSeparatedByBars[charPosition];
        }
        else
        {
            switch(numOfSingleUserData)
            {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            numOfSingleUserData++;
        }
    }
    return user;
}



void FileWithUsers::saveAllUsersInFIle(vector <User> &users)
{
    fstream textFile;
    string lineWithUsersData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(nameOfFileWithUsers.c_str(), ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            lineWithUsersData = changeUserDataToLinesSeparatedByVerticalBar(*itr);

            if (itr == itrEnd)
            {
               textFile << lineWithUsersData;
            }
            else
            {
                textFile << lineWithUsersData << endl;
            }
            lineWithUsersData = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << nameOfFileWithUsers << endl;
    }
    textFile.close();
}

