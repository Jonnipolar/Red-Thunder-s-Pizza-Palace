#include "PizzaSize.h"

PizzaSize::PizzaSize() {

}

PizzaSize::PizzaSize(string _size, int price){
    this->_size = _size;
    this->price = price;
}
string PizzaSize::get_size() {
    return this->_size;
}
int PizzaSize::get_price() {
    return this->price;
}
ostream& operator << (ostream& out, const PizzaSize& psize) {
    out << psize._size << ":" << psize.price << endl;
    return out;
}
