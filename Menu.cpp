#include <iostream>
#include <cstring>
#include <string>
#include <ostream>
#include "Text.h"
#include "Menu.h"

using std::cout;
using std::cin;
using std::endl;
using std::strcpy;
using std::ostream;
using std::to_string;
using std::size_t;
using std::out_of_range;
using std::string;

 //default constructor;
//initializing all the data members
Menu::Menu() {
    option_list = new Text[1];
    option_list[0] = Text();
    capacity = 1;
    count = 0;
    top_message = Text();
    bottom_message = Text();
}

//The "Big Three"
//copy constructor:
Menu::Menu(const Menu& mnu) {
    delete[] this->option_list; // releasing current storage
    
    //copying the mnu data members into the object being constructed
    this->option_list = new Text[mnu.capacity];
    for (int i{ 0 }; i < count; ++i) {
        option_list[i] = mnu.option_list[i];
    }
    this->capacity = mnu.capacity;
    this->count = mnu.count;
    this->top_message = mnu.top_message;
    this->bottom_message = mnu.bottom_message;
}

//destructor:
Menu::~Menu() {
    delete[] option_list; //releasing memory
    this->option_list = nullptr; //defensive programming
}

//assignment operator overload
Menu& Menu::operator=(const Menu& m) {
    if (this != &m) { //do nothing on self-assignment
        delete[] this->option_list; //release dynamic storage
        //allocate storage of appropriate size
        this->option_list = new Text[m.capacity];
        this->capacity = m.capacity;
        this->count = m.count;
        this->top_message = m.top_message;
        this->bottom_message = m.bottom_message;
        for (int i{ 0 }; i < count; ++i) {
            option_list[i] = m.option_list[i];
        }
    }
    return *this;
}

 //Overloading operator << using toString() function
ostream& operator <<(ostream& output, const Menu& m) {
    output << m.toString() << endl;
    return output;
}

//two "insert" methods inserting a new option at position "index - 1",
//shifting all options at or past 'index - 1' over to the right
//by one position
void Menu::insert(int index, const Text& option) {
    
    //index entered by user should be less or equal to count, but not less
    //than 1
    if ((index >= 1) && (index <= count)) {
        
        //if there is no more space available
        //for inserting a new element, double the capacity
        if (count == capacity) {
            double_capacity();
        }
        
        //incrementing count by 1
        count++;
        
        //shifting all options at or past 'index - 1' over to the right
        //by one position
        for (int i{ size() - 1 }; i > (index - 1); --i) {
            option_list[i] = option_list[i - 1];
        }
        
        //inserting the new option at position 'index - 1'
        option_list[index - 1] = option;
        
        //printing a message confirming that the option has been inserted
        cout << "Option \"" << option << "\" inserted successfully!\n" << endl;
    }
    
    //if index entered by user is beyond count, display an error message
    else {
        cout << "Invalid menu position " << index
            << ". It must be in the range [1,"
            << size() << "]." << endl;
    }
}

void Menu::insert(int index, const char* option) {
    
    //index entered by user should be less or equal to count, but not less
    //than 1
    if ((index >= 1) && (index <= count)) {
        
        //if there is no more space available
        //for inserting a new element, double the capacity
        if (count == capacity) {
            double_capacity();
        }
        
        //incrementing count by 1
        count++;
        
        //shifting all options at or past 'index - 1' over to the right
        //by one position
        for (int i{ size() - 1 }; i > (index - 1); --i) {
            option_list[i] = option_list[i - 1];
        }
        
        //inserting the new option at position 'index - 1'
        option_list[index - 1].assign(option);
        
        //printing a message confirming that the option has been inserted
        cout << "Option \"" << option << "\" inserted successfully!\n" << endl;
    }
    
    //if index entered by user is beyond count, display an error message
    else {
        cout << "Invalid menu position " << index
            << ". It must be in the range [1,"
            << size() << "]." << endl;
    }
}

//two "push_back" methods adding supplied option to the end
//of the option list
void Menu::push_back(const char* pOption) {
    
    //if there is no more space available
    //for inserting a new element, double the capacity
    if (count == capacity) {
        double_capacity();
    }
    
    //adding the new option to the end of the option list
    option_list[count].assign(pOption);
    
    //incrementing count by 1
    count++;
}

void Menu::push_back(const Text& option) {
    
    //if there is no more space available
    //for inserting a new element, double the capacity
    if (count == capacity) {
        double_capacity();
    }
    
    //adding the new option to the end of the option list
    option_list[count] = option;
    
    //incrementing count by 1
    count++;
    
}

