#include "ManagerSubUI.h"

ManagerSubUI::ManagerSubUI()
{
    //ctor
}
void ManagerSubUI::UI_Start() throw (InvalidMenuNumberException, InvalidFileNotOpenException)
{
    vector <Pizza> pizza;
    char selection;                                                                          // Declare selection char
    bool is_valid = true;
    while (selection != '6') {                                                               // While user does not want to quit
        system("CLS");
        cout << "Hello Mr. Manager" << endl;                                                 // Welcome message
        cout << "What would you like to do:" << endl;                                        // -||-
        cout << "[1] Make pizza" << endl;                                                    // Menu for user to pick
        cout << "[2] Make topping" << endl;                                                  // ------""-------------
        cout << "[3] View pizza menu" << endl;                                               // ------""-------------
        cout << "[4] Add other items" << endl;                                               // ------""-------------
        cout << "[5] Add pizza place" << endl;                                               // ------""-------------
        cout << "[6] Back to main menu" << endl;                                             // ------""-------------
        do {
            try {
                is_valid = true;
                cout << "Select option: ";
                cin >> selection;
                switch (selection) {
                case '1':                                                                    // if user picks p create pizza
                    UI_select_make_pizza();
                    break;
                case '2':
                    UI_make_toppings();
                    break;
                case '3':
                    pizza = pizza_service.get_pizzas();
                    cin >> selection;
                    for (unsigned int i = 0; i < pizza.size(); i++) {
                        cout << pizza[i];
                    };
                    if(!is_valid){
                        break;
                    }else{};                                                          ///HVAD ER THETTA HER?? A THETTA EKKI HEIMA ANNARSTADAR?? setja number throw??
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
    bool is_valid = true;                                                                    // is valid heldur user i loop a medan thu ert med vitlaust svar.
    char selection;

    system("CLS");
    cout << "[1] Make new size" << endl;
    cout << "[2] Make new bottom" << endl;
    cout << "[3] Make Pizza" << endl;
    cout << "[4] Back to main menu" << endl;
    do {
        try {                                                                                //try og throw komid
            is_valid = true;
            cout << "Select option: ";
            cin >> selection;
            switch (selection) {
            case '1':
                UI_make_size();
                break;
            case '2':                                                                        // if user picks t create topping
                UI_make_bottom();
                break;
            case '3':                                                                        // if user picks m Create menu
                UImake_pizza();
                break;
            case '4':
                break;
            default:                                                                         //kastar a throw
                is_valid = false;
                throw InvalidMenuNumberException();
            }
        } catch(InvalidMenuNumberException e) {                                              // gripur throw i message
            cout << e.get_message();
        }
    } while(!is_valid);
}

void ManagerSubUI::UImake_pizza()
{
    PizzaSize _size;
    PizzaBottom bottom;
    system("CLS");
    cout << "Please type in new pizza name" << endl;
    string name = get_name();
    vector <Toppings> userToppings = SubUI_add_topping();
    cout << "\nYour toppings are: " << endl;
    for (unsigned int i = 0; i < userToppings.size(); i++) {
        cout << "\t[" << i+1 << "] " << "Name of Topping: " << userToppings[i].get_name() << endl;
    }
    cout << "\nSelect the price for the pizza" << endl;
    unsigned int price = get_price();


    pizza_service.save_pizza(name,price,userToppings,bottom,_size);}
vector <Toppings> ManagerSubUI::SubUI_add_topping()
{
    vector <Toppings> cheeseTopp = toppings_list.get_selected_list(3);
    vector <Toppings> meatTopp = toppings_list.get_selected_list(1);
    vector <Toppings> vegetableTopp = toppings_list.get_selected_list(2);
    vector <Toppings> toppings;
    vector <Toppings> userToppings;
    unsigned int ToppSel = -1;
    unsigned int ToppingAmount = cheeseTopp.size() + meatTopp.size() + vegetableTopp.size();
    while (ToppSel != 0) {                                                                   ///vantar ekki numberthrow herna lika?
        try{
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
            ToppSel = get_integer_input_variable_size_with_zeroescape(ToppingAmount);
            if (ToppSel > 0 && ToppSel <= ToppingAmount) {
                userToppings.push_back(toppings[ToppSel-1]);
            }
        }catch(InvalidMenuNumberException e){
            cout << e.get_message();
        }
    }
    return userToppings;
}
void ManagerSubUI::UI_make_toppings()
{
    system("CLS");
    cout << "Please type in topping" << endl;
    string name = get_name();
    cout << "Please type in price of topping" << endl;
    unsigned int price = get_price();
    cout << "Type: \n\t1 for meat\n\t2 for vegetable\n\t3 for cheese" << endl;
    unsigned int type = get_integer_input_variable_size(3);

    toppings_list.save_topping_list(name, price, type);                                      // sendir í function sem vistar í skjal
}
void ManagerSubUI::UI_make_size()
{
    system("CLS");
    cout << "Please type in new size name (description)." << endl;
    string name = get_name();
    cout << "Select price for size.\n";
    unsigned int price = get_price();

    pizza_size.save_pizza_size(name, price);
}
void ManagerSubUI::UI_make_bottom()
{
    system("CLS");
    cout << "Please type in new bottom name (description)." << endl;
    string name = get_name();

    cout << "Select price for bottom." << endl;
    unsigned int price = get_price();

    PizzaBottom pizza_bottoms(name, price);
    pizza_bottom.save_pizza_bottom(name, price);
}
void ManagerSubUI::UI_make_pizza_place() throw (InvalidStreetAddressException)
{
    string street;
    int number;
    string number_input;
    bool is_valid = true;

    cout << "Please type in a new address." << endl;
    do {                                                           // laet inn sama og fyrir name nema med "street" i stad name                         ///name - ready
        is_valid = true;
        try {
            string name;
            cout << "Street name: ";
            cin.sync();
            getline(cin, street);
            if(street.length() > 20) {
                is_valid = false;
                throw InvalidStreetAddressException();
            } else if(street.empty() || isspace(street[0])) {
                is_valid = false;
                throw InvalidStreetAddressException();
            } else {};
        } catch(InvalidStreetAddressException e) {
            cout << e.get_message();
        }
    } while(!is_valid);

    cout << "Please type in house number." << endl;
    do {                                                                                     //sama og fyrir name nema með house number
        is_valid = true;
        try {
            cout << "House number: ";
            cin.sync();
            getline(cin, number_input);
            for(unsigned int i = 0; i < number_input.length(); i++) {
                if(ispunct(number_input[i])) {
                    is_valid = false;
                    throw InvalidStreetAddressException();
                } else {};
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

    pizza_places.save_pizza_place(street, number);
}
void ManagerSubUI::UI_make_other_items()
{
    cout << "Please type in a new extra." << endl;
    string name = get_name();
    cout << "Type in new extra price." << endl;
    unsigned int price = get_price();
    cout << "Type: \n\t1 for soda\n\t2 for sauces\n\t3 side dishes" << endl;                 /// herna get eg kannski stungid inn djos tharna... moddinu fyrir thetta Uppi
    unsigned int type = get_integer_input_variable_size(3);

    serv.save_other_products(name, price, type);
}

ManagerSubUI::~ManagerSubUI()
{
    //dtor
}

string ManagerSubUI::get_name() throw (InvalidNameException)
{
    string name;
    bool is_valid = true;
    do {                                                                                     ///name - ready
        is_valid = true;
        try {
            cout << "Name: ";
            cin.sync();
            getline(cin, name);
            if(name.length() > 20 || isspace(name[0])) {
                is_valid = false;
                throw InvalidNameException();
            } else {};
            if(name.empty()) {
                is_valid = false;
                throw InvalidNameException();
            } else {};
        } catch(InvalidNameException e) {
            cout << e.get_message();
        }
    } while(!is_valid);
    return name;
}

unsigned int ManagerSubUI::get_price() throw (InvalidPriceException)
{
    string price_input;
    unsigned int price;
    bool is_valid = true;
    do {
        is_valid = true;
        try {
            cout << "Price: ";
            cin.sync();                                                                      /// setja inn throw a illegal number
            getline(cin, price_input);
            for(unsigned int i = 0; i < price_input.length(); i++) {
                if(!isdigit(price_input[i])) {
                    is_valid = false;
                    throw InvalidPriceException();
                } else {};
            }
            if(price_input.empty()) {                                                        // passar ad madur slai eitthvad inn
                is_valid = false;
                throw InvalidPriceException();
            } else {};
        } catch(InvalidPriceException e) {
            cout << e.get_message();
        }
        stringstream push_price(price_input);
        push_price >> price;
    } while(!is_valid);
    return price;
}

unsigned int ManagerSubUI::get_integer_input_variable_size(unsigned int size) throw (InvalidMenuNumberException) //skilar int eftir s
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
            if(input == 0){break;}else
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
unsigned int ManagerSubUI::get_integer_input_variable_size_with_zeroescape(unsigned int size) throw (InvalidMenuNumberException) //skilar int eftir s
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
            if(input == 0){break;}else
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
