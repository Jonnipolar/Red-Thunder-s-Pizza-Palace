#include "Order.h"

Order::Order()
{
    this->name = "No Order";
    Pizza pizza;
    this->pizzas.push_back(pizza);
    set_time();

}
Order::Order(string name, vector <Pizza> pizzas, string OrderTime) {
    this->name = name;
    this->pizzas = pizzas;
    this->OrderTime = OrderTime;
}
string Order::get_name() {
    return this->name;
}
vector <Pizza> Order::get_pizzas() {
    return this->pizzas;
}
string Order::get_time() {
    return this->OrderTime;
}
void Order::set_time() {
    time_t timestamp = time(0);
    char time_buffer[80];
    strftime(time_buffer, sizeof(time_buffer), "%d/%m/%Y %H:%M ", localtime(&timestamp));

    string TimeOrder(time_buffer);
    this->OrderTime = TimeOrder;
}
int Order::get_totalAmount() {
    return this->TotalAmount;
}
string Order::get_typeOfDelivery() {
    return this->TypeOfDelivery;
}
string Order::get_HasBeenPaidFor() {
    return this->HasBeenPaidFor;
}
string Order::get_OrderLocation() {
    return this->OrderLocation;
}
string Order::get_Comment() {
    return this->Comment;
}
ostream& operator <<(ostream& out, Order& order) {
    //out << order.name << ":" <<
    return out;
}
istream& operator >>(istream& in, Order& order) {

    return in;
}
Order::~Order()
{
    //dtor
}
