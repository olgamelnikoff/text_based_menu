#include <iostream>
#include <cstring>
#include "Text.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::cerr;

int main()
{
    //Mandatory test:
    //lines 1-32 of the code snippets used on pages 6-9
    //of the Assignment document
    Menu menu;
    cout << menu << endl;
    int choice = menu.read_option_number();
    cout << "you entered: " << choice << endl;
    
    menu.push_back("Pepsi");
    cout << menu << endl;

    menu.push_back("Apple juice");
    menu.push_back("Root beer");
    choice = menu.read_option_number();
    cout << "you entered: " << choice << endl;

    menu.set_top_message("Choose your thirst crusher");
    menu.set_bottom_message("Enter a drink number");
    cout << menu << endl;

    menu.pop_back();
    menu.insert(2, "Iced tea with lemon");
    choice = menu.read_option_number();
    cout << "you entered: " << choice << endl;

    menu.pop_back();
    menu.remove(1);
    cout << menu << endl;

    menu.pop_back();
    cout << menu << endl;

    menu.clear_bottom_message();
    menu.set_top_message("Who Says You Can't Buy Happiness?\n"
        "Just Consider Our Seriously Delicious Ice Cream Flavors");
    menu.set_bottom_message("Enter the number of your Happiness! ");

    menu.push_back("Bacon ice cream");
    menu.push_back("Strawberry ice cream");
    menu.push_back("Vanilla ice cream");
    menu.push_back("Chocolate chip cookie dough ice cream");
    choice = menu.read_option_number();
    cout << "you entered: " << choice << endl;
    
    /*
    //Additional (non-mandatory) tests
    //of other methods of class Menu
    
    //Testing "insert()" method with a C-string as an argument:
    Text t1("Garlic ice cream");
    menu.insert(3, t1);
    
    //Testing error message of "insert()" method
    menu.insert(10, "Melon ice cream");
    
    //Testing "push_back()" method with a C-string as an argument:
    Text t2("Pineapple ice cream");
    menu.push_back(t2);
    cout << menu << endl;
    
    //Testing error message of "remove()" method
    menu.remove(12);
    
    //Testing "size()", "getCapacity()" and "get()" methods
    cout << "The current size of menu (count of its options) is " << menu.size() << endl;
    cout << "The current menu capacity is " << menu.getCapacity() << endl;
    cout << "The item at position 2 is " << menu.get(2) << endl;
    
    
    //Testing error message of "get()" method using try-catch:
    try {
        Text t = menu.get(19);
        cout << "The option at index 19 is: " << t << endl;
    }

    catch (const std::out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << "\n";
    }

    try {
        Text t = menu.get(4);
        cout << "The item at position 4 is: " << t << endl;
    }

    catch (const std::out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << "\n";
    }
    
    //Testing "clear_top_message()", "clear_bottom_message()"
    //and "toString()" methods
    menu.clear_top_message();
    menu.clear_bottom_message();
    cout << menu.toString() << endl;
    
    //Testing "isEmpty()" method
    Menu newMenu;
    cout << "Is the newMenu empty?" << endl;
    
    if (newMenu.isEmpty() == 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
     */
    return 0;
}
