#include "OrderUI.h"

Order_UI::Order_UI()
{
    //ctor
}
void Order_UI::UI_Start() {
    char selection;                                                             // Create Variable to keep hold of user selection
    while (selection != '2') {                                                  // While loop
        system("CLS");
        cout << "Hello and welcome to Red Thunder's Pizza" << endl;           // Welcome Message
        cout << "How may i help you?" << endl;                                  // -||-
        cout << "[1] Add an order" << endl;                                      // Choice
        cout << "[2] Quit" << endl;                                              // Choice
        cin >> selection;                                                       // Get user Input
        switch (selection) {
            case '1':
                UI_Add_Order();
                break;
            case '2':
                break;

        }
    }
}
void Order_UI::UI_Add_Order() {
    system("CLS");
    vector <Pizza> pizzas;
    vector <Toppings> toppings = SubUI_add_topping();
    cout << "What would you like to choose?" << endl;
    cout << "" << endl;
    char selection;
    cin >> selection;
    switch (selection) {
        case '1':
            break;
        case '2':
            break;
    }

    cout << "Your toppings are: " << endl;
    for (unsigned int i = 0; i < toppings.size(); i++) {
        cout << "\t[" << i+1 << "] " << "Name of Topping: " << toppings[i].get_name() << endl;
    }

}
vector <Toppings> Order_UI::SubUI_add_topping() {
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
Order_UI::~Order_UI()
{
    //dtor
}
