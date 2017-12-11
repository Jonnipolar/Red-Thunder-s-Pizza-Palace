#include "PizzaSizeService.h"

void PizzaSizeService::save_pizza_size(const PizzaSize& pizza_size) {
    pizza_sizes_repo.store_pizza_size(pizza_size);
}
vector <PizzaSize> PizzaSizeService::Get_Pizza_Sizes() {
    vector <PizzaSize> pizza_size = pizza_sizes_repo.get_pizza_size();
    return pizza_size;
}
