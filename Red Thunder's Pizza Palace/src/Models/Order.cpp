#include "Order.h"

Order::Order()
{
    this->name = "No Order";
    Pizza pizza;
    this->pizzas.push_back(pizza);
    OtherProducts other_prod;
    this->otherProducts.push_back(other_prod);
    set_time();
    this->TotalAmount = 0;
    this->TypeOfDelivery = "No Delivery";
    this->HasBeenPaidFor = "No payment";
    this->OrderLocation = PizzaPlace();
    this->OrderStatus = "No Status";
    this->Comment = "No Comment";
}
Order::Order(string name, vector <Pizza> pizzas, vector <OtherProducts> other_prod, string OrderTime, int TotalAmount, string TypeOfDelivery, string HasBeenPaidFor, PizzaPlace OrderLocation, string OrderStatus, string Comment) {
    this->name = name;
    this->pizzas = pizzas;
    this->otherProducts = other_prod;
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
vector <OtherProducts> Order::get_other_prod() {
    return this->otherProducts;
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
PizzaPlace Order::get_OrderLocation() {
    return this->OrderLocation;
}
string Order::get_orderStatus() {
    return this->OrderStatus;
}
string Order::get_Comment() {
    return this->Comment;
}
void Order::set_HasBeenPaidFor(string paid) {
    this->HasBeenPaidFor = paid;
}
void Order::set_orderStatus(string status) {
    this->OrderStatus = status;
}
ostream& operator <<(ostream& out, const Order& order) {
    PizzaPlace place = order.OrderLocation;
    string delim = "|";
    out << order.name << delim;
    for ( unsigned int i = 0; i < order.pizzas.size(); i++ ) {
        Pizza pizza = order.pizzas[i];
        PizzaSize pizza_size = pizza.get_size();
        PizzaBottom bottom = pizza.get_bottom();
        if (i != order.pizzas.size() - 1) {
            out << pizza.get_name() << ";";
            out << pizza_size.get_size() << ";";
            out << bottom.get_type() << ";";
            vector <Toppings> toppings = pizza.get_toppings();
            for ( unsigned int i = 0; i < toppings.size(); i++ ) {
                Toppings topping = toppings[i];
                if (i != toppings.size() - 1) {
                    out << topping.get_name() << ",";
                }
                else {
                    out << topping.get_name() << ";";
                }
            }
        }
        else {
            out << pizza.get_name() << ";";
            out << pizza_size.get_size() << ";";
            out << bottom.get_type() << ";";
            vector <Toppings> toppings = pizza.get_toppings();
            for ( unsigned int i = 0; i < toppings.size(); i++ ) {
                Toppings topping = toppings[i];
                if (i != toppings.size() - 1) {
                    out << topping.get_name() << ",";
                }
                else {
                    out << topping.get_name() << delim;
                }
            }
        }
    }
    for ( unsigned int i = 0; i < order.otherProducts.size(); i++ ) {
        OtherProducts other_prod = order.otherProducts[i];
        if (i != order.otherProducts.size() - 1) {
            out << other_prod.get_name() << ";";
        }
        else {
            out << other_prod.get_name() << delim;
        }
    }
    out << order.OrderTime << delim << order.TotalAmount << delim << order.TypeOfDelivery
        << delim << order.HasBeenPaidFor << delim << place.get_street() << delim
        << order.OrderStatus << delim << order.Comment << endl;
    return out;
}
istream& operator >>(istream& in, Order& order) {

    return in;
}
Order::~Order()
{
    //dtor
}
