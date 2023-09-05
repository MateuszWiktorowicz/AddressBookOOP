#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt");
    //addressBook.registerUser();
    addressBook.readAllAddresses();
    return 0;
}
