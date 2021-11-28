//
// Created by billy on 11/23/2021.
//

#ifndef PROGRAM5_CONTACT_H
#define PROGRAM5_CONTACT_H

#include <iostream>
#include <string>


using namespace std;

class Contact{

    // NOTE TO THE STUDENT
    // You may NOT add "Set" values to the Contact class
    // This is to force you to use link lists the correct way

public:
    //Constructors
    Contact();
    Contact(int id, string name, string streetAddress, string city, string state, string zip, string phone);
    Contact(const Contact &origObj);
    //Destructor
    ~Contact();

    int GetID();
    void SetID(int id);

    Contact * GetNext();
    void SetNext(Contact * next);

    string GetName();
    string GetStreetAddress();
    string GetCity();
    string GetState();
    string GetZip();
    string GetPhone();

    //assignment operator
    Contact& operator=(const Contact &objToCopy);

private:

    int id;
    string name;
    string streetAddress;
    string city;
    string state;
    string zip;
    string phone;
    Contact * next;

};

#endif //PROGRAM5_CONTACT_H
