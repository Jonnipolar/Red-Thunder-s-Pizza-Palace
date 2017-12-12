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
        }
    }
}
void Order_UI::UI_Add_Order() {
    OtherProducts other_product;
    Pizza pizza;
    Order order;
    string name;
    string order_time;
    int total_price;
    string typeOfDelivery;
    string HasBeenPaidFor;
    PizzaPlace OrderLocation;
    string OrderStatus;
    string Comment;
    vector <Pizza> pizzas;
    vector <OtherProducts> other_products;
    char selection;
    while (selection != 4) {
        system("CLS");
        cout << "What would you like to choose?" << endl;
        cout << "[1] Add Pizza" << endl;
        cout << "[2] Add Sides / Beverages" << endl;
        cout << "[3] Finish Order" << endl;
        cout << "[4] Quit" << endl;
        cin >> selection;
        switch (selection) {
            case '1':
                pizza = UI_Add_Order_Pizza();
                pizzas.push_back(pizza);
                break;
            case '2':
                other_product = add_other_prduct();
                other_products.push_back(other_product);
                break;
            case '3':
                system("CLS");
                cout << "Name of Person: ";
                cin >> ws;
                getline(cin, name);
                order_time = get_time();
                total_price = get_price_of_pizzas(pizzas);
                typeOfDelivery = get_type_of_delivery();
                HasBeenPaidFor = get_has_been_paid_for();
                OrderLocation = get_order_location();
                OrderStatus = get_order_status();
                Comment = get_comment();
                order = Order(name,pizzas,order_time,total_price,typeOfDelivery,HasBeenPaidFor,OrderLocation,OrderStatus,Comment);
                order_service.SaveOrder(order);
                selection = 5;
                break;
            case '4':
                break;
        }
    }
}
Pizza Order_UI::UI_Add_Order_Pizza() {
    Pizza pizza;
    int price;
    vector <Toppings> toppings;
    PizzaBottom user_pizza_bottom;
    PizzaSize user_pizza_size;
    char selection;
    string name = "";
    system("CLS");
    cout << "What would you like to do?" << endl;
    cout << "[1] Add custom pizza" << endl;
    cout << "[2] Add pizza from Menu" << endl;
    cin >> selection;
    switch (selection) {
        case '1':
            toppings = SubUI_add_topping();
            name = "Custom Pizza";
            user_pizza_bottom = UI_Get_Bottom();
            user_pizza_size = UI_Get_Size();
            price = get_price_of_toppings(toppings);
            pizza = Pizza(name, price, toppings, user_pizza_bottom, user_pizza_size);
            break;
        case '2':
            pizza = get_pizza_menus();
            user_pizza_bottom = UI_Get_Bottom();
            user_pizza_size = UI_Get_Size();
            price = pizza.get_price() + user_pizza_bottom.get_price() + user_pizza_size.get_price();
            Pizza new_pizza = Pizza(pizza.get_name(),pizza.get_price(),pizza.get_toppings(),user_pizza_bottom,user_pizza_size);
            return new_pizza;
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
        cout << "Please enter the number for topping to add (0 for no more)" << endl;
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
    cout << "Please enter the number for Bottom" << endl;
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
    cout << "Please enter the number for Size" << endl;
    cin >> SizeSel;
    if (SizeSel > 0 && SizeSel <= (int)pizza_size_list.size()) {
        user_pizza_size = pizza_size_list[SizeSel - 1];
    }
    return user_pizza_size;
}
int Order_UI::get_price_of_toppings(vector <Toppings> toppings) {
    int price = 0;
    for ( unsigned int i = 0; i < toppings.size(); i++ ) {
        price += toppings[i].get_price();
    }
    return price;
}
Pizza Order_UI::get_pizza_menus() {
    int PizzaSel = -1;
    vector <Pizza> pizzas = pizza_service.get_pizzas();
    Pizza user_pizza;
    system("CLS");
    cout << "Choose the pizza you want: " << endl;
    for ( unsigned int i = 0; i < pizzas.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizzas[i].get_name() << endl;
    }
    cin >> PizzaSel;
    if (PizzaSel > 0 && PizzaSel <= (int)pizzas.size()) {
        user_pizza = pizzas[PizzaSel - 1];
    }
    return user_pizza;
}
OtherProducts Order_UI::add_other_prduct() {
    OtherProducts other_product;
    system("CLS");
    cout << "Please add the sides you want!" << endl;
    vector <OtherProducts> soda_prod = other_prod_service.get_soda_list();
    vector <OtherProducts> sauce_prod = other_prod_service.get_sauces_list();
    vector <OtherProducts> dish_prod = other_prod_service.get_side();
    vector <OtherProducts> total_prod;
    int total_amount = soda_prod.size() + sauce_prod.size() + dish_prod.size();
    int prodSel = -1;
    int cntr = 0;
    cout << "Sodas: " << endl;
    for ( unsigned int i = 0; i < soda_prod.size(); i++ ) {
        cout << "\t[" << cntr+1 << "] " << soda_prod[i].get_name() << endl;
        cntr++;
        total_prod.push_back(soda_prod[i]);
    }
    cout << "\nSauces: " << endl;
    for ( unsigned int i = 0; i < sauce_prod.size(); i++ ) {
        cout << "\t[" << cntr+1 << "] " << sauce_prod[i].get_name() << endl;
        cntr++;
        total_prod.push_back(sauce_prod[i]);
    }
    cout << "\nDishes: " << endl;
    for ( unsigned int i = 0; i < dish_prod.size(); i++ ) {
        cout << "\t[" << cntr+1 << "] " << dish_prod[i].get_name() << endl;
        cntr++;
        total_prod.push_back(dish_prod[i]);
    }
    cin >> prodSel;
    if (prodSel > 0 && prodSel <= total_amount) {
        other_product = total_prod[prodSel - 1];
    }

    return other_product;
}
int Order_UI::get_price_of_pizzas(vector <Pizza> pizzas) {
    int price = 0;
    for ( unsigned int i = 0; i < pizzas.size(); i++ ) {
        PizzaBottom user_pizza_bottom = pizzas[i].get_bottom();
        PizzaSize user_pizza_size = pizzas[i].get_size();
        price += pizzas[i].get_price();
        price += user_pizza_bottom.get_price();
        price += user_pizza_size.get_price();
    }
    return price;
}
string Order_UI::get_time() {
    time_t timestamp = time(0);
    char time_buffer[80];
    strftime(time_buffer, sizeof(time_buffer), "%d/%m/%Y %H:%M", localtime(&timestamp));
    string TimeOrder(time_buffer);
    return TimeOrder;
}
string Order_UI::get_type_of_delivery() {
    string typeOfDelivery = "";
    int delSel = -1;
    system("CLS");
    cout << "PLease choose the type of delivery" << endl;
    cout << "\t[1] Home" << endl;
    cout << "\t[2] Pickup" << endl;
    cin >> delSel;
    if (delSel > 0 && delSel <= 2) {
        if (delSel == 1) {
            typeOfDelivery = "Home";
            return typeOfDelivery;
        }
        else {
            typeOfDelivery = "Pickup";
            return typeOfDelivery;
        }
    }
    return typeOfDelivery;
}
string Order_UI::get_has_been_paid_for() {
    string hasBeenPaidFor = "";
    int paidSel = -1;
    system("CLS");
    cout << "Is the user paying in advance or on pickup" << endl;
    cout << "\t[1] In Advance" << endl;
    cout << "\t[2] On Pickup" << endl;
    cin >> paidSel;
    if (paidSel > 0 && paidSel <= 2) {
        if (paidSel == 1) {
            hasBeenPaidFor = "In Advance";
            return hasBeenPaidFor;
        }
        else {
            hasBeenPaidFor = "On Pickup";
            return hasBeenPaidFor;
        }
    }
    return hasBeenPaidFor;
}
PizzaPlace Order_UI::get_order_location() {
    vector <PizzaPlace> user_pizza_places = pizza_places.get_pizza_place();
    PizzaPlace user_place;
    int locSel = -1;
    system("CLS");
    cout << "Select the location to pick up / Send from" << endl;
    for ( unsigned int i = 0; i < user_pizza_places.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << user_pizza_places[i].get_street() << endl;
    }
    cin >> locSel;
    if (locSel > 0 && locSel <= (int)user_pizza_places.size()) {
        user_place = user_pizza_places[locSel - 1];
        return user_place;
    }
    return user_place;
}
string Order_UI::get_order_status() {
    string orderStatus;
    int statSel = -1;
    system("CLS");
    cout << "Select the status of the order" << endl;
    cout << "[1] Processing" << endl;
    cout << "[2] In Oven" << endl;
    cout << "[3] Complete" << endl;
    cin >> statSel;
    if (statSel > 0 && statSel <= 3) {
        if (statSel == 1) {
            orderStatus = "Processing";
            return orderStatus;
        }
        else if (statSel == 2) {
            orderStatus = "In Oven";
            return orderStatus;
        }
        else {
            orderStatus = "Complete";
            return orderStatus;
        }
    }
    return orderStatus;
}
string Order_UI::get_comment() {
    system("CLS");
    string comment = "";
    int ComSel = -1;
    cout << "(Optional) Any Comments?" << endl;
    cout << "[1] Yes" << endl;
    cout << "[2] No" << endl;
    cin >> ComSel;
    if (ComSel > 0 && ComSel <= 2) {
        if (ComSel == 1) {
            cout << "What comment does the user want to leave?" << endl;
            cin >> ws;
            getline(cin, comment);
        }
        else {
            return comment;
        }
    }
    return comment;
}
Order_UI::~Order_UI()
{
    //dtor
}
