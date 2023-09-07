#ifndef ADDRESSEE_H
#define ADDRESSEE_H

#include <iostream>

using namespace std;

class Addressee
{
    int id, userId;
    string name, surname, phone, email, address;
public:
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getLogin();
    string getPassword();
};

#endif
