//
// Created by billy on 11/23/2021.
//

#include "contact.h"

Contact::Contact() {
    this -> next = nullptr;
}

//Overloaded constructor
Contact::Contact(int id, string name, string streetAddress, string city, string state, string zip, string phone){
    this->id = id;
    this->name = name;
    this->streetAddress = streetAddress;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
    this->next = nullptr;
}

//Copy constructor
Contact::Contact(const Contact &origObj) {
    this->id = origObj.id;
    this->name = origObj.name;
    this->streetAddress = origObj.streetAddress;
    this->city = origObj.city;
    this->state = origObj.state;
    this->zip = origObj.zip;
    this->phone = origObj.phone;
    this->next = nullptr;
}

Contact::~Contact() {
    this->next = nullptr;
}
int Contact::GetID() {
    return id;
}

void Contact::SetID(int id) {
    this->id = id;
}

Contact* Contact::GetNext() {
    return next;
}

void Contact::SetNext(Contact *next) {
    this->next = next;
}

string Contact::GetName() {
    return name;
}

string Contact::GetStreetAddress() {
    return streetAddress;
}

string Contact::GetCity() {
    return city;
}

string Contact::GetState() {
    return state;
}

string Contact::GetZip() {
    return zip;
}

string Contact::GetPhone() {
    return phone;
}

Contact& Contact::operator=(const Contact &objToCopy) {
    if(this != &objToCopy){
        this->id = objToCopy.id;
        this->name = objToCopy.name;
        this->streetAddress = objToCopy.streetAddress;
        this->city = objToCopy.city;
        this->state = objToCopy.state;
        this->zip = objToCopy.zip;
        this->phone = objToCopy.phone;
        this->next = objToCopy.next;
    }
    return *this;
}