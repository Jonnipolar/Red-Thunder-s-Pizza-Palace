#include "MakeToppingsList.h"


void MakeToppingsList::save_topping_list(const Toppings& toppings) {

    repo.store_toppings(toppings);                    // send information to write to document
}

