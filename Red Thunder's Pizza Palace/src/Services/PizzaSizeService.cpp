#include "PizzaSizeService.h"

void PizzaSizeService::save_pizza_size(string name, int price) {
    bool check = true;
    vector <PizzaSize> pizza_sizes = Get_Pizza_Sizes();
    for(unsigned int i = 0; i < name.size(); i++) {
        name[i] = tolower(name[i]);
    }
    PizzaSize pizza_size(name, price);
    for(unsigned int i = 0; i < pizza_sizes.size(); i++) {
        if(pizza_sizes[i].get_size() == name) {
            pizza_sizes[i] = pizza_size;
            check = false;
        }
    }
    if(check) {
        pizza_sizes.push_back(pizza_size);
    }
    pizza_sizes_repo.store_pizza_size(pizza_sizes );
}
vector <PizzaSize> PizzaSizeService::Get_Pizza_Sizes() {
    vector <PizzaSize> pizza_size = pizza_sizes_repo.get_pizza_size();
    return pizza_size;
}
