#include "ManagerSubUI.h"

ManagerSubUI::ManagerSubUI()
{
    //ctor
}
void ManagerSubUI::UI_Start() {
    char selection;                                                         // Declare selection char
    while (selection != '6') {                                              // While user does not want to quit
        cout << "\nHello Mr. Manager" << endl;                              // Welcome message
        cout << "What would you like to do:" << endl;                       // -||-
        cout << "1: Make pizza" << endl;                                    // Menu for user to pick
        cout << "2: Make topping" << endl;                                  // ------""-------------
        cout << "3: Create menu" << endl;                                   // ------""-------------
        cout << "4: Add other items" << endl;                               // ------""-------------
        cout << "5: Add pizza place" << endl;                               // ------""-------------
        cout << "6: Quit" << endl;                                          // ------""-------------
        cin >> selection;
        if (selection == '1') {                                                     // if user picks p create pizza

        }
        else if (selection == '2') {                                               // if user picks t create topping
            UI_make_toppings();

        }
        else if (selection == '3') {                                               // if user picks m Create menu

        }
        else if (selection == '4') {                                               // if user picks i Add other items (soda, breadsticks etc.)

        }
        else if (selection == '5') {                                               // if user picks a Add a pizza place to choose

        }
    }
}
void ManagerSubUI::UI_make_toppings() {
    string name;
    int price;
    int type;
    cout << "Please type in topping" << endl;
    cout << "Name: ";
    cin >> ws;                                                                      // ws needed to clear before getline
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
    cout << "Type: \n\t1 for meat\n\t2 for vegetable\n\t3 for cheese" << endl;
    cin >> type;
    Toppings topping(name, price, type);                                    // sendir inn í færubreytusmið
    toppings_list.save_topping_list(topping);                                      // sendir í function sem vistar í skjal
}
ManagerSubUI::~ManagerSubUI()
{
    //dtor
}
