#include "Toppings.h"

Toppings::Toppings() {
    this->name = "No Topping";
    this->price = 0;
    this->type = 0;
}

Toppings::Toppings(string name, int price, int type) {

    this->name = name;      // set name
    this->price = price;    // set price
    this->type = type;
}
string Toppings::get_name() {
    return this->name;
}
int Toppings::get_price() {
    return this->price;
}
int Toppings::get_type() {
    return this->type;
}
ostream& operator << (ostream& out,const Toppings& topping) {

    out << topping.name << ":" << topping.price << ":" << topping.type << endl;                           // prints to file what is typed
    return out;
}