//removing an option from the list at position "index - 1",
//shifting all options at or past 'index - 1' over to the left
//by one position
void Menu::remove(int index) {
    
    //index entered by user should be less or equal to count, but not less
    //than 1
    if ((index >= 1) && (index <= count)) {
        
        //if count > 1, the final array will not be empty
        //after we remove 1 element,
        //so we do shifting all options at or past 'index - 1'
        //over to the left by one position
        if (count > 1) {
            for (int i{ index - 1 }; i < size() - 1; ++i) {
                option_list[i] = option_list[i + 1];
            }
        }
        
        //after all the elements have been shifted to the left,
        //we need to clear the last position in the array
        option_list[size() - 1].clear();
        
        //decrementing the count by 1
        count--;
    }
    
    //if index entered by user is beyond count, display an error message
    else {
        cout << "Invalid menu position " << index
            << ". It must be in the range [1,"
            << size() << "]." << endl;
    }
}

//returns the number of options in the options list (count):
int Menu::size() const {
    return this->count;
}

//returns the current capacity of the option list
int Menu::getCapacity() const {
    return this->capacity;
}

//removes the last option from the list:
void Menu::pop_back() {
    
    //displaying an error if the list is empty.
    if (isEmpty()) {
        cout << "Error: nothing to pop back. The list is empty.";
    }
    
    //clearing the last position in the array
    else {
        option_list[size() - 1].clear();
        
        //decrementing the count by 1
        count--;
    }
}

//returns the option at position 'k - 1'
Text Menu::get(int k) {
    //'k' entered by user should be less or equal to count, but not less
    //than 1
    if (k < 1 || k > count) {
        throw out_of_range("No such option");
    }
    return option_list[k - 1];
}

//returns a Text object storing
//a string representation of this menu
Text Menu::toString() const {
    
    //introducing a Text variable to hold
    //the entire menu
    Text stringRepOfMenu;
    
    //appending Text objects one-by-one to the stringRepOfMenu
    stringRepOfMenu.append(top_message);
    stringRepOfMenu.append("\n");
    
    //Adding menu options from option list to the stringRepOfMenu
    //using a for-loop
    for (int i{ 0 }; i < count; ++i) {
        
        //first, converting the number i to a regular string
        string numberAsString = to_string(i + 1);
        
        //second, converting the regular string to a C-string
        const char * numberAsCString = new char[numberAsString.size() + 1];
        numberAsCString = numberAsString.c_str();
        
        stringRepOfMenu.append("  ");
        
        //adding the number of the current o`ption to the Menu
        stringRepOfMenu.append(numberAsCString);
        stringRepOfMenu.append(":  ");
        
        //adding the current option itself to the Menu
        stringRepOfMenu.append(option_list[i]);
        stringRepOfMenu.append("\n");
    }
    
    //adding the rest of the Menu to the stringRepOfMenu
    stringRepOfMenu.append(bottom_message);
    stringRepOfMenu.append("\n");
    stringRepOfMenu.append("??");
    
    //returning the final string representation of menu
    return stringRepOfMenu;
}

//displays this menu and then reads
//and returns a valid option number
int Menu::read_option_number() {
    
    //first, returning the menu representation using toString()
    cout << this->toString() << endl;
    
    //introducing a variable to hold the user entry
    int userEntry;
    cin >> userEntry;
    
    //if the index entered by user is beyond count, displaying
    //an error message and printing the menu again
    //for the user to make another choice
    if (count > 0 && (userEntry > count || userEntry < 1)) {
        cout << "Invalid choice " << userEntry
            << ". It must be in the range [1, "
            << count << "]." << endl;
        
        //in case of incorrect user input, calling the method again
        userEntry = read_option_number();
    }
    return userEntry;
}

//setting the top message
void Menu::set_top_message(const Text& m) {
    this->top_message.assign(m);

}

//setting the top message
void Menu::set_top_message(const char* pM) {
    this->top_message.assign(pM);

}

//setting the bottom message
void Menu::set_bottom_message(const Text& m) {
    this->bottom_message.assign(m);
}

//setting the bottom message
void Menu::set_bottom_message(const char* pM) {
    this->bottom_message.assign(pM);

}

//clearing the top message
void Menu::clear_top_message() {
    this->top_message.clear();
}

//clearing the bottom message
void Menu::clear_bottom_message() {
    this->bottom_message.clear();
}

//determines if this menu's option list is empty
bool Menu::isEmpty() const {
    if (count == 0) {
        return true;
    }
    return false;
}

//doubles the current capacity of the options list
void Menu::double_capacity() {
    int twice_cap = 2 * this->getCapacity();    // new desired capacity
    
    // allocating space twice the current capacity
    Text* temp = new Text[twice_cap];
    
    // assigning current option list to temp, element by element
    for (std::size_t i = 0; i < this->getCapacity(); i++) {
        
        // Text's operator= performs the assignment
        temp[i] = this->option_list[i];
    }
    delete[] this->option_list;         // releasing current storage
    this->option_list = temp;           // pointing at new storage
    this->capacity = twice_cap;         // adjusting capacity
}
