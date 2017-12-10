#include "PizzaPlaceService.h"

PizzaPlaceService::PizzaPlaceService()
{
    //ctor
}

PizzaPlaceService::~PizzaPlaceService()
{
    //dtor
}
void PizzaPlaceService::save_pizza_place(const PizzaPlace& pizza_place) {
    pizza_places.store_pizza_places(pizza_place);
}
