#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <cstring>
#include "Text.h"

using std::ostream;

class Menu {
private:
    Text* option_list; //pointer to dynamic array of Text objects
    int capacity; //the current length of the options list dynamic array
    int count; //the actual number of options in the option list
    Text top_message; //the opening message
    Text bottom_message; //the closing message
    
    //doubles the current capacity of the options list
    void double_capacity();
public:
    Menu(); //default constructor

    //The "Big Three":
    Menu(const Menu&); //copy constructor
    virtual ~Menu(); //destructor
    Menu& operator=(const Menu&); //assignment operator overload

    //insertion operator overload as a friend member:
    friend ostream& operator <<(ostream&, const Menu&);
    
    //two "insert" methods inserting a new option to the list
    //at a certain position
    void insert(int, const char*);
    void insert(int, const Text&);
    
    //two "push_back" methods adding supplied option to the end
    //of the option list
    void push_back(const char*);
    void push_back(const Text&);
    
    //removes an option at a certain position from the list
    void remove(int);
    
    //returns the number of options in the option list (count):
    int size() const;
    
    //returns the current capacity of the option list
    int getCapacity() const;
    
    //removes the last option from the list:
    void pop_back();
    
    //returns the option at a certain position
    Text get(int);
    
    //returns a Text object storing
    //a string representation of this menu
    Text toString() const;
    
    //displays this menu and then reads
    //and returns a valid option number
    int read_option_number();
    
    //sets top message
    void set_top_message(const Text&);
    void set_top_message(const char*);
    
    //sets bottom message
    void set_bottom_message(const Text&);
    void set_bottom_message(const char*);
    
    //sets top message to empty text
    void clear_top_message();
    
    //sets bottom message to empty text
    void clear_bottom_message();
    
    //determines if this menu's option list is empty
    bool isEmpty() const;
};

#endif /* MENU_H */
