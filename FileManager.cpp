#include "FileManager.h"





bool FileManager::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string FileWithAddressees::changeAddresseDataToLinesSeparatedByVerticalBar(Addressee addressee)
{
    string lineWithAddresseData = "";

    lineWithAddresseData += HelpfullMethods::convertIntegerToString(addressee.getId()) + '|';
    lineWithAddresseData += HelpfullMethods::convertIntegerToString(addressee.getUserId()) + '|';
    lineWithAddresseData += addressee.getName() + '|';
    lineWithAddresseData += addressee.getSurname() + '|';
    lineWithAddresseData += addressee.getPhone() + '|';
    lineWithAddresseData += addressee.getEmail() + '|';
    lineWithAddresseData += addressee.getAddress() + '|';

    return lineWithAddresseData;
}

vector <Addressee> FileWithAddressees::loadAddresseesLogedInUserFromFile(int idLoggedInUser)
{
    vector <Addressee> addressees;
    Addressee addressee;
    string oneAddresseeDatasSeparatedByBar = "";
    string lastAddresseeDataInFile = "";
    fstream textFile;
    textFile.open(NAME_OF_FILE_WITH_ADDRESSEES.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, oneAddresseeDatasSeparatedByBar))
        {
            if(idLoggedInUser == getIdUserFromDataSeparatedByBars(oneAddresseeDatasSeparatedByBar))
            {
                addressee = getAddresseeData(oneAddresseeDatasSeparatedByBar);
                addressees.push_back(addressee);
            }
        }
        lastAddresseeDataInFile = oneAddresseeDatasSeparatedByBar;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    textFile.close();

    if (lastAddresseeDataInFile != "")
    {
        lastAddresseeId = loadAddresseeIdFromDataSeparatedByBars(lastAddresseeDataInFile);
    }
    return addressees;
}

int FileWithAddressees::getIdUserFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar)
{
    int idUserPosition = oneAddresseeDatasSeparatedByBar.find_first_of('|') + 1;
    int userId = HelpfullMethods::convertStringIntoInt(HelpfullMethods::getNumber(oneAddresseeDatasSeparatedByBar, idUserPosition));

    return userId;
}

Addressee FileWithAddressees::getAddresseeData(string addresseeDatasSeparatedByBar)
{
    Addressee addressee;
    string singleAddresseeData = "";
    int numOfSingleAddresseeData = 1;

    for (size_t signPosition = 0; signPosition < addresseeDatasSeparatedByBar.length(); signPosition++)
    {
        if (addresseeDatasSeparatedByBar[signPosition] != '|')
        {
            singleAddresseeData += addresseeDatasSeparatedByBar[signPosition];
        }
        else
        {
            switch(numOfSingleAddresseeData)
            {
            case 1:
                addressee.setId(atoi(singleAddresseeData.c_str()));
                break;
            case 2:
                addressee.setUserId(atoi(singleAddresseeData.c_str()));
                break;
            case 3:
                addressee.setName(singleAddresseeData);
                break;
            case 4:
                addressee.setSurname(singleAddresseeData);
                break;
            case 5:
                addressee.setPhone(singleAddresseeData);
                break;
            case 6:
                addressee.setEmail(singleAddresseeData);
                break;
            case 7:
                addressee.setAddress(singleAddresseeData);
                break;
            }
            singleAddresseeData = "";
            numOfSingleAddresseeData++;
        }
    }
    return addressee;
}

int FileWithAddressees::loadAddresseeIdFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar)
{
    int addresseeIdStartPosition = 0;
    int addresseeId = HelpfullMethods::convertStringIntoInt(HelpfullMethods::getNumber(oneAddresseeDatasSeparatedByBar, addresseeIdStartPosition));
    return addresseeId;
}

int FileWithAddressees::getLastAddresseeId()
{
    return lastAddresseeId;
}

void FileWithAddressees::increaseLastAddresseeIdAfterInsertNewAddressee()
{
    lastAddresseeId += 1;
}

void FileWithAddressees::deleteAddresseeFromFile(int deleteAddresseeId)
{
    fstream textFileBeingRead, temporaryTextFile;
    string loadedLine = "";
    int numOfLoadedLine = 1;
    int loadedAddresseId = 0;

    textFileBeingRead.open(NAME_OF_FILE_WITH_ADDRESSEES.c_str(), ios::in);
    temporaryTextFile.open(NAME_OF_TEMPORARY_FILE_WITH_ADDRESSEE.c_str(), ios::out | ios::app);

    if (textFileBeingRead.good() == true)
    {
        while (getline(textFileBeingRead, loadedLine))
        {
            stringstream ss(loadedLine);
            string field;

            getline(ss, field, '|');
            loadedAddresseId = stoi(field);

            if (deleteAddresseeId == loadedAddresseId)
            {
                if (numOfLoadedLine == 1)
                {
                    numOfLoadedLine = 0;
                }
            }
            else
            {
                if (numOfLoadedLine != 1)
                {
                    temporaryTextFile << endl;
                }
                temporaryTextFile << loadedLine;
            }
            numOfLoadedLine++;
        }
        textFileBeingRead.close();
        temporaryTextFile.close();

        deleteOutOfDateFileWithAddressees();
        changeTemporaryAddresseesFileNameToAddresseesFileName();
    }
}

