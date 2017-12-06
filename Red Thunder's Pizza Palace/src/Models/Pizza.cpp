#include "Pizza.h"
Pizza::Pizza()
{
    //ctor
}
ostream& operator <<(ostream& out, const Pizza& pizza) {
    out << pizza.name << ":" << pizza.price << ":";
    for (unsigned int i = 0; i < pizza.toppings.size(); i++ ) {
        if (i != pizza.toppings.size() - 1) {
            out << pizza.toppings[i] << ",";
        }
        else {
            out << pizza.toppings[i];
        }
    }
    out << pizza.bottom << ":" << pizza.pizzaSize << endl;
    return out;
}
istream& operator >>(istream& in, Pizza& pizza) {
    cout << "";

    return in;
}
Pizza::~Pizza()
{
    //dtor
}
