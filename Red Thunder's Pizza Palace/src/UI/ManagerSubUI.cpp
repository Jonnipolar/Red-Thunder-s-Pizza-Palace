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
    PizzaSize _size;
    PizzaBottom bottom;
    string name;
    system("CLS");
    cout << "Please type in pizza name" << endl;
    cout << "Pizza: ";
    cin >> ws;
    getline(cin, name);
    vector <Toppings> userToppings = SubUI_add_topping();
    cout << "\nYour toppings are: " << endl;
    for (unsigned int i = 0; i < userToppings.size(); i++) {
        cout << "\t[" << i+1 << "] " << "Name of Topping: " << userToppings[i].get_name() << endl;
    }
    int price;
    cout << "\nSelect the price for the pizza" << endl;
    cin >> price;
    Pizza pizza(name,price,userToppings,bottom,_size);
    pizza_service.save_pizza(pizza);

}
vector <Toppings> ManagerSubUI::SubUI_add_topping() {
    vector <Toppings> cheeseTopp = toppings_list.get_cheese_list();
    vector <Toppings> meatTopp = toppings_list.get_meat_list();
    vector <Toppings> vegetableTopp = toppings_list.get_vegetable_list();
    vector <Toppings> toppings;
    vector <Toppings> userToppings;
    int ToppingAmount = cheeseTopp.size() + meatTopp.size() + vegetableTopp.size();
    int ToppSel = -1;
    while (ToppSel != 0) {
        int cntr = 0;
        system("CLS");
        cout << "\nMeat Toppings: \n" << endl;
        for ( unsigned int i = 0; i < meatTopp.size(); i++ ) {
            cout << "\t[" << cntr+1 << "] " << "Name of Topping: " << meatTopp[i].get_name() << endl;
            toppings.push_back(meatTopp[i]);
            cntr++;
        }
        cout << "\nVegetable Toppings: \n" << endl;
        for ( unsigned int i = 0; i < vegetableTopp.size(); i++ ) {
            cout << "\t[" << cntr+1 << "] " << "Name of Topping: " << vegetableTopp[i].get_name() << endl;
            toppings.push_back(vegetableTopp[i]);
            cntr++;
        }
        cout << "\nCheese Topping: \n" << endl;
        for ( unsigned int i = 0; i < cheeseTopp.size(); i++ ) {
            cout << "\t[" << cntr+1 << "] " << "Name of Topping: " << cheeseTopp[i].get_name() << endl;
            toppings.push_back(cheeseTopp[i]);
            cntr++;
        }
        cout << "Please enter number for topping to add (0 for no more)" << endl;
        cin >> ToppSel;
        if (ToppSel > 0 && ToppSel <= ToppingAmount) {
            userToppings.push_back(toppings[ToppSel-1]);
        }
    }
    return userToppings;
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
    pizza_places.save_pizza_place(pizza_place);
}
ManagerSubUI::~ManagerSubUI()
{
    //dtor
}
