#include "ManagerSubUI.h"

ManagerSubUI::ManagerSubUI()
{
    //ctor
}
void ManagerSubUI::UI_Start() {
    char selection;                                                         // Declare selection char
    while (selection != '6') {                                              // While user does not want to quit
        system("CLS");
        cout << "Hello Mr. Manager" << endl;                              // Welcome message
        cout << "What would you like to do:" << endl;                       // -||-
        cout << "1: Make pizza" << endl;                                    // Menu for user to pick
        cout << "2: Make topping" << endl;                                  // ------""-------------
        cout << "3: Create menu" << endl;                                   // ------""-------------
        cout << "4: Add other items" << endl;                               // ------""-------------
        cout << "5: Add pizza place" << endl;                               // ------""-------------
        cout << "6: Quit" << endl;                                          // ------""-------------
        cin >> selection;
        switch (selection) {
            case '1':                                                   // if user picks p create pizza
                system("CLS");
                cout << "1: Make new size" << endl;
                cout << "2: Make new bottom" << endl;
                cout << "3: Make Pizza" << endl;
                cin >> selection;
                switch (selection) {
                    case '1':
                        UI_make_size();
                        break;
                    case '2':                                            // if user picks t create topping
                        UI_make_toppings();
                        break;
                    case '3':                                               // if user picks m Create menu
                        UImake_pizza();
                        break;
                }
                break;
            case '2':
                UI_make_toppings();
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                UI_make_pizza_place();
                break;
        }
    }
}
void ManagerSubUI::UImake_pizza() {
    Pizza pizza;
    string name;
    /*
    vector <Toppings> cheeseTopp = toppings_list.get_cheese_list();
    vector <Toppings> meatTopp = toppings_list.get_meat_list();
    vector <Toppings> vegetableTopp = toppings_list.get_vegetable_list();
    */
    vector <Toppings> toppings = toppings_list.get_topping_list();
    //int ToppingAmount = cheeseTopp.size() + meatTopp.size() + vegetableTopp.size();
    system("CLS");

    cout << "Break" << endl;
    cout << toppings[0].get_price() << endl;
    cout << toppings[1].get_price() << endl;
    cout << "/Break" << endl;
    cout << "Please type in pizza name" << endl;
    cout << "Pizza: ";
    cin >> name;

    int ToppSel = -1;
    while (ToppSel != 0) {
        int cntr = 0;
        system("CLS");
        cout << "Please enter number for topping to add (0 for no more)" << endl;
        cout << "Meat Toppings: " << endl;
        for ( unsigned int i = 0; i < toppings.size(); i++ ) {
            Toppings topping = toppings[i];
            cout << topping.get_price() << endl;
            if (topping.get_type() == 1) {
                cout << "\t[" << cntr+1 << "] " << "Name of Topping: " << topping.get_name() << "     " << topping.get_price() << "kr." << endl;
                cntr++;
            }
        }
        cout << "Vegetable Toppings: " << endl;
        for ( unsigned int i = 0; i < toppings.size(); i++ ) {
            Toppings topping = toppings[i];
            if (topping.get_type() == 2) {
                cout << "\t[" << cntr+1 << "] " << "Name of Topping: " << topping.get_name() << "     " << topping.get_price() << "kr." << endl;
                cntr++;
            }
        }
        cout << "Cheese Topping: " << endl;
        for ( unsigned int i = 0; i < toppings.size(); i++ ) {
            Toppings topping = toppings[i];
            if (topping.get_type() == 3) {
                cout << "\t[" << cntr+1 << "] " << "Name of Topping: " << topping.get_name() << "     " << topping.get_price() << "kr." << endl;
                cntr++;
            }
        }
        cin >> ToppSel;

        if (ToppSel > 0 && ToppSel <= (int)toppings.size()) {
        }
    }

}
void ManagerSubUI::UI_make_toppings() {
    system("CLS");
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
void ManagerSubUI::UI_make_size() {
    system("CLS");
    string name;
    int price;
    cout << "Please type in new size" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
    PizzaSize pizza_sizes(name, price);
    pizza_size.save_pizza_size(pizza_sizes);
}
void ManagerSubUI::UI_make_bottom() {
    system("CLS");
    string name;
    int price;
    cout << "Please type in new bottom" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
    PizzaBottom pizza_bottoms(name, price);
    pizza_bottom.save_pizza_bottom(pizza_bottoms);
}
void ManagerSubUI::UI_make_pizza_place() {
    string street;
    int number;
    cout << "Please type in a new address" << endl;
    cout << "Street: ";
    cin >> street;
    cout << "Number: ";
    cin >> number;
    PizzaPlace pizza_place(street, number);
    // to be continued
}
ManagerSubUI::~ManagerSubUI()
{
    //dtor
}
