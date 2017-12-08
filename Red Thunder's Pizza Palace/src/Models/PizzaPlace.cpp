#include "PizzaPlace.h"

PizzaPlace::PizzaPlace() {
    this->street = "No Street";
    this->number = -1;

}
PizzaPlace::PizzaPlace(string street, int number) {
    this->street = street;
    this->number = number;
}
string PizzaPlace::get_street() {
    return this->street;
}
int PizzaPlace::get_number() {
    return this->number;
}
ostream& operator << (ostream& out, const PizzaPlace& pizza_place) {
    out << pizza_place.street << ":" << pizza_place.number << endl;
    return out;
}
