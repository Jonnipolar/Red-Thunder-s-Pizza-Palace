#include "DeliveryUI.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}
void DeliveryUI::StartUI() {
      vector <PizzaPlace> pizza_places = pizza_service.get_pizza_place();
    //unsigned int placeSel = -1; fjarlægi þetta decleration og set það fyrir neðan í place-sel svo það validate-i menu choice þegar það býr til.
    string select;
    bool is_valid = true;
    system("CLS");
    cout << "Welcome To the Bakery!" << endl;
    cout << "Please choose the address of the place where you will be working at" << endl;
    for ( unsigned int i = 0; i < pizza_places.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizza_places[i].get_street() << endl;
    }
    cout << "\n";
    do{
        is_valid = true;
        cin.sync();
        getline(cin, select);
        try{
            unsigned int placeSel = valid.get_integer_input_variable_size(select, pizza_places.size());
            if (placeSel > 0 && placeSel <= pizza_places.size()) {
                string street = pizza_places[placeSel - 1].get_street();
                UI_sub(street);
            }
        }catch (InvalidMenuNumberException e) {
            cout << e.get_message();
            is_valid = false;
        }
    }while(!is_valid);
}
void DeliveryUI::UI_sub(string street) {
    string selection;
    unsigned int check;
    bool is_valid = true;
    do{
        system("CLS");
        cout << "Welcome to " << street << endl;
        cout << "Please select an option" << endl;
        cout << "[1] List of all orders" << endl;
        cout << "[2] List of all done orders" << endl;
        cout << "[3] Return to main menu" << endl;
        try {
            is_valid = true;
            cin >> selection;
            check = valid.get_integer_input_variable_size(selection, 3);
            switch (check) {
                case 1:
                    list_all_orders(street);
                    break;
                case 2:
                    list_done_orders(street);
                    break;
                case 3:
                    is_valid = false;
                    break;
            }
        } catch(InvalidMenuNumberException e) {
                cout << e.get_message();
        };
    }while(is_valid);
}
void DeliveryUI::list_all_orders (string street) {
    string selection;
    string selection2;
    unsigned int placeSel;
    bool is_valid = true;
    system("CLS");
    vector <Order> order = order_service.get_all_orders_by_street(street);
    cout << "Here is a list of all orders" << endl;
    for(unsigned int i = 0; i < order.size(); i++) {
        cout << "[" << i+1 << "] " << "Name: " << order[i].get_name()
        << " Status: " << order[i].get_orderStatus() << " Price: "
        << order[i].get_totalAmount() << " Paid status: " << order[i].get_HasBeenPaidFor() << endl;
    }
    cout << "Do you want to change paid status?" << endl;
    cout << "[1] Yes" << endl;
    cout << "[2] No" << endl;
    do {
        try {
            is_valid = true;
            cout << "Select option: ";
            cin >> selection;
            placeSel = valid.get_integer_input_variable_size(selection, 2);
            switch (placeSel) {
                case 1:
                    do{
                        is_valid = true;
                        cout << "Select order: ";
                        cin >> selection2;
                        try{
                            placeSel = valid.get_integer_input_variable_size(selection2, order.size());
                            order_service.change_paid_status(placeSel, street);
                        }catch(InvalidMenuNumberException e){
                            cout << e.get_message();
                            is_valid = false;
                        };
                    }while(!is_valid);
                    break;
                case 2:
                    is_valid = true;
                    break;
            }
        } catch(InvalidMenuNumberException e) {
                    cout << e.get_message();
                    is_valid = false;
        };
    } while(!is_valid);

}
void DeliveryUI::list_done_orders(string street) {
    system("CLS");
    bool is_valid = true;
    unsigned int placeSel;
    string selection;
    string input_input;
    vector <Order> order = order_service.get_done_orders_by_street(street);
    cout << "Here is a list of all done orders" << endl;
    for(unsigned int i = 0; i < order.size(); i++) {
        cout << "[" << i+1 << "] " << "Name: " << order[i].get_name()
        <<  " Price: " << order[i].get_totalAmount() << " Paid status: "
        << order[i].get_HasBeenPaidFor() << endl;
    }
    cout << "Do you want to select an order to checkout" << endl;
    cout << "[1] Yes" << endl;
    cout << "[2] No" << endl;
    do {
        try {
            cout << "Select option: ";
            cin >> selection;
            placeSel = valid.get_integer_input_variable_size(selection, 2);
            switch (placeSel) {
                case 1:
                    do{
                        is_valid = true;
                        cout << "Select order: ";
                        cin.sync();
                        getline(cin,input_input);
                        try{
                            placeSel = valid.get_integer_input_variable_size(input_input, order.size());
                            try{
                                legacy_serv.change_status(placeSel, order);
                                order_service.set_done_orders(order, placeSel);
                            }catch (InvalidFileNotOpenException e) {
                                cout << e.get_message();
                                is_valid = false;
                            }
                        }catch (InvalidMenuNumberException e) {
                            cout << e.get_message();
                            is_valid = false;
                        }
                    }while(!is_valid);
                    break;
                case 2:
                    is_valid = false;
                    break;
            }
        } catch(InvalidMenuNumberException e) {
                    cout << e.get_message();
                    is_valid = true;
        };
    } while(is_valid);
}
DeliveryUI::~DeliveryUI()
{
    //dtor
}
