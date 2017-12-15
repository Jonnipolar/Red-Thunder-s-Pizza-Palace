#include "OrderUI.h"

Order_UI::Order_UI()
{
    //ctor
}
void Order_UI::UI_Start()
{
    char selection;
    bool is_valid = true;
                                                              // Create Variable to keep hold of user selection
    while (selection != '3')
    {
        // While loop
        system("CLS");
        cout << "Hello and welcome to Red Thunder's Pizza" << endl;             // Welcome Message
        cout << "How may i help you?" << endl;                                  // -||-
        cout << "[1] Add an order" << endl;                                     // Choice
        cout << "[2] Print last orders" << endl;
        cout << "[3] Back to login screen" << endl;
        do {
            try {
                is_valid = true;
                cout << "Selection: ";
                cin >> selection;                                                       // Get user Input
                switch (selection) {
                case '1':
                    UI_Add_Order();
                    break;
                case '2':
                    {
                        vector <Order> order = order_service.get_orders(1);
                        for(unsigned int i = 0; i < order.size(); i++)
                        {
                            cout << order[i] << endl;
                        }
                        if(order.size() == 0)
                        {
                            cout << "No order has been made in this session. \n";
                        };
                        do {
                            cout << "\nPress enter to continue. \n";
                            cin.sync();
                        } while(cin.get() != '\n');
                    }
                    break;
                case '3': break;
                default:
                    {
                        throw InvalidMenuNumberException();
                    }
                }
            } catch(InvalidMenuNumberException e)
            {
                is_valid = false;
                cout << e.get_message();
                cin.sync();
            }
        } while(!is_valid);
    }
}

void Order_UI::UI_Add_Order() throw (InvalidFileNotOpenException)
{
    OtherProducts other_product;
    Pizza pizza;
    Order order;
    string name;
    string order_time;
    int total_price;
    string typeOfDelivery;
    string HasBeenPaidFor;
    PizzaPlace OrderLocation;
    string OrderStatus = "Processing";
    string Comment;
    vector <Pizza> pizzas;
    vector <OtherProducts> other_products;
    char selection;
    int check = 0;
    int check2 = 0;
    bool is_valid = true;
    while (selection != '4') {
        system("CLS");
        cout << "What would you like to choose?" << endl;
        cout << "[1] Add Pizza" << endl;
        cout << "[2] Add Sides / Beverages" << endl;
        cout << "[3] Finish Order" << endl;
        cout << "[4] Quit" << endl;
        cin >> selection;
        switch (selection) {
        case '1':
            try {
                pizza = UI_Add_Order_Pizza();
                pizzas.push_back(pizza);
                check2 = 1;
            } catch (InvalidFileNotOpenException e) {
                cout << e.get_message();
                do {
                    cout << "Press enter to continue. \n";
                    cin.sync();
                } while(cin.get() != '\n');
            }
            break;
        case '2':
            try {
                other_product = add_other_product();
                other_products.push_back(other_product);
                check = 1;
            } catch (InvalidFileNotOpenException e) {
                cout << e.get_message();
                do {
                    cout << "Press enter to continue. \n";
                    cin.sync();
                } while(cin.get() != '\n');
            }
            break;
        case '3':
            system("CLS");
            try {

                do {
                    cout << "Name of Person: ";
                    is_valid = true;
                    cin.sync();
                    getline(cin, name);
                    try {
                        name = valid.get_name(name);
                    } catch(InvalidNameException e) {
                        is_valid = false;
                        cout << e.get_message();
                    }
                } while(!is_valid);
                order_time = get_time();
                if(check == 0) {
                    other_products.push_back(other_product);
                }
                if(check2 == 0) {
                    pizzas.push_back(pizza);
                }
                total_price = get_price_of_pizzas(pizzas);
                typeOfDelivery = get_type_of_delivery();
                HasBeenPaidFor = get_has_been_paid_for();
                OrderLocation = get_order_location();
                Comment = get_comment();
            } catch (InvalidFileNotOpenException e) {
                cout << e.get_message();
                do {
                    cout << "Press enter to continue. \n";
                    cin.sync();
                } while(cin.get() != '\n');
            }
            order = Order(name,pizzas, other_products, order_time,total_price,typeOfDelivery,HasBeenPaidFor,OrderLocation,OrderStatus,Comment);
            order_service.SaveOrder(order);
            selection = '4';
            break;
        case '4':
            break;
        }
    }
}
Pizza Order_UI::UI_Add_Order_Pizza()
{
    // bool is_valid = true;
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
        try {
            toppings = SubUI_add_topping();
            name = "Custom Pizza";
            user_pizza_bottom = UI_Get_Bottom();
            user_pizza_size = UI_Get_Size();
            price = get_price_of_toppings(toppings);
            pizza = Pizza(name, price, toppings, user_pizza_bottom, user_pizza_size);
        } catch(InvalidFileNotOpenException e) {
            cout << e.get_message();
            do {
                cout << "Press enter to continue. \n";
                cin.sync();
            } while(cin.get() != '\n');
        };
        break;
    case '2':
        try {
            pizza = get_pizza_menus();
            user_pizza_bottom = UI_Get_Bottom();
            user_pizza_size = UI_Get_Size();
            price = pizza.get_price() + user_pizza_bottom.get_price() + user_pizza_size.get_price();
            pizza = Pizza(pizza.get_name(),pizza.get_price(),pizza.get_toppings(),user_pizza_bottom,user_pizza_size);
            return pizza;
        } catch(InvalidFileNotOpenException e) {
            cout << e.get_message();
            do {
                cout << "Press enter to continue. \n";
                cin.sync();
            } while(cin.get() != '\n');
        };

        break;
    }
    return pizza;
}

