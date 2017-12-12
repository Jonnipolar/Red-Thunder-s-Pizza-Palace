#include "ManagerSubUI.h"

ManagerSubUI::ManagerSubUI()
{
    //ctor
}
void ManagerSubUI::UI_Start() throw (InvalidMenuNumberException)
{
    vector <Pizza> pizza;
    char selection;                                                         // Declare selection char
    bool is_valid = true;
    while (selection != '6') {                                              // While user does not want to quit
        system("CLS");
        cout << "Hello Mr. Manager" << endl;                                 // Welcome message
        cout << "What would you like to do:" << endl;                        // -||-
        cout << "[1] Make pizza" << endl;                                    // Menu for user to pick
        cout << "[2] Make topping" << endl;                                  // ------""-------------
        cout << "[3] Create menu" << endl;                                   // ------""-------------
        cout << "[4] Add other items" << endl;                               // ------""-------------
        cout << "[5] Add pizza place" << endl;                               // ------""-------------
        cout << "[6] Back to main menu" << endl;                                          // ------""-------------
        do {
            try {
                is_valid = true;
                cout << "Select option: ";
                cin >> selection;
                switch (selection) {
                case '1':                                                        // if user picks p create pizza
                    UI_select_make_pizza();
                    break;
                case '2':
                    UI_make_toppings();
                    break;
                case '3':
                    pizza = pizza_service.get_pizzas();
                    for (unsigned int i = 0; i < pizza.size(); i++) {
                        cout << pizza[i];
                    }
                    cin >> selection; ///HVAD ER THETTA HER?? A THETTA EKKI HEIMA ANNARSTADAR?? setja number throw??
                    break;
                case '4':
                    UI_make_other_items();
                    break;
                case '5':
                    UI_make_pizza_place();
                    break;
                case '6':
                    break;

                default:
                    is_valid = false;
                    throw InvalidMenuNumberException();
                }
            } catch(InvalidMenuNumberException e) {
                cout << e.get_message();
            };
        } while(!is_valid);
    }
}

void ManagerSubUI::UI_select_make_pizza() throw (InvalidMenuNumberException)
{
    bool is_valid = true; // is valid heldur user i loop a medan thu ert med vitlaust svar.
    char selection;

    system("CLS");
    cout << "[1] Make new size" << endl;
    cout << "[2] Make new bottom" << endl;
    cout << "[3] Make Pizza" << endl;
    cout << "[4] Back to main menu" << endl;
    do {
        try {                                                                          //try og throw komid
            is_valid = true;
            cout << "Select option: ";
            cin >> selection;
            switch (selection) {
            case '1':
                UI_make_size();
                break;
            case '2':                                            // if user picks t create topping
                UI_make_bottom();
                break;
            case '3':                                               // if user picks m Create menu
                UImake_pizza();
                break;
            case '4':
                break;
            default: //kastar a throw
                is_valid = false;
                throw InvalidMenuNumberException();
            }
        } catch(InvalidMenuNumberException e) { // gripur throw i message
            cout << e.get_message();
        }
    } while(!is_valid);
}



