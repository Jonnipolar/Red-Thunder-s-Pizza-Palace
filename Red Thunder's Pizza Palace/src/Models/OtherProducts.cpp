#include "OtherProducts.h"


OtherProducts::OtherProducts() {
    this->name = "No Product";
    this->price = 0;
    this->type = 0;
}
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
ostream& operator << (ostream& out, const OtherProducts& other_product) {
    out << other_product.name << ":" << other_product.price << ":" << other_product.type << endl;
    return out;
}
OtherProducts::~OtherProducts()
{
    //dtor
}
