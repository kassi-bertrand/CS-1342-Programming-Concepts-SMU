//
// Created by billy on 11/23/2021.
//

#ifndef PROGRAM5_ROLODEX_H
#define PROGRAM5_ROLODEX_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "contact.h"

enum Field {ID, NAME, CITY, STATE, ZIP};

class Rolodex{
public:

    Rolodex();
    ~Rolodex();

    int LoadFromFile(string filename);

    void AddContact(string name, string streetAddress, string city, string state, string zip, string phone);

    int Length();

    void DeleteContact(int id);

    int GetMaxID();

    void DuplicateContact(int id);

    Contact * FindContactByID(int id);

    bool IDExists(int id);

    void UpdateContact(int id, string name, string streetAddress, string city, string state, string zip, string phone);

    void SortBy(Field field);

    void PrintContact(Contact * contact);

    void PrintRolodex();

private:
    Contact * head;
    static void SwapNodes(Contact *&prevX, Contact *&X, Contact *&prevY, Contact *&Y);
};


#endif //PROGRAM5_ROLODEX_H
