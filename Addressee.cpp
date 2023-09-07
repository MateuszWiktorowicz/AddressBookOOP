#include "Addressee.h"

    void Addressee::setId(int newId)
    {
        id = newId;
    }
    void Addressee::setUserId(int UserId)
    {
        userId = UserId;
    }

    void Addressee::setName(string Name)
    {
        name = Name;
    }

    void Addressee::setSurname(string Surname)
    {
        surname = Surname;
    }

    void Addressee::setPhone(string Phone)
    {
        phone = Phone;
    }

    void Addressee::setEmail(string Email)
    {
        email = Email;
    }

    void Addressee::setAddress(string Address)
    {
        address = Address;
    }

    int Addressee::getId()
    {
        return id;
    }

    int Addressee::getUserId()
    {
        return userId;
    }

    string Addressee::getName()
    {
        return name;
    }

    string Addressee::getSurname()
    {
        return surname;
    }

    string Addressee::getPhone()
    {
        return phone;
    }

    string Addressee::getEmail()
    {
        return email;
    }

    string Addressee::getAddress()
    {
        return address;
    }
