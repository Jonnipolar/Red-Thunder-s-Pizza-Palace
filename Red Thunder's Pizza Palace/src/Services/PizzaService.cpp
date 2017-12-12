#include "PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}
void PizzaService::save_pizza(string name, int price, vector <Toppings> toppings, PizzaBottom bottom, PizzaSize pizza_size) {
    bool check = true;
    vector <Pizza> pizzas = get_pizzas();
    for(unsigned int i = 0; i < name.size(); i++) {
        name[i] = tolower(name[i]);
    }
    Pizza pizza(name,price,toppings,bottom,pizza_size);
    for(unsigned int i = 0; i < pizzas.size(); i++) {
        if(pizzas[i].get_name() == name) {
            pizzas[i] = pizza;
            check = false;
        }
    }
    if (check) {
        pizzas.push_back(pizza);
    }
    pizzaRepo.store_pizza(pizzas);
}
vector <Pizza> PizzaService::get_pizzas() {
    vector <Pizza> pizzas = pizzaRepo.get_pizza();
    return pizzas;
}
PizzaService::~PizzaService()
{
    //dtor
}
