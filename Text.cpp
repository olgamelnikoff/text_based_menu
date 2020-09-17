#include <iostream>
#include <cstring>
#include <string>
#include "Text.h"

using std::cout;
using std::endl;
using std::strcpy;

//conversion constructor
Text::Text(const char* pCstr) {
    this->pStore = new char[strlen(pCstr) + 1]; //allocating memory
    strcpy(pStore, pCstr);
}

//default constructor
Text::Text() : Text{ "" } {}

//copy constructor
Text::Text(const Text& txt) : Text{ txt.pStore } {}

//destructor
Text:: ~Text() {
    delete[] this->pStore; //releasing memory
    this->pStore = nullptr; //defensive programming
}

//assignment operator overload
Text& Text::operator=(const Text& txt) {
    if (this != &txt) {
        delete[] pStore; //releasing dynamic storage
        this->pStore = new char[strlen(txt.pStore) + 1];
        strcpy(this->pStore, txt.pStore);
    }
    return *this;
}

void Text::assign(const char* pCstr) {
    delete[] this->pStore; //releasing dynamic storage
    this->pStore = new char[strlen(pCstr) + 1];
    strcpy(pStore, pCstr);
}
void Text::assign(const Text& txt) {
    delete[] this->pStore; //releasing dynamic storage
    this->pStore = new char[strlen(txt.pStore)];
    strcpy(this->pStore, txt.pStore);
}
void Text::append(const char* pCstr) {
    //if the array is empty:
    if (strlen(pStore) == 0) {
        assign(pCstr);
        return;
    }
    //saving the current content to a temp var if the array is not empty
    char* temp = new char[strlen(pStore) + 1];
    strcpy(temp, pStore);
    
    //determining the size of the new string
    unsigned long size = strlen(pStore) + strlen(pCstr) + 1;
    
    //releasing dynamic storage
    delete[] this->pStore;
    
    //allocating enough memory for pStore
    pStore = new char[size];
    
    //copying the current content back to pStore
    strcpy(pStore, temp);
    
    //adding new content to pStore
    strcat(pStore, pCstr);
}

void Text::append(const Text& txt) {
    append(txt.pStore);
}

void Text::clear() {
    pStore[0] = '\0';
}

int Text::length() const {
    int stringLength = static_cast<int>(strlen(pStore));
    return stringLength;
}
bool Text::isEmpty() const {
    if (strlen(pStore) == 0) {
        return true;
    }
    return false;
}
const char* Text::getCstring() const {
    return pStore;
}

ostream& operator<<(ostream& sout, const Text& txt) {
    sout << txt.getCstring();
    return sout;
}
