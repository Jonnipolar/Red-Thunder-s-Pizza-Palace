#include "OrderUI.h"

Order_UI::Order_UI()
{
    //ctor
}
void Order_UI::UI_Start() {
    char selection;                                                             // Create Variable to keep hold of user selection
    while (selection != '2') {                                                  // While loop
        system("CLS");
        cout << "Hello and welcome to Red Thunder's Pizza" << endl;             // Welcome Message
        cout << "How may i help you?" << endl;                                  // -||-
        cout << "[1] Add an order" << endl;                                     // Choice
        cout << "[2] Quit" << endl;                                             // Choice
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
    char selection;
    while (selection != '5') {
        cout << "What would you like to choose?" << endl;
        cout << "[1] Add Pizza" << endl;
        cout << "[2] Add Beverages" << endl;
        cout << "[3] Add Sides" << endl;
        cout << "[4] Finish Order" << endl;
        cout << "[5] Quit" << endl;
        cin >> selection;
        switch (selection) {
            case '1':
                UI_Add_Order_Pizza();
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
        }
    }
}
Pizza Order_UI::UI_Add_Order_Pizza() {
    Pizza pizza;
    vector <Toppings> toppings;
    char selection;
    string name = "";
    system("CLS");
    cout << "What would you like to do?" << endl;
    cout << "[1] Add pizza from Menu" << endl;
    cout << "[2] Add custom pizza" << endl;
    cin >> selection;
    switch (selection) {
        case '1':
            toppings = SubUI_add_topping();


            break;
        case '2':
            break;
    }
    return pizza;
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
PizzaBottom Order_UI::UI_Get_Bottom() {
    int BottSel = -1;
    PizzaBottom user_pizza_bottom;
    vector <PizzaBottom> pizza_bottom_list = pizza_bottom.Get_Pizza_Bottom();
    system("CLS");
    cout << "Please choose the pizza bottom for your pizza" << endl;
    for ( unsigned int i = 0; i < pizza_bottom_list.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizza_bottom_list[i].get_type() << endl;
    }
    cout << "Please enter number for Bottom" << endl;
    cin >> BottSel;
    if (BottSel > 0 && BottSel <= (int)pizza_bottom_list.size()) {
        user_pizza_bottom = pizza_bottom_list[BottSel - 1];
    }
    return user_pizza_bottom;
}
PizzaSize Order_UI::UI_Get_Size() {
    int SizeSel = -1;
    PizzaSize user_pizza_size;
    vector <PizzaSize> pizza_size_list = pizza_size.Get_Pizza_Sizes();
    system("CLS");
    cout << "Please choose the pizza size for your pizza" << endl;
    for ( unsigned int i = 0; i < pizza_size_list.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizza_size_list[i].get_size() << endl;
    }
    cout << "Please enter number for Size" << endl;
    cin >> SizeSel;
    if (SizeSel > 0 && SizeSel <= (int)pizza_size_list.size()) {
        user_pizza_size = pizza_size_list[SizeSel - 1];
    }
    return user_pizza_size;
}
Order_UI::~Order_UI()
{
    //dtor
}
