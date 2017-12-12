#include "BakeryUI.h"

BakeryUI::BakeryUI()
{
    //ctor
}
void BakeryUI::StartUI() {
    vector <PizzaPlace> pizza_places = pizza_service.get_pizza_place();
    int placeSel = -1;
    system("CLS");
    cout << "Welcome To the Bakery!" << endl;
    cout << "Please choose the address of the place where you will be working at" << endl;
    for ( unsigned int i = 0; i < pizza_places.size(); i++ ) {
        cout << "\t[" << i+1 << "] " << pizza_places[i].get_street() << endl;
    }
    cout << "\n";
    cin >> placeSel;
    if (placeSel > 0 && placeSel < (int)pizza_places.size()) {

    }

}
BakeryUI::~BakeryUI()
{
    //dtor
}
