#include <iostream>
#include <vector>
#include "HelpfullMethods.h"
#include "Addressee.h"

#include <fstream>

using namespace std;

class FileWithAddressees
{
    const string NAME_OF_FILE_WITH_ADDRESSEES;
    int lastAddresseeId;

    bool isFileEmpty(fstream &textFile);

    string changeAddresseDataToLinesSeparatedByVerticalBar(Addressee addressee);
    int loadAddresseeIdFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar);
    Addressee getAddresseeData(string addresseeDatasSeparatedByBar);
    int getIdUserFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar);

public:
    FileWithAddressees(string nameOfFileWithAddressees) : NAME_OF_FILE_WITH_ADDRESSEES(nameOfFileWithAddressees) {lastAddresseeId = 0;};
    int loadAddresseesLogedInUserFromFile(vector <Addressee> &addressees, int idLoggedInUser);
    void appendAddresseeToFile(Addressee addressee);
    int getLastAddresseeId();
    void setLastAddresseId();

};
