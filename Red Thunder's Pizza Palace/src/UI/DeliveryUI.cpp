#include "DeliveryUI.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}
void DeliveryUI::StartUI() {
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
unsigned int DeliveryUI::get_integer_input_variable_size(unsigned int size) throw (InvalidMenuNumberException) //skilar int eftir s
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
            if(input > size || input <1 || input_input.empty()) { /// sama og í bakery
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
void DeliveryUI::UI_sub(string street) {
    char selection;
    bool is_valid = true;
    system("CSL");
    cout << "Welcome to " << street << endl;
    cout << "Please select an option" << endl;
    cout << "[1] List of all orders" << endl;
    cout << "[2] List of all done orders" << endl;
    cout << "[3] Return to main menu" << endl;
    do {
        try {

            cin >> selection;
            switch (selection) {
                case '1':
                    list_all_orders(street);
                    break;
                case '2':
                    //list_done_orders(street);
                    break;
                case '3':
                    break;
                default :
                    is_valid = false;
                    throw InvalidMenuNumberException();
                    break;
            }
        } catch(InvalidMenuNumberException e) {
                    cout << e.get_message();
        };
    } while(!is_valid);
}
void DeliveryUI::list_all_orders (string street) {
    char selection;
    system("CSL");
    vector <Order> order = order_service.get_all_orders_by_street(street);
    cout << "Here is a list of all orders" << endl;
    for(unsigned int i = 0; i < order.size(); i++) {
        cout << "[" << i+1 << "] " << "Name: " << order[i].get_name()
        << " Status: " << order[i].get_orderStatus() << " Price: "
        << order[i].get_totalAmount() << " Paid status: " << order[i].get_HasBeenPaidFor() << endl;
    }

}
void DeliveryUI::list_done_orders(string street) {
    system("CSL");
    vector <Order> order = order_service.get_done_orders_by_street(street);
    cout << "Here is a list of all done orders" << endl;
    for(unsigned int i = 0; i < order.size(); i++) {
        cout << "[" << i+1 << "] " << "Name: " << order[i].get_name()
        <<  " Price: " << order[i].get_totalAmount() << " Paid status: "
        << order[i].get_HasBeenPaidFor() << endl;
    }
    unsigned int placeSel = get_integer_input_variable_size(order.size());

}
DeliveryUI::~DeliveryUI()
{
    //dtor
}
