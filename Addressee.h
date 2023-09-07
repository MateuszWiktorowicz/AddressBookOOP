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
    void setUserId(int UserId);
    void setName(string Name);
    void setSurname(string Surname);
    void setPhone(string Phone);
    void setEmail(string Email);
    void setAddress(string Address);

    int getId();
    int getUserId();
    string getName();
    string getSurname();
    string getPhone();
    string getEmail();
    string getAddress();

};

#endif
