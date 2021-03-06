#include "Pizza.h"

Pizza::Pizza() {
    this->name = "No pizza";
    this->price = 0;
    Toppings topping;
    this->toppings.push_back(topping);
    this->bottom = PizzaBottom();
    this->pizzaSize = PizzaSize();

}
Pizza::Pizza(string name, int price, vector <Toppings> toppings, PizzaBottom bottom, PizzaSize pizzasize)
{
    this->name = name;
    this->price = price;
    this->toppings = toppings;
    this->bottom = bottom;
    this->pizzaSize = pizzasize;
}
string Pizza::get_name() {
    return this->name;
}
int Pizza::get_price() {
    return this->price;
}
vector <Toppings> Pizza::get_toppings() {
    return this->toppings;
}
PizzaBottom Pizza::get_bottom() {
    return this->bottom;
}
PizzaSize Pizza::get_size() {
    return this->pizzaSize;
}
ostream& operator <<(ostream& out, const Pizza& pizza) {
    out << pizza.name << ":" << pizza.price << ":";
    for (unsigned int i = 0; i < pizza.toppings.size(); i++ ) {
        Toppings topping = pizza.toppings[i];
        if (i != pizza.toppings.size() - 1) {
            out << topping.get_name() << ",";
        }
        else {
            out << topping.get_name() << endl;
        }
    }
    return out;
}
istream& operator >>(istream& in, Pizza& pizza) {
    cout << "";

    return in;
}
Pizza::~Pizza()
{
    //dtor
}
