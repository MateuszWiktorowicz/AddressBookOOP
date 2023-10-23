#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include "Addressee.h"
#include "FileWithAddressees.h"
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
    int getLastAddresseeIdAfterDeleteAddressee(int deleteAddresseeId);
    void displayAddresseeData(Addressee addressee);
    void displayQuantitySearchedAddressees(int numOfAddressees);

public:
    AddresseeManager(string nameOfFileWithAddresses, int idLoggedInUser)
    : ID_LOGGED_IN_USER(idLoggedInUser), fileWithAddressees(nameOfFileWithAddresses)
    {
        addressees = fileWithAddressees.loadAddresseesLogedInUserFromFile(ID_LOGGED_IN_USER);
    };
    void insertNewAddressee();
    void loadAddresseesLogedInUserFromFile();
    void readAllAddresses();
    void deleteAddressee();
    void editAddressee();
    void searchAddresseeByName();
    void searchAddresseeBySurname();




};
