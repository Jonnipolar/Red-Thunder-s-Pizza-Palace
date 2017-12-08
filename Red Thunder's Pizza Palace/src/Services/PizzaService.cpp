#include "PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}
void PizzaService::save_pizza(const Pizza& pizza) {
    pizzaRepo.store_pizza(pizza);
}
PizzaService::~PizzaService()
{
    //dtor
}
