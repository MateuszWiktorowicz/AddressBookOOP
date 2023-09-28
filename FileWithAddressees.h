#include <iostream>
#include <vector>
#include "HelpfullMethods.h"
#include "Addressee.h"

#include <fstream>

using namespace std;

class FileWithAddressees
{
    const string nameOfFileWithAddressees = "Addressees.txt";


    bool isFileEmpty(fstream &textFile);

    string changeAddresseDataToLinesSeparatedByVerticalBar(Addressee addressee);
    int loadAddresseeIdFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar);
    Addressee getAddresseeData(string addresseeDatasSeparatedByBar);
    int getIdUserFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar);

public:
    int loadAddresseesLogedInUserFromFile(vector <Addressee> &addressees, int idLoggedInUser);
    void appendAddresseeToFile(Addressee addressee);

};
