//
// Created by billy on 11/23/2021.
//

#include "rolodex.h"

Rolodex::Rolodex() {
    // create a dummy Contact at the head of the Rolodex
    head = new Contact;
}

Rolodex::~Rolodex(){
    Contact * current = head;
    while(current != nullptr){
        Contact * next = current->GetNext();
        delete current;
        current = next;
    }
    head = nullptr;
}

int Rolodex::LoadFromFile(string filename) {
    ifstream file(filename);

    if(!file.is_open()){
        return -1;
    }

    string line;
    int id = 1;
    Contact * current = head;

    // first line is header row
    getline(file, line);

    while(getline(file, line)){
        stringstream ss(line);
        string first_name, last_name, company_name, address;
        string city, county, state, zip, phone1, phone, email;

        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, company_name, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, county, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');
        getline(ss, phone1, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');

        Contact * contact = new Contact(
                id,
                last_name + ", " + first_name,
                address,
                city,
                state,
                zip,
                phone);

        current->SetNext(contact);
        current = current->GetNext();
        id++;
    }

    file.close();

    return this->Length();
}

void Rolodex::AddContact(string name, string streetAddress, string city, string state, string zip, string phone) {
    // find the last Contact in the Rolodex
    Contact * current = head->GetNext();
    Contact * previous = head;
    int maxID = 0;
    while(current != nullptr){
        if(current->GetID() > maxID){
            maxID = current->GetID();
        }
        previous = previous->GetNext();
        current = current->GetNext();
    }

    // instantiate new Contact
    previous->SetNext(new Contact(maxID + 1, name, streetAddress, city, state, zip, phone));
}

int Rolodex::Length() {
    Contact * current = head->GetNext();
    int length = 0;
    while(current != nullptr){
        length++;
        current = current->GetNext();
    }
    return length;
}

void Rolodex::DeleteContact(int id) {
    // TODO by student: complete the function below
    Contact *current = head -> GetNext();
    Contact *previous = head;

    while(current != nullptr){
        if(current->GetID() == id){
            //assign previous-next to current-next
            previous->SetNext(current->GetNext());

            //delete current node
            delete current;
            break;
        }
        current = current->GetNext();
        previous = previous->GetNext();
    }
}

int Rolodex::GetMaxID() {
    Contact * current = head->GetNext();
    int maxID = 0;
    while(current != nullptr){
        if(maxID < current->GetID()){
            maxID = current->GetID();
        }
        current = current->GetNext();
    }
    return maxID;
}

void Rolodex::DuplicateContact(int id) {
    // Duplicate must utilize a copy constructor that you have added to the Contact class.
    // Take extra care that you are actually calling the copy constructor and you aren't
    // doing a shallow copy.

    // TODO by student: complete the function below

    //Find to-be-copied contact
    Contact *copiedContact = FindContactByID(id);

    //Clone it using copy constructor
    Contact tempCopy = *copiedContact;

    //add it to the list using "AddContact" member function
    AddContact(tempCopy.GetName(),
               tempCopy.GetStreetAddress(),
               tempCopy.GetCity(),
               tempCopy.GetState(),
               tempCopy.GetZip(),
               tempCopy.GetPhone());

    //Function goes out of scope, and "tempCopy"
    //will get wiped of the stack. :)
}

Contact* Rolodex::FindContactByID(int id) {
    Contact * current = head->GetNext();
    while(current != nullptr){
        if(id == current->GetID()){
            return current;
        }
        current = current->GetNext();
    }
    return current;
}

bool Rolodex::IDExists(int id) {
    Contact * current = head->GetNext();
    while(current != nullptr){
        if(id == current->GetID()){
            return true;
        }
        current = current->GetNext();
    }
    return false;
}

void Rolodex::UpdateContact(int id, string name, string streetAddress, string city, string state, string zip,
                            string phone) {
    // The update function must use an assignment operator overload
    // that you have added to the Contact class.
    // Take extra care that you are actually calling the assignment overload
    // and you aren't doing a shallow copy.
    // Be careful that you update the "next" pointer and ID appropriately.

    Contact * updatee = FindContactByID(id);
    Contact updator(updatee->GetID(), name, streetAddress, city, state, zip, phone);

    // TODO by student: complete the function below
    //Make sure updator "next" ptr is the same as updatee's
    //because its default value is "nullptr" according to
    //Contact::Contact(id, name, ..., phone)
    updator.SetNext(updatee->GetNext());

    //update "updatee" with values from "updator"
    // using assignment operator.
    *updatee = updator;

    //Function goes out of scope and "updator"
    //goes gets wiped of the stack. :)
}

void Rolodex::SortBy(Field field) {

    // TODO by student: complete the function below
    //I intend to you the Insertion sort algorithm
    //(for simplicity and time constraint)
    //to sort from smallest to greatest.
    //Merge sort is a better option.

    switch (field) {
        case ID:{
            Contact *prevX = head;
            Contact *X = head->GetNext();

            //This portion of code will get the smallest node
            //The smallest node will be assigned the pointer small
            while(X != nullptr){

                Contact *prevY = prevX->GetNext();
                Contact *Y = X->GetNext();

                //smallest node is set to X
                Contact *prevSmall = prevX;
                Contact *Small = X;

                while(Y != nullptr){
                    //if "Y" comes before "Small" alphabetically
                    if(Y->GetID() < Small->GetID()){
                        prevSmall = prevY;
                        Small = Y;
                    }

                    //update Y pointer for next iteration
                    prevY = prevY->GetNext();
                    Y = Y->GetNext();
                }

                //At this point, we have the smallest node for this
                //iteration
                //swap nodes X and Smallest
                SwapNodes(prevX, X, prevSmall, Small);

                //update X pointer for next iteration
                prevX = prevX->GetNext();
                X = X->GetNext();
            }
        }
            break;

        case NAME:{
            Contact *prevX = head;
            Contact *X = head->GetNext();

            //This portion of code will get the smallest node
            //The smallest node will be assigned the pointer small
            while(X != nullptr){

                Contact *prevY = prevX->GetNext();
                Contact *Y = X->GetNext();

                //smallest node is set to X
                Contact *prevSmall = prevX;
                Contact *Small = X;

                while(Y != nullptr){
                    //if "Y" comes before "Small" alphabetically
                    if(Y->GetName() < Small->GetName()){
                        prevSmall = prevY;
                        Small = Y;
                    }

                    //update Y pointer for next iteration
                    prevY = prevY->GetNext();
                    Y = Y->GetNext();
                }
                //At this point, we have the smallest node for this
                //iteration

                //swap nodes X and Smallest
                SwapNodes(prevX, X, prevSmall, Small);

                //update X pointer for next iteration
                prevX = prevX->GetNext();
                X = X->GetNext();
            }

        }
            break;

        case CITY:{
            Contact *prevX = head;
            Contact *X = head->GetNext();

            //This portion of code will get the smallest node
            //The smallest node will be assigned the pointer small
            while(X != nullptr){

                Contact *prevY = prevX->GetNext();
                Contact *Y = X->GetNext();

                //smallest node is set to X
                Contact *prevSmall = prevX;
                Contact *Small = X;

                while(Y != nullptr){
                    //if "Y" comes before "Small" alphabetically
                    if(Y->GetCity() < Small->GetCity()){
                        prevSmall = prevY;
                        Small = Y;
                    }

                    //update Y pointer for next iteration
                    prevY = prevY->GetNext();
                    Y = Y->GetNext();
                }
                //At this point, we have the smallest node for this
                //iteration

                //swap nodes X and Smallest
                SwapNodes(prevX, X, prevSmall, Small);

                //update X pointer for next iteration
                prevX = prevX->GetNext();
                X = X->GetNext();
            }
        }
            break;

        case STATE:{

            Contact *prevX = head;
            Contact *X = head->GetNext();

            //This portion of code will get the smallest node
            //The smallest node will be assigned the pointer small
            while(X != nullptr){

                Contact *prevY = prevX->GetNext();
                Contact *Y = X->GetNext();

                //smallest node is set to X
                Contact *prevSmall = prevX;
                Contact *Small = X;

                while(Y != nullptr){
                    //if "Y" comes before "Small" alphabetically
                    if(Y->GetState() < Small->GetState()){
                        prevSmall = prevY;
                        Small = Y;
                    }

                    //update Y pointer for next iteration
                    prevY = prevY->GetNext();
                    Y = Y->GetNext();
                }
                //At this point, we have the smallest node for this
                //iteration

                //swap nodes X and Smallest
                SwapNodes(prevX, X, prevSmall, Small);

                //update X pointer for next iteration
                prevX = prevX->GetNext();
                X = X->GetNext();
            }
        }
            break;

        case ZIP:{

            Contact *prevX = head;
            Contact *X = head->GetNext();

            //This portion of code will get the smallest node
            //The smallest node will be assigned the pointer small
            while(X != nullptr){

                Contact *prevY = prevX->GetNext();
                Contact *Y = X->GetNext();

                //smallest node is set to X
                Contact *prevSmall = prevX;
                Contact *Small = X;

                while(Y != nullptr){
                    //if "Y" comes before "Small" alphabetically
                    if(Y->GetZip() < Small->GetZip()){
                        prevSmall = prevY;
                        Small = Y;
                    }

                    //update Y pointer for next iteration
                    prevY = prevY->GetNext();
                    Y = Y->GetNext();
                }
                //At this point, we have the smallest node for this
                //iteration

                //swap nodes X and Smallest
                SwapNodes(prevX, X, prevSmall, Small);

                //update X pointer for next iteration
                prevX = prevX->GetNext();
                X = X->GetNext();
            }
        }
            break;
    }
}

void Rolodex::PrintContact(Contact *contact) {
    if(contact == nullptr) {
        cout << "NULLPTR" << endl;
        return;
    }
    if(contact == head){
        cout << "HEAD" << endl;
        return;
    }

    cout << setw(5) << contact->GetID();
    cout << setw(22) << contact->GetName();
    cout << setw(50) <<
         contact->GetStreetAddress() + ", " +
         contact->GetCity() + " " +
         contact->GetState() + " " +
         contact->GetZip();
    cout << setw(15) << contact->GetPhone();
    cout << endl;
}

void Rolodex::PrintRolodex() {
    Contact * current = head->GetNext();
    cout << setw(5) << "ID";
    cout << setw(22) << "Name";
    cout << setw(50) << "Address";
    cout << setw(15) << "Phone";
    cout << endl;
    cout << "----------------------------------------------";
    cout << "----------------------------------------------";
    cout << endl;
    while(current != nullptr){
        PrintContact(current);
        current = current->GetNext();
    }
}

void Rolodex::SwapNodes(Contact *&prevX, Contact *&X, Contact *&prevY, Contact *&Y) {

    //The portion of code below will swap two nodes x, and y
    //Assume that x ALWAYS comes BEFORE y

    if(X != Y){
        prevX->SetNext(Y);
        Contact *temp = Y->GetNext();
        Y->SetNext(X);
        prevY->SetNext(temp);

        //IMPORTANT NOTICE: After swap, X pointer must be reassigned
        //before the next iteration. Otherwise: Seg fault.
        //See drawing for explicit explanation
        X = Y;
    }
    else{
        //X and Y point to the same
        //memory location, we
        //DO NOTHING
    }
}