#include "Order.h"

Order::Order()
{
    //ctor
}
string Order::get_name() {
    return this->name;
}
vector <Pizza> Order::get_pizzas() {
    return this->pizzas;
}
Order::~Order()
{
    //dtor
}
