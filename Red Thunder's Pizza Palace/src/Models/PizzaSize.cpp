#include "PizzaSize.h"

PizzaSize::PizzaSize(string size, int price){
    this->size = size;
    this->price = price;
}
ostream& operator << (ostream& out, const PizzaSize& psize) {
    out << psize.size << ":" << psize.price << endl;
    return out;
}
