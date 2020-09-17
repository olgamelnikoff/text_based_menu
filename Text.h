#ifndef TEXT_H
#define TEXT_H

#include <iostream>
using std::ostream;

class Text {
private:
    char* pStore; //pointer to dynamic memory
public:
    Text(); //default constructor
    Text(const char*); //conversion constructor

    //The "Big Three"
    Text(const Text&); //copy constructor
    ~Text(); //destructor
    Text& operator=(const Text&); //assignment operator overload
    
    //assigns a C-string to 'this' object, replacing the current content
    void assign(const char*);
    
    //assigns a Text object to 'this' object, replacing the current content
    void assign(const Text&);
    
    //appends a C-string to 'this' object, extending its content
    void append(const char*);
    
    //appends a Text object to 'this' object, extending its content
    void append(const Text&);
    
    //erases the content of the C-string in 'this' object, which becomes an empty C-string
    void clear();
    
    //returns the length of 'this' object's text
    int length() const;
    
    //determines whether 'this' object represents a C-string of length zero
    bool isEmpty() const;
    
    //returns pStore as a const pointer
    const char* getCstring() const;
};

//insertion operator overload
ostream& operator<<(ostream& sout, const Text& txt);
#endif /* TEXT_H */