vector <Toppings> Order_UI::SubUI_add_topping()
{
    vector <Toppings> cheeseTopp = toppings_list.get_selected_list(3);
    vector <Toppings> meatTopp = toppings_list.get_selected_list(1);
    vector <Toppings> vegetableTopp = toppings_list.get_selected_list(2);
    vector <Toppings> toppings;
    vector <Toppings> userToppings;
    unsigned int ToppingAmount = cheeseTopp.size() + meatTopp.size() + vegetableTopp.size();
    unsigned int ToppSel = -1;
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
        ToppSel = get_integer_input_variable_size_with_zeroescape(ToppingAmount);
        if (ToppSel > 0 && ToppSel <= ToppingAmount) {
            userToppings.push_back(toppings[ToppSel-1]);
        }
    }
    return userToppings;
}
PizzaBottom Order_UI::UI_Get_Bottom()
{
    PizzaBottom user_pizza_bottom;
    vector <PizzaBottom> pizza_bottom_list = pizza_bottom.Get_Pizza_Bottom();
    system("CLS");
    cout << "Please choose the pizza bottom for your pizza" << endl;
    for ( unsigned int i = 0; i < pizza_bottom_list.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizza_bottom_list[i].get_type() << endl;
    }
    cout << "Please enter the number for Bottom" << endl;
    unsigned int BottSel = get_integer_input_variable_size(pizza_bottom_list.size());
    if (BottSel > 0 && BottSel <= pizza_bottom_list.size()) {
        user_pizza_bottom = pizza_bottom_list[BottSel - 1];
    }
    return user_pizza_bottom;
}
PizzaSize Order_UI::UI_Get_Size()
{
    PizzaSize user_pizza_size;
    vector <PizzaSize> pizza_size_list = pizza_size.Get_Pizza_Sizes();
    system("CLS");
    cout << "Please choose the pizza size for your pizza" << endl;
    for ( unsigned int i = 0; i < pizza_size_list.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizza_size_list[i].get_size() << endl;
    }
    cout << "Please enter the number for Size" << endl;
    unsigned int SizeSel = get_integer_input_variable_size(pizza_size_list.size());                                                                 ///ath input her lika
    if (SizeSel > 0 && SizeSel <= pizza_size_list.size()) {
        user_pizza_size = pizza_size_list[SizeSel - 1];
    }
    return user_pizza_size;
}
int Order_UI::get_price_of_toppings(vector <Toppings> toppings)
{
    int price = 0;
    for ( unsigned int i = 0; i < toppings.size(); i++ ) {
        price += toppings[i].get_price();
    }
    return price;
}
Pizza Order_UI::get_pizza_menus()
{
    vector <Pizza> pizzas = pizza_service.get_pizzas();
    Pizza user_pizza;
    system("CLS");
    cout << "Choose the pizza you want: " << endl;
    for ( unsigned int i = 0; i < pizzas.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizzas[i].get_name() << endl;
    }
    unsigned int PizzaSel = get_integer_input_variable_size(pizzas.size());                                                          ///ath herna input mida vid array
    if (PizzaSel > 0 && PizzaSel <= pizzas.size()) {
        user_pizza = pizzas[PizzaSel - 1];
    }
    return user_pizza;
}
OtherProducts Order_UI::add_other_product()
{
    OtherProducts other_product;
    system("CLS");

    cout << "Please add the sides you want!" << endl;
    try {
        vector <OtherProducts> soda_prod = other_prod_service.get_soda_list();
        vector <OtherProducts> sauce_prod = other_prod_service.get_sauces_list();
        vector <OtherProducts> dish_prod = other_prod_service.get_side();
        vector <OtherProducts> total_prod;

        unsigned int total_amount = soda_prod.size() + sauce_prod.size() + dish_prod.size();
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

        unsigned int prodSel = get_integer_input_variable_size(total_amount);                                                             ///ath thetta input her, liklega mbara menu throw eins og hitt (nema size of stuff)
        if (prodSel > 0 && prodSel <= total_amount) {
            other_product = total_prod[prodSel - 1];
        }
    } catch (InvalidFileNotOpenException e) {
        cout << e.get_message();
        do {
            cout << "Press enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
    return other_product;
}
int Order_UI::get_price_of_pizzas(vector <Pizza> pizzas)
{
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
string Order_UI::get_time()
{
    time_t timestamp = time(0);
    char time_buffer[80];
    strftime(time_buffer, sizeof(time_buffer), "%d/%m/%Y %H:%M", localtime(&timestamp));
    string TimeOrder(time_buffer);
    return TimeOrder;
}
string Order_UI::get_type_of_delivery() throw (InvalidFileNotOpenException) ///vantar
{

    string typeOfDelivery = "";
    int delSel = -1;
    system("CLS");
    cout << "PLease choose the type of delivery" << endl;
    cout << "\t[1] Home" << endl;
    cout << "\t[2] Pickup" << endl;
    delSel = get_integer_input_variable_size(2);
    try {
        if (delSel > 0 && delSel <= 2) {                        /// her er if en ekki switch
            if (delSel == 1) {
                typeOfDelivery = "Home";
                return typeOfDelivery;
            } else {
                typeOfDelivery = "Pickup";
                return typeOfDelivery;
            }
        }
    } catch (InvalidFileNotOpenException e) {
        cout << e.get_message();
        do {
            cout << "Press enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
    return typeOfDelivery;
}
string Order_UI::get_has_been_paid_for()  throw (InvalidFileNotOpenException) ///vantar
{

    string hasBeenPaidFor = "";
    int paidSel = -1;
    system("CLS");
    try {
        cout << "Is the user paying in advance or on pickup" << endl;
        cout << "\t[1] In Advance" << endl;
        cout << "\t[2] On Pickup" << endl;
        paidSel = get_integer_input_variable_size(2);                                                  /// ath her (menu input??) - thetta er if en ekki switch
        if (paidSel > 0 && paidSel <= 2) {
            if (paidSel == 1) {
                hasBeenPaidFor = "In Advance";
                return hasBeenPaidFor;
            } else {
                hasBeenPaidFor = "On Pickup";
                return hasBeenPaidFor;
            }
        }
    } catch (InvalidFileNotOpenException e) {
        cout << e.get_message();
        do {
            cout << "Press enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
    return hasBeenPaidFor;
}
PizzaPlace Order_UI::get_order_location() throw (InvalidMenuNumberException,InvalidFileNotOpenException)  //virdist vera klart
{

    vector <PizzaPlace> user_pizza_places = pizza_places.get_pizza_place();
    PizzaPlace user_place;
    unsigned int locSel;
    system("CLS");
    try {
        cout << "Select the location to pick up / Send from" << endl;
        for ( unsigned int i = 0; i < user_pizza_places.size(); i++ ) {
            cout << "\t[" << i+1 << "] " << user_pizza_places[i].get_street() << endl;
        }
        locSel = get_integer_input_variable_size(user_pizza_places.size());

        if (locSel > 0 && locSel <= user_pizza_places.size()) {                    ///liklega thetta size ??? kannski
            user_place = user_pizza_places[locSel - 1];
            return user_place;
        }
    } catch (InvalidFileNotOpenException e) {
        cout << e.get_message();
        do {
            cout << "Press enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
    return user_place;
}

string Order_UI::get_comment()
{
    system("CLS");

    string comment = "";
    unsigned int ComSel;
    cout << "(Optional) Any Comments?" << endl;
    cout << "[1] Yes" << endl;
    cout << "[2] No" << endl;
    try {
        ComSel = get_integer_input_variable_size(2);
        if (ComSel > 0 && ComSel <= 2) {
            if (ComSel == 1) {
                cout << "What comment does the user want to leave?" << endl;        ///tharf ekkert ad gera her hugsa eg.. ekkert validation.
                cin.sync();
                getline(cin, comment);
            } else {
                return comment;
            }
        }
    } catch (InvalidFileNotOpenException e) {
        cout << e.get_message();
        do {
            cout << "Press enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
    return comment;
}
Order_UI::~Order_UI()
{
    //dtor
}

unsigned int Order_UI::get_integer_input_variable_size(unsigned int size) throw (InvalidMenuNumberException) //skilar int eftir s
{
    unsigned int input;
    bool is_valid = true;
    do {                                                                                     //mod for menunumber - not universally adaptive (see below)
        is_valid = true;
        string input_input;
        try {
            cout << "Select option: ";
            cin.sync();
            getline(cin,input_input);
            stringstream push_input(input_input);
            push_input >> input;
            if(input > size || input <1 || input_input.empty()) {
                is_valid = false;
                throw InvalidMenuNumberException();
            } else {};
            for(unsigned int i = 0; i < input_input.length(); i++) {
                if(!isdigit(input_input[i])) {      // because of this (see above)
                    is_valid = false;
                    throw InvalidMenuNumberException();
                } else {};
            }
        } catch(InvalidMenuNumberException e) {
            cout << e.get_message();
        }
        stringstream push_input(input_input);
        push_input >> input;
    } while(!is_valid);
    return input;
}

unsigned int Order_UI::get_integer_input_variable_size_with_zeroescape(unsigned int size) throw (InvalidMenuNumberException) //skilar int eftir s
{
    unsigned int input;
    bool is_valid = true;
    do {                                                                                     //mod for menunumber - not universally adaptive (see below)
        is_valid = true;
        string input_input;
        try {
            cout << "Select option: ";
            cin.sync();
            getline(cin,input_input);
            stringstream push_input(input_input);
            push_input >> input;
            if(input == 0) {
                break;
            } else if(input > size || input <1 || input_input.empty()) {
                is_valid = false;
                throw InvalidMenuNumberException();
            } else {};
            for(unsigned int i = 0; i < input_input.length(); i++) {
                if(!isdigit(input_input[i])) {      // because of this (see above)
                    is_valid = false;
                    throw InvalidMenuNumberException();
                } else {};
            }
        } catch(InvalidMenuNumberException e) {
            cout << e.get_message();
        }
        stringstream push_input(input_input);
        push_input >> input;
    } while(!is_valid);
    return input;
}
/*
int Order_UI::get_integer_input3() throw (InvalidMenuNumberException)
{
    bool is_valid = true;
    int type;
    do {                                                                                     //mod for menunumber - not universally adaptive (see below)
        is_valid = true;
        string type_input;
        try {
            cout << "Select option: ";
            cin.sync();
            getline(cin,type_input);
            stringstream push_type(type_input);
            push_type >> type;
            if(type > 3 || type <1 || type_input.empty()) {
                is_valid = false;
                throw InvalidMenuNumberException();
            } else {};
            for(unsigned int i = 0; i < type_input.length(); i++) {
                if(!isdigit(type_input[i]) || type_input[i]>'3' || type_input[i]<'1') {      // because of this (see above)
                    is_valid = false;
                    throw InvalidMenuNumberException();
                } else {};
            }
        } catch(InvalidMenuNumberException e) {
            cout << e.get_message();
        }
        stringstream push_type(type_input);
        push_type >> type;
    } while(!is_valid);
    return type;
}
int Order_UI::get_integer_input2() throw (InvalidMenuNumberException)  /// thessi er settur upp fyrir ad taka einungis integer fra einu
{
    bool is_valid = true;
    int type;
    do {                                                                                     //mod for menunumber - not universally adaptive (see below)
        is_valid = true;
        string type_input;
        try {
            cout << "Select option: ";
            cin.sync();
            getline(cin,type_input);
            stringstream push_type(type_input);
            push_type >> type;
            if(type > 2 || type <1 || type_input.empty()) {
                is_valid = false;
                throw InvalidMenuNumberException();
            } else {};
            for(unsigned int i = 0; i < type_input.length(); i++) {
                if(!isdigit(type_input[i]) || type_input[i]>'2' || type_input[i]<'1') {      // because of this (see above)
                    is_valid = false;
                    throw InvalidMenuNumberException();
                } else {};
            }
        } catch(InvalidMenuNumberException e) {
            cout << e.get_message();
        }
        stringstream push_type(type_input);
        push_type >> type;
    } while(!is_valid);
    return type;
}
int Order_UI::get_integer_input4() throw (InvalidMenuNumberException)  /// thessi er settur upp fyrir ad taka einungis integer fra einu
{
    bool is_valid = true;
    int type;
    do {                                                                                     //mod for menunumber - not universally adaptive (see below)
        is_valid = true;
        string type_input;
        try {
            cout << "Select option: ";
            cin.sync();
            getline(cin,type_input);
            stringstream push_type(type_input);
            push_type >> type;
            if(type > 4 || type <1 || type_input.empty()) {
                is_valid = false;
                throw InvalidMenuNumberException();
            } else {};
            for(unsigned int i = 0; i < type_input.length(); i++) {
                if(!isdigit(type_input[i]) || type_input[i]>'4' || type_input[i]<'1') {      // because of this (see above)
                    is_valid = false;
                    throw InvalidMenuNumberException();
                } else {};
            }
        } catch(InvalidMenuNumberException e) {
            cout << e.get_message();
        }
        stringstream push_type(type_input);
        push_type >> type;
    } while(!is_valid);
    return type;
}
*/
