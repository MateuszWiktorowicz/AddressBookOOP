#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class AddressBook
{
    int idLoggedInUser;
    int idLastAddress;
    int idDeletedAddress;

    vector <User> users;

public:
    void registerUser();
};
