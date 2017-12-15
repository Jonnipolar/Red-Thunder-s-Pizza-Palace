#include "ManagerSubUI.h"

void ManagerSubUI::UI_Start() throw (InvalidMenuNumberException, InvalidFileNotOpenException)
{

    string selection;                                                                          // Declare selection char
    bool is_valid = true;
    unsigned int check;
    while (check != 6) {                                                               // While user does not want to quit
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
                check = valid.get_integer_input_variable_size(selection, 6);
                switch (check) {
                case 1:                                                                    // if user picks p create pizza
                    UI_select_make_pizza();
                    break;
                case 2:
                    UI_make_toppings();
                    break;
                case 3:
                    Print_pizza_menu();
                    do {
                        cout << "\nPress enter to continue. \n";
                        cin.sync();
                    } while(cin.get() != '\n');
                    break;
                case 4:
                    UI_make_other_items();
                    break;
                case 5:
                    UI_make_pizza_place();
                    break;
                case 6:
                    break;
                default:
                    is_valid = false;
                    throw InvalidMenuNumberException();
                    break;
                }
            } catch(InvalidMenuNumberException e) {
                cout << e.get_message();
            };
        } while(!is_valid);
    }
}

void ManagerSubUI::Print_pizza_menu() throw (InvalidFileNotOpenException)
{
    vector <Pizza> pizza;
    bool is_valid = true;
    try {
        do {
            is_valid = true;
            pizza = pizza_service.get_pizzas();
            for (unsigned int i = 0; i < pizza.size(); i++) {
                cout << pizza[i];
            };
        } while (!is_valid);
    } catch(InvalidFileNotOpenException e) {
        is_valid = false;
        cout << e.get_message();
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
    bool is_valid = true;
    string price_input;
    string name;
    unsigned int price;
    PizzaSize _size;
    PizzaBottom bottom;
    system("CLS");
    try {
        cout << "Please type in new pizza name" << endl;
        do{
            cout << "Name: ";
            cin.sync();
            getline(cin, name);
            try{
                name = valid.get_name(name);
            }catch(InvalidNameException e) {
                cout << e.get_message();
            }
        }while(!is_valid);
        vector <Toppings> userToppings = SubUI_add_topping();
        cout << "\nYour toppings are: " << endl;
        for (unsigned int i = 0; i < userToppings.size(); i++) {
            cout << "\t[" << i+1 << "] " << "Name of Topping: " << userToppings[i].get_name() << endl;
        }
        do{
            cout << "\nSelect the price for the pizza" << endl;
            cout << "Price: ";
            cin.sync();                                                                      /// setja inn throw a illegal number
            getline(cin, price_input);
            try {
                price = valid.get_price(price_input);
            }catch(InvalidPriceException e) {
                cout << e.get_message();
                is_valid = false;
            }
        }while(!is_valid);
        pizza_service.save_pizza(name,price,userToppings,bottom,_size);
    } catch(InvalidFileNotOpenException e) {
        cout << e.get_message();
        do {
            cout << "\nPress enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
}
vector <Toppings> ManagerSubUI::SubUI_add_topping()
{
    string input_input;
    vector <Toppings> cheeseTopp = toppings_list.get_selected_list(3);
    vector <Toppings> meatTopp = toppings_list.get_selected_list(1);
    vector <Toppings> vegetableTopp = toppings_list.get_selected_list(2);
    vector <Toppings> toppings;
    vector <Toppings> userToppings;
    unsigned int ToppSel = -1;
    unsigned int ToppingAmount = cheeseTopp.size() + meatTopp.size() + vegetableTopp.size();
    while (ToppSel != 0) {
        try {
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
            cout << "Select option: ";
            cin.sync();
            getline(cin,input_input);
            try {
                ToppSel = valid.get_integer_input_variable_size(input_input, ToppingAmount);
            }catch(InvalidMenuNumberException e) {
                cout << e.get_message();
            }
            if (ToppSel > 0 && ToppSel <= ToppingAmount) {
                userToppings.push_back(toppings[ToppSel-1]);
            }
        }catch(InvalidFileNotOpenException e) {
            cout << e.get_message();
        }
    }
    do {
        cout << "\nPress enter to continue. \n";
        cin.sync();
    } while(cin.get() != '\n');
    return userToppings;
}
void ManagerSubUI::UI_make_toppings()
{
    bool is_valid = true;
    string price_input;
    string input_input;
    string name;
    unsigned int type;
    unsigned int price;
    try{
        system("CLS");
        cout << "Please type in topping" << endl;
        do{
            is_valid = true;
            cout << "Name: ";
            cin.sync();
            getline(cin, name);
            try{
                name = valid.get_name(name);
            }catch(InvalidNameException e) {
                cout << e.get_message();
                is_valid = false;
            }
        }while(!is_valid);
        do{
            is_valid = true;
            cout << "Please type in price of topping" << endl;
            cout << "Price: ";
            cin.sync();                                                                      /// setja inn throw a illegal number
            getline(cin, price_input);
            try {
                price = valid.get_price(price_input);
            }catch(InvalidPriceException e) {
                cout << e.get_message();
                is_valid = false;
            }
        }while(!is_valid);
        cout << "Type: \n\t1 for meat\n\t2 for vegetable\n\t3 for cheese" << endl;
        cout << "Select option: ";
        cin.sync();
        getline(cin,input_input);
        try {
            type = valid.get_integer_input_variable_size(input_input,3);
        }catch(InvalidMenuNumberException e) {
            cout << e.get_message();
        }
        toppings_list.save_topping_list(name, price, type);                                      // sendir í function sem vistar í skjal
    }catch(InvalidFileNotOpenException e){
        cout << e.get_message();
        do {
            cout << "\nPress enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
}
void ManagerSubUI::UI_make_size()
{
    bool is_valid = true;
    string price_input;
    string name;
    unsigned int price;
    try{
        system("CLS");
        cout << "Please type in new size name (description)." << endl;
        do{
            is_valid = true;
            cout << "Name: ";
            cin.sync();
            getline(cin, name);
            try{
                name = valid.get_name(name);
            }catch(InvalidNameException e) {
                cout << e.get_message();
                is_valid = false;
            }
        }while(!is_valid);
        do{
            is_valid = true;
            cout << "Select price for size.\n";
            cout << "Price: ";
                cin.sync();                                                                      /// setja inn throw a illegal number
                getline(cin, price_input);
            try{
                price = valid.get_price(price_input);
            }catch(InvalidPriceException e) {
                cout << e.get_message();
                is_valid = false;
            }
        }while(!is_valid);
        pizza_size.save_pizza_size(name, price);
    }catch(InvalidFileNotOpenException e){
        cout << e.get_message();
        do {
            cout << "\nPress enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
}
void ManagerSubUI::UI_make_bottom()
{
    bool is_valid = true;
    string price_input;
    string name;
    unsigned int price;
    try{
        system("CLS");
        cout << "Please type in new bottom name (description)." << endl;
        do{
            is_valid = true;
            cout << "Name: ";
            cin.sync();
            getline(cin, name);
            try {
                name = valid.get_name(name);
            }catch(InvalidNameException e) {
                cout << e.get_message();
                is_valid = false;
            }
        }while(!is_valid);
        do{
            is_valid = true;
            cout << "Select price for bottom." << endl;
            cout << "Price: ";
            cin.sync();                                                                      /// setja inn throw a illegal number
            getline(cin, price_input);
            try {
                price = valid.get_price(price_input);
            }catch(InvalidPriceException e) {
                cout << e.get_message();
                is_valid = false;
            }
        }while(!is_valid);
        PizzaBottom pizza_bottoms(name, price);
        pizza_bottom.save_pizza_bottom(name, price);

    }catch(InvalidFileNotOpenException e){
        cout << e.get_message();
        do {
            cout << "\nPress enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
}
void ManagerSubUI::UI_make_pizza_place() throw (InvalidStreetAddressException)
{
    string street;
    int number;
    string number_input;
    bool is_valid = true;
    try{
    cout << "Please type in a new address." << endl;
    do {                                                           // laet inn sama og fyrir name nema med "street" i stad name                         ///name - ready
        is_valid = true;
        try {
            string name;
            cout << "Street name: ";
            cin.sync();
            getline(cin, street);
            if(street.length() > 20) {                      /// laga throw catch service layer
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

    pizza_places.save_pizza_place(street, number);}catch(InvalidFileNotOpenException e){
        cout << e.get_message();
        do {
            cout << "\nPress enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
}
void ManagerSubUI::UI_make_other_items()
{
    bool is_valid;
    string input_input;
    string price_input;
    string name;
    unsigned int price;
    unsigned int type;
    try{
        cout << "Please type in a new extra." << endl;
        do{
            is_valid = true;
            cout << "Name: ";
            cin.sync();
            getline(cin, name);
            try{
                name = valid.get_name(name);
            }catch(InvalidNameException e) {
                cout << e.get_message();
                is_valid = false;
            }
        }while(!is_valid);
        do{
            is_valid = true;
            cout << "Type in new extra price." << endl;
            cout << "Price: ";
            cin.sync();                                                                      /// setja inn throw a illegal number
            getline(cin, price_input);
            try {
                price = valid.get_price(price_input);
            }catch(InvalidPriceException e) {
                cout << e.get_message();
                is_valid = false;
            }
        }while(!is_valid);
        cout << "Type: \n\t1 for soda\n\t2 for sauces\n\t3 side dishes" << endl;                 /// herna get eg kannski stungid inn djos tharna... moddinu fyrir thetta Uppi
        cout << "Select option: ";
        cin.sync();
        getline(cin,input_input);
        try {
            type = valid.get_integer_input_variable_size(input_input,3);
        }catch(InvalidMenuNumberException e) {
            cout << e.get_message();
        }
        serv.save_other_products(name, price, type);
    }catch(InvalidFileNotOpenException e){
        cout << e.get_message();
        do {
            cout << "\nPress enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    }
}

ManagerSubUI::~ManagerSubUI()
{
    //dtor
}

