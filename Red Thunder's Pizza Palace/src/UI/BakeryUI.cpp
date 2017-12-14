#include "BakeryUI.h"


void BakeryUI::StartUI() {
    vector <PizzaPlace> pizza_places = pizza_service.get_pizza_place();
    system("CLS");
    cout << "Welcome To the Bakery!" << endl;
    cout << "Please choose the address of the place where you will be working at" << endl;
    for ( unsigned int i = 0; i < pizza_places.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizza_places[i].get_street() << endl;
    }
    cout << "\n";
    unsigned int placeSel = get_integer_input_variable_size(pizza_places.size());
    if (placeSel > 0 && placeSel <= pizza_places.size()) {
        string street = pizza_places[placeSel - 1].get_street();
        UI_sub(street);
    }

}
unsigned int BakeryUI::get_integer_input_variable_size(unsigned int size) throw (InvalidMenuNumberException) //skilar int eftir s
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
            if(input > size || input <1 || input_input.empty()) {  ///hafa í service öll vinnsla í service
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
void BakeryUI::UI_sub(string street) {
    char selection;
    system("CLS");
    cout << "Welcome to " << street << endl;
    cout << "Please select option" << endl;
    cout << "[1] Orders in processing" << endl;
    cout << "[2] Orders in progress" << endl;
    cin >> selection;
    switch (selection) {
        case '1':
            UI_processing(street);
            break;
        case '2':
            break;
    }
}
void BakeryUI::UI_processing(string street) throw (InvalidFileNotOpenException) {
    char selection;
    system("CLS");
    vector <Order> orders_by_street;
    cout << "Welcome to " << street << endl;
    cout << "Please select option" << endl;
    cout << "[1] list of orders in processing" << endl;
    cout << "[2] First 3 orders in processing" << endl;
    cin >> selection;
    switch (selection) {
        case '1':
            try{
                orders_by_street = order_service.get_processing_orders_by_street(street);
                UI_add_to_progress(orders_by_street);
            }
            catch(InvalidFileNotOpenException e){
                cout << e.get_message();
                do {
                    cout << "Press enter to continue. \n";
                    cin.sync();
                }
                while(cin.get() != '\n');
            }
            break;
        case '2':
            break;
    }
}
void BakeryUI::UI_add_to_progress(vector <Order> by_street) {
    system("CLS");
    cout << "Here is a list of orders not processed" << endl;
    for ( unsigned int i = 0; i < by_street.size(); i++) {
        vector <Pizza> pizzas = by_street[i].get_pizzas();
        cout << "[" << i+1 << "] " << by_street[i].get_name() << endl;
        for ( unsigned int j = 0; j < pizzas.size(); j++ ) {
            vector <Toppings> toppings = pizzas[j].get_toppings();
            cout << "\t" << pizzas[j].get_name() << "\n\tBottom: " << pizzas[j].get_bottom() << "\tSize: " << pizzas[j].get_size();
            cout << "\tToppings: ";
            for ( unsigned int x = 0; x < toppings.size(); x++ ) {
                cout << toppings[x].get_name() << ", ";
            }
            cout << "\n";
        }
    }
    cout << "\n";
    unsigned int selection = get_integer_input_variable_size(by_street.size());


}
