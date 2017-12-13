#include "BakeryUI.h"


void BakeryUI::StartUI() {/// I MESSED WITH UR CODE (bara smá samt)
    vector <PizzaPlace> pizza_places = pizza_service.get_pizza_place();
    //unsigned int placeSel = -1; fjarlægi þetta decleration og set það fyrir neðan í place-sel svo það validate-i menu choice þegar það býr til.
    system("CLS");
    cout << "Welcome To the Bakery!" << endl;
    cout << "Please choose the address of the place where you will be working at" << endl;
    for ( unsigned int i = 0; i < pizza_places.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizza_places[i].get_street() << endl;
    }
    cout << "\n";

    /// !!! nota frekar unsigned int þá þarftu ekki að harðkóða int inn á size.
    /// þá er líka hægt að nota inputfallið sem ég kalla í hér.
    /// einnig eru sambærileg finctions fyrir price og strings í manager subUI
    /// sem er hægt að kopera eða talar við mig og ég lít á þetta líka.

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
void BakeryUI::UI_processing(string street) {
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
            orders_by_street = order_service.get_processing_orders_by_street(street);
            UI_add_to_progress(orders_by_street);
            break;
        case '2':
            break;
    }
}
void BakeryUI::UI_add_to_progress(vector <Order> by_street) {

}
