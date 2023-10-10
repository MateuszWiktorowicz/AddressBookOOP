#include "FileWithAddressees.h"

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



bool FileWithAddressees::isFileEmpty(fstream &textFile)
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

    lineWithAddresseData += HelpfullMethods::convertIntoString(addressee.getId()) + '|';
    lineWithAddresseData += HelpfullMethods::convertIntoString(addressee.getUserId()) + '|';
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
                {}
            else
            {
               if (!textFileBeingRead.eof())
               {
                   if (numOfLoadedLine != 1)
                   {
                       temporaryTextFile << endl;
                   }

               }    temporaryTextFile << loadedLine;
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


