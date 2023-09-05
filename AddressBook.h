#include <iostream>

#include "UserManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
public:
    AddressBook();
    void registerUser();
    void readAllAddresses();

};
