#include "BakeryUI.h"

BakeryUI::BakeryUI()
{
    //ctor
}
void BakeryUI::StartUI() {/// I MESSED WITH UR CODE (bara sm� samt)
    vector <PizzaPlace> pizza_places = pizza_service.get_pizza_place();
    //unsigned int placeSel = -1; fjarl�gi �etta decleration og set �a� fyrir ne�an � place-sel svo �a� validate-i menu choice �egar �a� b�r til.
    system("CLS");
    cout << "Welcome To the Bakery!" << endl;
    cout << "Please choose the address of the place where you will be working at" << endl;
    for ( unsigned int i = 0; i < pizza_places.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizza_places[i].get_street() << endl;
    }
    cout << "\n";

    /// !!! nota frekar unsigned int �� �arftu ekki a� har�k��a int inn � size.
    /// �� er l�ka h�gt a� nota inputfalli� sem �g kalla � h�r.
    /// einnig eru samb�rileg finctions fyrir price og strings � manager subUI
    /// sem er h�gt a� kopera e�a talar vi� mig og �g l�t � �etta l�ka.

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
