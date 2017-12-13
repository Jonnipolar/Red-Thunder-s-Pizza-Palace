#include "BakeryUI.h"

BakeryUI::BakeryUI()
{
    //ctor
}
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
    if (placeSel > 0 && placeSel < pizza_places.size()) {

    }

}
BakeryUI::~BakeryUI()
{
    //dtor
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
