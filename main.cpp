#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt", "Addressees.txt");
   // addressBook.registerUser();
    addressBook.loginUser();
    addressBook.insertNewAddressee();
    addressBook.readAllAddresses();
    addressBook.logoutUser();


    return 0;
}
