#include "PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}
void PizzaService::save_pizza(const Pizza& pizza) {
    pizzaRepo.store_pizza(pizza);
}
vector <Pizza> PizzaService::get_pizzas() {
    vector <Pizza> pizzas = pizzaRepo.get_pizza();
    return pizzas;
}
PizzaService::~PizzaService()
{
    //dtor
}
