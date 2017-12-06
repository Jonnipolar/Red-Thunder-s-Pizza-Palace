#include "PizzaBottom.h"

PizzaBottom::PizzaBottom(string size, int price) {
    this->size = size;
    this->price = price;
}
ostream& operator << (ostream& out, const PizzaBottom& bottom) {
    out << bottom.size << ":" << bottom.price << endl;
    return out;
}
