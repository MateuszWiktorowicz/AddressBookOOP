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
    int lastAddresseeId;
    vector <Addressee> addressees;
    FileWithAddressees fileWithAddressees;


    Addressee insertNewAddresseeDatas(int idZalogowanegoUzytkownika, int lastAddresseeId);

public:
    int insertNewAddressee();
    int loadAddresseesLogedInUserFromFile();
    int getIdLoggedInUser();
    int getLastAddresseeId();
    void setIdLoggedInUser(int id);
    void setLastAddresseeId(int id);
    void readAllAddresses();


};
