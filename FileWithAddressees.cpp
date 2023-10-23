#include "FileWithAddressees.h"

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
    textFile.open(FileManager::getFileName().c_str(), ios::in);

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

void FileWithAddressees::deleteAddresseeFromFile(int deleteAddresseeId)
{
    fstream textFileBeingRead, temporaryTextFile;
    string loadedLine = "";
    int numOfLoadedLine = 1;
    int loadedAddresseId = 0;

    textFileBeingRead.open(FileManager::getFileName(), ios::in);
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
    if (deleteAddresseeId == getLastAddresseeId())
    {
       setLastAddresseeId(getFromFileLastAddresseeId());
    }

}

void FileWithAddressees::deleteOutOfDateFileWithAddressees()
{
    if (remove(FileManager::getFileName().c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << FileManager::getFileName() << endl;
}

void FileWithAddressees::changeTemporaryAddresseesFileNameToAddresseesFileName()
{
    if (rename(FileManager::getFileName().c_str(), FileManager::getFileName().c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << FileManager::getFileName() << endl;
}

int FileWithAddressees::getFromFileLastAddresseeId()
{
    int lastAddresseeId = 0;
    string oneAddresseeDatasSeparatedByBar = "";
    string dataLastAddresseeInFile = "";
    fstream textFile;
    textFile.open(FileManager::getFileName().c_str(), ios::in);

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

    textFileBeingRead.open(FileManager::getFileName().c_str(), ios::in);
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
    textFile.open(FileManager::getFileName().c_str(), ios::out | ios::app);

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
    lastAddresseeId += 1;
    textFile.close();
    system("pause");
}
