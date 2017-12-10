#include "PizzaSizeService.h"

void PizzaSizeService::save_pizza_size(const PizzaSize& pizza_size) {
    pizza_sizes.store_pizza_size(pizza_size);
}
