#include "BakeryUI.h"


void BakeryUI::StartUI() {
    vector <PizzaPlace> pizza_places = pizza_service.get_pizza_place();
    bool is_valid = true;
    string select;
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
void BakeryUI::UI_sub(string street) throw (InvalidMenuNumberException) {
    string selection;
    bool is_valid = true;
    do {
        system("CLS");
        cout << "Welcome to " << street << endl;
        cout << "Please select option" << endl;
        cout << "[1] Orders in processing" << endl;
        cout << "[2] Orders in progress" << endl;
        cout << "[3] Back to main menu" << endl;
        try {
            cin >> selection;
            unsigned int check = valid.get_integer_input_variable_size(selection, 3);
            switch (check) {
            case 1:
                UI_processing(street);
                break;
            case 2:
                UI_in_progress(street);
                break;
            case 3:
                is_valid = false;
                break;
            }
        }catch (InvalidMenuNumberException e) {
            cout << e.get_message();
            do {
                cout << "\nPress enter to continue. \n";
                cin.sync();
            } while(cin.get() != '\n');
        }
    } while(is_valid);
}
void BakeryUI::UI_processing(string street) throw (InvalidFileNotOpenException, InvalidMenuNumberException) {
    string selection;
    bool is_valid = true;

    system("CLS");
    vector <Order> orders_by_street;
    do {
        system("CLS");
        cout << "Welcome to " << street << endl;
        cout << "Please select option" << endl;
        cout << "[1] list of orders in processing" << endl;
        cout << "[2] Back to Main Menu" << endl;
        try {
            cin >> selection;
            unsigned int check = valid.get_integer_input_variable_size(selection, 2);
            switch (check) {
                case 1:
                    orders_by_street = order_service.get_processing_orders_by_street(street);
                    UI_add_to_progress(orders_by_street);
                    break;
                case 2:
                    is_valid = false;
                    break;
            }
        } catch(InvalidMenuNumberException e) {
            cout << e.get_message();
            do {
                cout << "\nPress enter to continue. \n";
                cin.sync();
            } while(cin.get() != '\n');
        };
    } while(is_valid);

}
void BakeryUI::UI_in_progress(string street) throw (InvalidFileNotOpenException, InvalidMenuNumberException) {
    string selection;
    bool is_valid = true;
    do {
        system("CLS");
        vector <Order> orders_by_street;
        cout << "Welcome to " << street << endl;
        cout << "Please select option" << endl;
        cout << "[1] list of orders in progress" << endl;
        cout << "[2] Back to Main Menu" << endl;
        try {
            cin >> selection;
            unsigned int check = valid.get_integer_input_variable_size(selection, 2);
            switch (check) {
                case 1:
                    orders_by_street = order_service.get_in_progress_orders_by_street(street);
                    UI_add_to_done(orders_by_street);
                    break;
                case 2:
                    is_valid = false;
                    break;
            }
    } catch(InvalidMenuNumberException e) {
        cout << e.get_message();
        do {
            cout << "\nPress enter to continue. \n";
            cin.sync();
        } while(cin.get() != '\n');
    };
    } while(is_valid);

}
void BakeryUI::UI_add_to_done(vector <Order> by_street) {
    system("CLS");
    string select;
    bool is_valid = true;
    unsigned int check;
    cout << "Here is a list of orders in progress, but not done" << endl;
    for ( unsigned int i = 0; i < by_street.size(); i++) {
        vector <Pizza> pizzas = by_street[i].get_pizzas();
        cout << "[" << i+1 << "] " << by_street[i].get_name() << endl;
        for ( unsigned int j = 0; j < pizzas.size(); j++ ) {
            vector <Toppings> toppings = pizzas[j].get_toppings();
            PizzaBottom bottom = pizzas[j].get_bottom();
            PizzaSize p_size = pizzas[j].get_size();
            cout << "\t" << pizzas[j].get_name() << "\n\tBottom: " << bottom.get_type() << "\n\tSize: " << p_size.get_size();
            cout << "\n\tToppings: ";
            for ( unsigned int x = 0; x < toppings.size(); x++ ) {
                if (x != toppings.size() - 1) {
                    cout << toppings[x].get_name() << ", ";
                }
                else {
                    cout << toppings[x].get_name() << endl;
                }
            }
        }
        vector <OtherProducts> other = by_street[i].get_other_prod();
        for ( unsigned int i = 0; i < other.size(); i++ ) {
            cout << "\t" << other[i].get_name() << endl;
        }
    }
    cout << "\n";
    cout << "[1] work on order" << endl;
    cout << "[2] Back" << endl;
    do{
        try{
            cin >> select;
            cout << "Selection: ";
            check = valid.get_integer_input_variable_size(select, 2);
            if(check == 1) {
                    do{
                        try{
                            is_valid = true;
                            cout << "Select order to work on" << endl;
                            cin >> select;
                            unsigned int selection = valid.get_integer_input_variable_size(select, by_street.size());
                            Order sel_order = by_street[selection - 1];
                            UI_change_to_done(sel_order, selection);
                            check = 2;
                        }catch(InvalidMenuNumberException e) {
                            cout << e.get_message();
                            is_valid = false;
                        }
                    }while(!is_valid);
            }
        }catch(InvalidMenuNumberException e) {
            cout << e.get_message();
        }
    }while(check != 2);
}
void BakeryUI::UI_add_to_progress(vector <Order> by_street) {
    string select;
    bool is_valid = true;
    unsigned int check;
    system("CLS");
    cout << "Here is a list of orders not processed" << endl;
    for ( unsigned int i = 0; i < by_street.size(); i++) {
        vector <Pizza> pizzas = by_street[i].get_pizzas();
        cout << "[" << i+1 << "] " << by_street[i].get_name() << endl;
        for ( unsigned int j = 0; j < pizzas.size(); j++ ) {
            vector <Toppings> toppings = pizzas[j].get_toppings();
            PizzaBottom bottom = pizzas[j].get_bottom();
            PizzaSize p_size = pizzas[j].get_size();
            cout << "\t" << pizzas[j].get_name() << "\n\tBottom: " << bottom.get_type() << "\n\tSize: " << p_size.get_size();
            cout << "\n\tToppings: ";
            for ( unsigned int x = 0; x < toppings.size(); x++ ) {
                if (x != toppings.size() - 1) {
                    cout << toppings[x].get_name() << ", ";
                }
                else {
                    cout << toppings[x].get_name() << endl;
                }
            }
        }
        vector <OtherProducts> other = by_street[i].get_other_prod();
        for ( unsigned int i = 0; i < other.size(); i++ ) {
            cout << "\t" << other[i].get_name() << endl;
        }
    }
    cout << "\n";
        cout << "[1] work on order" << endl;
        cout << "[2] Back" << endl;
    do{
        try{
            cin >> select;
            check = valid.get_integer_input_variable_size(select, 2);
            if(check == 1) {
                    do{
                        try{
                            is_valid = true;
                            cout << "Select order to work on" << endl;
                            cin >> select;
                            unsigned int selection = valid.get_integer_input_variable_size(select, by_street.size());
                            Order sel_order = by_street[selection - 1];
                            UI_change_to_in_progress(sel_order, selection);
                            check = 2;
                        }catch(InvalidMenuNumberException e) {
                            cout << e.get_message();
                            is_valid = false;
                        }
                    }while(!is_valid);
            }
        }catch(InvalidMenuNumberException e) {
            cout << e.get_message();
        }
    }while(check != 2);
}
void BakeryUI::UI_change_to_in_progress(Order& order, int sel) {
    unsigned int done;
    string select;
    PizzaPlace place = order.get_OrderLocation();
    order_service.change_proc_to_inPro(sel, place.get_street());
    system("CLS");
    cout << "Name: " << order.get_name() << endl;
    vector <Pizza> pizzas = order.get_pizzas();
    vector <OtherProducts> other = order.get_other_prod();
    for ( unsigned int i = 0; i < pizzas.size(); i++ ) {
        vector <Toppings> toppings = pizzas[i].get_toppings();
        PizzaBottom bottom = pizzas[i].get_bottom();
        PizzaSize p_size = pizzas[i].get_size();
        cout << "\t" << pizzas[i].get_name() << "\n\tBottom: " << bottom.get_type() << "\n\tSize: " << p_size.get_size() << endl;
        cout << "\tToppings: ";
        for ( unsigned int j = 0; j < toppings.size(); j++) {
            if (j != toppings.size() - 1) {
                cout << toppings[i].get_name() << ", ";
            }
            else {
                cout << toppings[i].get_name() << endl;
            }
        }
    }
    for ( unsigned int i = 0; i < other.size(); i++ ) {
        cout << "\t" << other[i].get_name() << endl;
    }
    cout << "[1] Done?" << endl;
    cout << "[2] Back to Main Menu" << endl;
    ///setja inn rett check
    do{
        try {
            cin >> select;
            done = valid.get_integer_input_variable_size(select, 2);

            if (done == 1) {
                vector <Order> orders = order_service.get_in_progress_orders_by_street(place.get_street());
                order_service.change_inPro_to_Done((int)orders.size(), place.get_street());
                done = 2;
            }
        }catch (InvalidMenuNumberException e) {
            cout << e.get_message();
        }
    }while(done != 2);
}
void BakeryUI::UI_change_to_done(Order& order, int sel) {
    unsigned int done;
    string select;
    PizzaPlace place = order.get_OrderLocation();
    system("CLS");
    cout << "Name: " << order.get_name() << endl;
    vector <Pizza> pizzas = order.get_pizzas();
    vector <OtherProducts> other = order.get_other_prod();
    for ( unsigned int i = 0; i < pizzas.size(); i++ ) {
        vector <Toppings> toppings = pizzas[i].get_toppings();
        PizzaBottom bottom = pizzas[i].get_bottom();
        PizzaSize p_size = pizzas[i].get_size();
        cout << "\t" << pizzas[i].get_name() << "\n\tBottom: " << bottom.get_type() << "\n\tSize: " << p_size.get_size() << endl;
        cout << "\tToppings: ";
        for ( unsigned int j = 0; j < toppings.size(); j++) {
            if (j != toppings.size() - 1) {
                cout << toppings[i].get_name() << ", ";
            }
            else {
                cout << toppings[i].get_name() << endl;
            }
        }
    }
    for ( unsigned int i = 0; i < other.size(); i++ ) {
        cout << "\t" << other[i].get_name() << endl;
    }
    cout << "[1] Done?" << endl;
    cout << "[2] Back to Main Menu" << endl;
    do{
        try {
            cin >> select;
            done = valid.get_integer_input_variable_size(select, 2);

            if (done == 1) {
                vector <Order> orders = order_service.get_in_progress_orders_by_street(place.get_street());
                order_service.change_inPro_to_Done((int)orders.size(), place.get_street());
                done = 2;
            }
        }catch (InvalidMenuNumberException e) {
            cout << e.get_message();
        }
    }while(done != 2);
}
