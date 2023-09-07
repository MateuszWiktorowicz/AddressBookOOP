#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt");
    UserManager userManager();
    //addressBook.registerUser();
    addressBook.readAllAddresses();
    addressBook.loginUser();
    return 0;
}