void FileWithAddressees::deleteOutOfDateFileWithAddressees()
{
    if (remove(NAME_OF_FILE_WITH_ADDRESSEES.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << NAME_OF_FILE_WITH_ADDRESSEES << endl;
}

void FileWithAddressees::changeTemporaryAddresseesFileNameToAddresseesFileName()
{
    if (rename(NAME_OF_TEMPORARY_FILE_WITH_ADDRESSEE.c_str(), NAME_OF_FILE_WITH_ADDRESSEES.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << NAME_OF_TEMPORARY_FILE_WITH_ADDRESSEE << endl;
}

int FileWithAddressees::getFromFileLastAddresseeId()
{
    int lastAddresseeId = 0;
    string oneAddresseeDatasSeparatedByBar = "";
    string dataLastAddresseeInFile = "";
    fstream textFile;
    textFile.open(NAME_OF_FILE_WITH_ADDRESSEES.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, oneAddresseeDatasSeparatedByBar)) {}
        dataLastAddresseeInFile = oneAddresseeDatasSeparatedByBar;
        textFile.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (dataLastAddresseeInFile != "")
    {
        lastAddresseeId = loadAddresseeIdFromDataSeparatedByBars(dataLastAddresseeInFile);
    }
    return lastAddresseeId;
}

void FileWithAddressees::setLastAddresseeIdAfterDeleteAddressee(int deleteAddresseeId)
{
    if (deleteAddresseeId == getLastAddresseeId())
        setLastAddresseeId(getFromFileLastAddresseeId());

}

int FileWithAddressees::setLastAddresseeId(int id)
{
    return lastAddresseeId = id;
}


void FileWithAddressees::updateAddresseeDataInFile(Addressee addressee)
{

    fstream textFileBeingRead, temporaryTextFile;
    string loadedLine = "";
    int numOfLoadedLine = 1;
    int loadedAddresseId = 0;

    textFileBeingRead.open(NAME_OF_FILE_WITH_ADDRESSEES.c_str(), ios::in);
    temporaryTextFile.open(NAME_OF_TEMPORARY_FILE_WITH_ADDRESSEE.c_str(), ios::out);

    if (textFileBeingRead.good() == true)
    {
        while (getline(textFileBeingRead, loadedLine))
        {
            stringstream ss(loadedLine);
            string field;

            getline(ss, field, '|');
            loadedAddresseId = stoi(field);


            if (addressee.getId() == loadedAddresseId)
            {
                 if (((addressee.getId() != getLastAddresseeId()) && numOfLoadedLine != 1) || (addressee.getId() == getLastAddresseeId()))
                {
                    temporaryTextFile << endl;
                }
                temporaryTextFile << HelpfullMethods::convertIntegerToString(addressee.getId()) << '|';
                temporaryTextFile << HelpfullMethods::convertIntegerToString(addressee.getUserId()) << '|';
                temporaryTextFile << addressee.getName() << '|';
                temporaryTextFile << addressee.getSurname() << '|';
                temporaryTextFile << addressee.getPhone() << '|';
                temporaryTextFile << addressee.getEmail() << '|';
                temporaryTextFile << addressee.getAddress() << '|';
            }
            else
            {
                if (numOfLoadedLine != 1)
                {
                    temporaryTextFile << endl;
                }
                temporaryTextFile << loadedLine;
            }
            numOfLoadedLine++;
        }
        textFileBeingRead.close();
        temporaryTextFile.close();

        deleteOutOfDateFileWithAddressees();
        changeTemporaryAddresseesFileNameToAddresseesFileName();
        cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
    }
}



void FileWithAddressees::appendAddresseeToFile(Addressee addressee)
{
    string lineWithAddresseData = "";
    fstream textFile;
    textFile.open(NAME_OF_FILE_WITH_ADDRESSEES.c_str(), ios::out | ios::app);

    if (textFile.good())
    {
        lineWithAddresseData = changeAddresseDataToLinesSeparatedByVerticalBar(addressee);

        if (isFileEmpty(textFile))
        {
            textFile << lineWithAddresseData;
        }
        else
        {
            textFile << endl << lineWithAddresseData ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    textFile.close();
    system("pause");
}


void FileWithUsers::appendUserToTextFile(User user)
{
    fstream textFile;
    string userDatasLine = "";
    textFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::app);

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
        cout << "Nie udalo sie otworzyc pliku " << NAME_OF_FILE_WITH_USERS << " i zapisac w nim danych." << endl;
    textFile.close();
}

string FileWithUsers::changeUserDataToLinesSeparatedByVerticalBar(User user)
{
    string userDatasLine = "";
    userDatasLine += HelpfullMethods::convertIntegerToString(user.getId())+ '|';
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


    textFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::in);

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

    for (size_t charPosition = 0; charPosition < userDataSeparatedByBars.length(); charPosition++)
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

    textFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::out);

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
        cout << "Nie mozna otworzyc pliku " << NAME_OF_FILE_WITH_USERS << endl;
    }
    textFile.close();
}



