#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include "Addressee.h"
#include "FileWithAddressees.h"
#include "helpfullMethods.h"

using namespace std;

class AddresseeManager
{
    const int ID_LOGGED_IN_USER;
    vector <Addressee> addressees;
    FileWithAddressees fileWithAddressees;


    Addressee insertNewAddresseeDatas();

public:
    AddresseeManager(string nameOfFileWithAddresses, int idLoggedInUser)
    : fileWithAddressees(nameOfFileWithAddresses), ID_LOGGED_IN_USER(idLoggedInUser)
    {
        addressees = fileWithAddressees.loadAddresseesLogedInUserFromFile(ID_LOGGED_IN_USER);
    };

    void insertNewAddressee();
    void loadAddresseesLogedInUserFromFile();
    void readAllAddresses();


};
