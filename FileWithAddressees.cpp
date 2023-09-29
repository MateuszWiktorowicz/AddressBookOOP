#include "FileWithAddressees.h"

void FileWithAddressees::appendAddresseeToFile(Addressee addressee)
{
    string lineWithAddresseData = "";
    fstream textFile;
    textFile.open(nameOfFileWithAddressees.c_str(), ios::out | ios::app);

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

int FileWithAddressees::loadAddresseesLogedInUserFromFile(vector <Addressee> &addressees, int idLoggedInUser)
{
    Addressee addressee;
    string oneAddresseeDatasSeparatedByBar = "";
    string lastAddresseeDataInFile = "";
    fstream textFile;
    textFile.open(nameOfFileWithAddressees.c_str(), ios::in);

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
        return lastAddresseeId;
    }
    else
        return 0;
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

    for (int signPosition = 0; signPosition < addresseeDatasSeparatedByBar.length(); signPosition++)
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

void FileWithAddressees::setLastAddresseId()
{
    lastAddresseeId += 1;
}
