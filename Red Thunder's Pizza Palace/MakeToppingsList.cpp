#include "MakeToppingsList.h"
#include "ToppingsRepository.h"

MakeToppingsList::MakeToppingsList() {
    this->name = "";        // makes name empty string
    this->price = 0;        // set price at 0
}

MakeToppingsList::MakeToppingsList(string name, int price) {

        this->name = name;      // set name
        this->price = price;    // set price

}

istream& operator >> (istream& in, MakeToppingsList toppings)
{
    cout << "Please enter new toppings: " << endl;
    cout << "Name: ";
    cin >> ws;                                         // cin >> ws needs to be done before
    getline(in, toppings.name);                         // set name
    cout << "price: ";
    cin >> toppings.price;                              // set price
    ToppingsRepository repo;                            // create class to write to document
    repo.store_toppings(toppings);                      // send information to write to document

    return in;
}
ostream& operator << (ostream& out, const MakeToppingsList& topping) {
    out << topping.name << " " << topping.price;                            // prints to screen what is typed
    return out;
}
