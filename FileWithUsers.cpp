#include "FileWithUsers.h"

FileWithUsers::FileWithUsers()
{
    nameOfFileWithUsers = "Uzytkownicy.txt";
}

void FileWithUsers::appendUserToTextFile(User user)
{

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
