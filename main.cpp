#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook;
    addressBook.registerUser();
    addressBook.readAllAddresses();
    return 0;
}
