#include "OtherProducts.h"

OtherProducts::OtherProducts(string name, int price, int type){
    this->name = name;
    this->price = price;
    this->type = type;
}
string OtherProducts::get_name() {
    return this->name;
}
int OtherProducts::get_price() {
    return this->price;
}
int OtherProducts::get_type() {
    return this->type;
}
OtherProducts::~OtherProducts()
{
    //dtor
}
