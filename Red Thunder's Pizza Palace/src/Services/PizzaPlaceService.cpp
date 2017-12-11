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
vector <PizzaPlace> PizzaPlaceService::get_pizza_place() {
    vector <PizzaPlace> pizzaPlaces = pizza_places.get_pizza_place();
    return pizzaPlaces;
}
