#include "MakeToppingsList.h"
#include "ToppingsRepository.h"

MakeToppingsList::MakeToppingsList() {
    this->name = "";        // makes name empty string
    this->price = 0;        // set price at 0
    this->type = '\0';
}

MakeToppingsList::MakeToppingsList(string name, int price, char type) {

    this->name = name;      // set name
    this->price = price;    // set price
    this->type = type;
}
string MakeToppingsList::get_name() {
    return this->name;
}
int MakeToppingsList::get_price() {
    return this->price;
}
void MakeToppingsList::save_topping_list(MakeToppingsList toppings) {
    ToppingsRepository repo;                        // create class to write to document
    repo.store_toppings(toppings);                    // send information to write to document
}

ostream& operator << (ostream& out, MakeToppingsList& topping) {

    out << topping.name << ":" << topping.price << ":" << topping.type << endl;                           // prints to file what is typed
    return out;
}
