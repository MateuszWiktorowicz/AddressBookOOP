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
    int idLoggedInUser;
    vector <Addressee> addressees;
    FileWithAddressees fileWithAddressees;


    Addressee insertNewAddresseeDatas(int idLoggedInUser, int lastAddresseeId);

public:
    AddresseeManager(string nameOfFileWithAddresses) : fileWithAddressees(nameOfFileWithAddresses) {idLoggedInUser = 0;};
    void insertNewAddressee();
    int loadAddresseesLogedInUserFromFile();
    int getIdLoggedInUser();
    void setIdLoggedInUser(int id);
    void readAllAddresses();
    void clearVector();

};
