#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include "Addressee.h"
#include "FileManager.h"
#include "helpfullMethods.h"
#include "MenuManager.h"

using namespace std;

class AddresseeManager
{
    const int ID_LOGGED_IN_USER;
    vector <Addressee> addressees;
    FileWithAddressees fileWithAddressees;


    Addressee insertNewAddresseeDatas();
    int deleteAddresseeFromFile();
    int insertAddresseId();
    int getLastAddresseeIdAfterDeleteAddressee(int deleteAddresseeId);
    void displayAddresseeData(Addressee addressee);
    void displayQuantitySearchedAddressees(int numOfAddressees);

public:
    AddresseeManager(string nameOfFileWithAddresses, int idLoggedInUser)
    : fileWithAddressees(nameOfFileWithAddresses), ID_LOGGED_IN_USER(idLoggedInUser)
    {
        addressees = fileWithAddressees.loadAddresseesLogedInUserFromFile(ID_LOGGED_IN_USER);
    };
    void insertNewAddressee();
    void loadAddresseesLogedInUserFromFile();
    void readAllAddresses();
    int deleteAddressee();
    void editAddressee();
    void searchAddresseeByName();
    void searchAddresseeBySurname();




};
