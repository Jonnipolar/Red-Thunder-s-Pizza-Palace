#include "Manager_Sub_UI.h"

Manager_Sub_UI::Manager_Sub_UI()
{
    //ctor
}
void Manager_Sub_UI::UI_Start() {
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
void Manager_Sub_UI::UI_make_toppings() {
    string name;
    int price;
    char type;
    cout << "Please type in topping" << endl;
    cout << "Name: ";
    cin >> ws;                                                                      // ws needed to clear before getline
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
    cout << "Type: \n\tm for meat\n\tv for vegetable\n\tc for cheese" << endl;
    cin >> type;
    MakeToppingsList topping(name, price, type);                                    // sendir inn í færubreytusmið
    topping.save_topping_list(topping);                                             // sendir í function sem vistar í skjal
}
Manager_Sub_UI::~Manager_Sub_UI()
{
    //dtor
}
