#include "PizzaPlaceService.h"


void PizzaPlaceService::save_pizza_place(string street, int number) {
    bool check = true;
    vector <PizzaPlace> pizza_place_list = get_pizza_place();
    for(unsigned int i = 0; i < street.size(); i++) {
        street[i] = tolower(street[i]);
    }
    PizzaPlace pizza_place(street, number);
    for(unsigned int i = 0; i < pizza_place_list.size(); i++) {
        if(pizza_place_list[i].get_street() == street) {
            pizza_place_list[i] = pizza_place;
            check = false;
        }
    }
    if(check) {
        pizza_place_list.push_back(pizza_place);
    }
    pizza_places.store_pizza_places(pizza_place_list);
}
vector <PizzaPlace> PizzaPlaceService::get_pizza_place() {
    vector <PizzaPlace> pizzaPlaces = pizza_places.get_pizza_place();
    return pizzaPlaces;
}
