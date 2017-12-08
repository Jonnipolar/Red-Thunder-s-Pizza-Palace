#include "PizzaBottom.h"

PizzaBottom::PizzaBottom() {

}
PizzaBottom::PizzaBottom(string type, int price) {
    this->type = type;
    this->price = price;
}
string PizzaBottom::get_type() {
    return this->type;
}
int PizzaBottom::get_price() {
    return this->price;
}
ostream& operator << (ostream& out, const PizzaBottom& bottom) {
    out << bottom.type << ":" << bottom.price << endl;
    return out;
}