void ManagerSubUI::UImake_pizza() throw (InvalidNameException, InvalidPriceException) /// throw komin
{
    bool is_valid = true;
    PizzaSize _size;
    PizzaBottom bottom;
    string name;
    system("CLS");
    cout << "Please type in new pizza name" << endl;
    do {
        is_valid = true;
        try {
            cout << "Name: ";
            cin.sync();                             ///þetta verður að vera Sync en ekki WS svo að .empty function virki
            getline(cin, name);
            if(name.length() > 20) {
                is_valid = false;
                throw InvalidNameException();
            } else if(name.empty()) {
                is_valid = false;
                throw InvalidNameException();
            } else {};
        } catch(InvalidNameException e) {
            cout << e.get_message();
        }
    } while(!is_valid);
    vector <Toppings> userToppings = SubUI_add_topping();
    cout << "\nYour toppings are: " << endl;
    for (unsigned int i = 0; i < userToppings.size(); i++) {
        cout << "\t[" << i+1 << "] " << "Name of Topping: " << userToppings[i].get_name() << endl;
    }
    int price;
    string price_input;

    cout << "\nSelect the price for the pizza" << endl;
    do {
        is_valid = true;
        try {
            cout << "Price: ";
            cin.sync();
            getline(cin, price_input);
            for(unsigned int i = 0; i < price_input.length(); i++) {
                if(!isdigit(price_input[i])) {
                    is_valid = false;
                    throw InvalidPriceException();
                } else {};
            }
            if(price_input.empty()) {
                is_valid = false;
                throw InvalidPriceException();
            } else {};
        } catch(InvalidPriceException e) {
            cout << e.get_message();
        }
        stringstream push_price(price_input);
        push_price >> price;
    } while(!is_valid);

    Pizza pizza(name,price,userToppings,bottom,_size);
    pizza_service.save_pizza(pizza);
}
vector <Toppings> ManagerSubUI::SubUI_add_topping()
{
    vector <Toppings> cheeseTopp = toppings_list.get_cheese_list();
    vector <Toppings> meatTopp = toppings_list.get_meat_list();
    vector <Toppings> vegetableTopp = toppings_list.get_vegetable_list();
    vector <Toppings> toppings;
    vector <Toppings> userToppings;
    int ToppingAmount = cheeseTopp.size() + meatTopp.size() + vegetableTopp.size();
    int ToppSel = -1;
    while (ToppSel != 0) {                                                               ///vantar ekki numberthrow herna lika?
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
void ManagerSubUI::UI_make_toppings() throw (InvalidNameException, InvalidPriceException, InvalidMenuNumberException)
{
    system("CLS");

    int price;
    int type;
    bool is_valid = true;
    string name;



    cout << "Please type in topping" << endl;
    do { ///name - ready
        is_valid = true;
        try {
            cout << "Name: ";                                                       // ws needed to clear before getline
            cin.sync();
            getline(cin, name);
            if(name.length() > 20) {
                is_valid = false;
                throw InvalidNameException();
            } else if(name.empty()) {
                is_valid = false;
                throw InvalidNameException();
            } else {};
        } catch(InvalidNameException e) {
            cout << e.get_message();
        }
    } while(!is_valid);

    do { ///ready for use PRICE
        is_valid = true;
        string price_input = "";
        try {
            cout << "Price: ";
            cin.sync();
            getline(cin, price_input);
            for(unsigned int i = 0; i < price_input.length(); i++) {
                if(!isdigit(price_input[i])) {
                    is_valid = false;
                    throw InvalidPriceException();
                } else {};
            }
            if(price_input.empty()) {
                is_valid = false;
                throw InvalidPriceException();
            } else {};
        } catch(InvalidPriceException e) {
            cout << e.get_message();
        }
        stringstream push_price(price_input);
        push_price >> price;
    } while(!is_valid);


    cout << "Type: \n\t1 for meat\n\t2 for vegetable\n\t3 for cheese" << endl;
    do { //mod for menunumber - not universally adaptive (see below)
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
                if(!isdigit(type_input[i]) || type_input[i]>'3' || type_input[i]<'1') { // because of this (see above)
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

    Toppings topping(name, price, type);                                    // sendir inn í færubreytusmið
    toppings_list.save_topping_list(topping);                                      // sendir í function sem vistar í skjal
}
void ManagerSubUI::UI_make_size() throw (InvalidNameException, InvalidPriceException) /// KOMINN HINGAD!!!
{
    system("CLS");
    string name;

    int price;
    bool is_valid = true;
    string price_input;

    cout << "Please type in new size name (description)." << endl;
     do { ///name - ready
        is_valid = true;
        try {
            cout << "Name: ";
            cin.sync();
            getline(cin, name);
            if(name.length() > 20) {
                is_valid = false;
                throw InvalidNameException();
            } else if(name.empty()) {
                is_valid = false;
                throw InvalidNameException();
            } else {};
        } catch(InvalidNameException e) {
            cout << e.get_message();
        }
    } while(!is_valid);

    cout << "Select price for size.\n";
    do {
        is_valid = true;
        try {
            cout << "Price: ";
            cin.sync();                                                     /// setja inn throw a illegal number
            getline(cin, price_input);
            for(unsigned int i = 0; i < price_input.length(); i++) {
                if(!isdigit(price_input[i])) {
                    is_valid = false;
                    throw InvalidPriceException();
                } else {};
            }
            if(price_input.empty()) { // passar ad madur slai eitthvad inn
                is_valid = false;
                throw InvalidPriceException();
            } else {};
        } catch(InvalidPriceException e) {
            cout << e.get_message();
        }
        stringstream push_price(price_input);
        push_price >> price;
    } while(!is_valid);

    PizzaSize pizza_sizes(name, price);
    pizza_size.save_pizza_size(pizza_sizes);
}
void ManagerSubUI::UI_make_bottom() throw (InvalidNameException, InvalidPriceException)
{
    system("CLS");
    string name;
    int price;
    bool is_valid = true;
    string price_input;


    cout << "Please type in new bottom name (description)." << endl;
     do { ///name - ready
        is_valid = true;
        try {
            cout << "Name: ";
            cin.sync();
            getline(cin, name);
            if(name.length() > 20) {
                is_valid = false;
                throw InvalidNameException();
            } else if(name.empty()) {
                is_valid = false;
                throw InvalidNameException();
            } else {};
        } catch(InvalidNameException e) {
            cout << e.get_message();
        }
    } while(!is_valid);


    cout << "Select price for bottom." << endl;
    do {
        is_valid = true;
        try {
            cout << "Price: ";
            cin.sync();                                                     /// setja inn throw a illegal number
            getline(cin, price_input);
            for(unsigned int i = 0; i < price_input.length(); i++) {
                if(!isdigit(price_input[i])) {
                    is_valid = false;
                    throw InvalidPriceException();
                } else {};
            }
            if(price_input.empty()) { // passar ad madur slai eitthvad inn
                is_valid = false;
                throw InvalidPriceException();
            } else {};
        } catch(InvalidPriceException e) {
            cout << e.get_message();
        }
        stringstream push_price(price_input);
        push_price >> price;
    } while(!is_valid);                                                          ///only numbers

    PizzaBottom pizza_bottoms(name, price);
    pizza_bottom.save_pizza_bottom(pizza_bottoms);
}
void ManagerSubUI::UI_make_pizza_place()
{
    string street;
    int number;
    string number_input;
    bool is_valid = true;

    cout << "Please type in a new address." << endl;
    bool is_valid = true;
     do { ///name - ready
        try {
            string name;
            cout << "Street name: ";
            cin.sync();
            getline(cin, street);
            if(street.length() > 20) {
                is_valid = false;
                throw InvalidStreetAddressException();
            } else if(street.empty()) {
                is_valid = false;
                throw InvalidStreetAddressException();
            } else {};
        } catch(InvalidStreetAddressException e) {
            cout << e.get_message();
        }
    } while(!is_valid);
                                                         /// nafn - ath ad lata setja number i nedri linu
    cout << "Please type in house number." << endl;
    do { ///name - ready
        is_valid = true;
        try {
            cout << "House number: ";
            cin.sync();
            getline(cin, number_input);
            for(unsigned int i = 0; i < number_input.length();i++){
                if(ispunct(number_input[i])){
                    is_valid = false;
                    throw InvalidStreetAddressException();
                }
                else{};
            }
            if(number_input.length() > 20) {
                is_valid = false;
                throw InvalidStreetAddressException();
            } else if(number_input.empty()) {
                is_valid = false;
                throw InvalidStreetAddressException();
            } else {};
        } catch(InvalidStreetAddressException e) {
            cout << e.get_message();
        }
    } while(!is_valid);
    stringstream push_number(number_input);
    push_number >> number;

    PizzaPlace pizza_place(street, number);
    pizza_places.save_pizza_place(pizza_place);
}
void ManagerSubUI::UI_make_other_items() throw (InvalidNameException, InvalidPriceException)
{
    string name;
    int price;
    int type;
    bool is_valid = true;
    string price_input;

    cout << "Please type in a new extra." << endl;
     do { ///name - ready
        is_valid = true;
        try {
            cout << "Name: ";
            cin.sync();
            getline(cin, name);
            if(name.length() > 20) {
                is_valid = false;
                throw InvalidNameException();
            } else if(name.empty()) {
                is_valid = false;
                throw InvalidNameException();
            } else {};
        } catch(InvalidNameException e) {
            cout << e.get_message();
        }
    } while(!is_valid);


    cout << "Type in new extra price." << endl;
    do {
        is_valid = true;
        try {
            cout << "Price: ";
            cin.sync();                                                     /// setja inn throw a illegal number
            getline(cin, price_input);
            for(unsigned int i = 0; i < price_input.length(); i++) {
                if(!isdigit(price_input[i])) {
                    is_valid = false;
                    throw InvalidPriceException();
                } else {};
            }
            if(price_input.empty()) { // passar ad madur slai eitthvad inn
                is_valid = false;
                throw InvalidPriceException();
            } else {};
        } catch(InvalidPriceException e) {
            cout << e.get_message();
        }
        stringstream push_price(price_input);
        push_price >> price;
    } while(!is_valid);



    cout << "Type: \n\t1 for soda\n\t2 for sauces\n\t3 side dishes" << endl; /// herna get eg kannski stungid inn djos tharna... moddinu fyrir thetta Uppi
        do { //mod for menunumber - not universally adaptive (see below)
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
                if(!isdigit(type_input[i]) || type_input[i]>'3' || type_input[i]<'1') { // because of this (see above)
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

    OtherProducts other_products(name, price, type);
    serv.save_other_products(other_products);
}
ManagerSubUI::~ManagerSubUI()
{
    //dtor
}
