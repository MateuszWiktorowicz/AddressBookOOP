#include <iostream>
#include <vector>
#include <fstream>
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
    FileWithAddressees FileWithAddressees;

};
