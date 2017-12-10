#include "Order.h"

Order::Order()
{
    this->name = "No Order";
    Pizza pizza;
    this->pizzas.push_back(pizza);
    set_time();

}
Order::Order(string name, vector <Pizza> pizzas, string OrderTime, int TotalAmount, string TypeOfDelivery, string HasBeenPaidFor, string OrderLocation, string OrderStatus, string Comment) {
    this->name = name;
    this->pizzas = pizzas;
    this->OrderTime = OrderTime;
    this->TotalAmount = TotalAmount;
    this->TypeOfDelivery = TypeOfDelivery;
    this->HasBeenPaidFor = HasBeenPaidFor;
    this->OrderLocation = OrderLocation;
    this->OrderStatus = OrderStatus;
    this->Comment = Comment;
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
string Order::get_orderStatus() {
    return this->OrderStatus;
}
string Order::get_Comment() {
    return this->Comment;
}
ostream& operator <<(ostream& out, const Order& order) {
    out << order.name << ":";
    for ( unsigned int i = 0; i < order.pizzas.size(); i++ ) {
        Pizza pizza = order.pizzas[i];
        if (i != order.pizzas.size() - 1) {
            out << pizza.get_name() << ";";
            vector <Toppings> toppings = pizza.get_toppings();
            for ( unsigned int i = 0; i < toppings.size(); i++ ) {
                Toppings topping = toppings[i];
                if (i != toppings.size() - 1) {
                    out << topping.get_name() << ";";
                }
                else {
                    out << topping.get_name() << ",";
                }
            }
        }
        else {
            out << pizza.get_name();
            vector <Toppings> toppings = pizza.get_toppings();
            for ( unsigned int i = 0; i < toppings.size(); i++ ) {
                Toppings topping = toppings[i];
                if (i != toppings.size() - 1) {
                    out << topping.get_name() << ";";
                }
                else {
                    out << topping.get_name() << ":";
                }
            }
        }
    }
    out << order.OrderTime << ":" << order.TotalAmount << ":" << order.TypeOfDelivery
        << ":" << order.HasBeenPaidFor << ":" << order.OrderLocation << ":"
        << order.OrderStatus << ":" << order.Comment << endl;
    return out;
}
istream& operator >>(istream& in, Order& order) {

    return in;
}
Order::~Order()
{
    //dtor
}
