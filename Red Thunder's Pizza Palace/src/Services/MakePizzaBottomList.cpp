#include "MakePizzaBottomList.h"

void MakePizzaBottomList::save_pizza_bottom(string name, int price) {
    bool check = true;
    vector <PizzaBottom> pizza_bottoms = Get_Pizza_Bottom();
    for(unsigned int i = 0; i < name.size(); i++) {
        name[i] = tolower(name[i]);
    }
    PizzaBottom pizza_bottom(name, price);
    for(unsigned int i = 0; i < pizza_bottoms.size(); i++) {
        if(pizza_bottoms[i].get_type() == name) {
            pizza_bottoms[i] = pizza_bottom;
            check = false;
        }
    }
    if(check) {
        pizza_bottoms.push_back(pizza_bottom);
    }
    pizza_bottom_repo.store_pizza_bottom(pizza_bottoms);
}
vector <PizzaBottom> MakePizzaBottomList::Get_Pizza_Bottom() {
    vector <PizzaBottom> PizzaBottomList = pizza_bottom_repo.get_pizza_bottom();
    return PizzaBottomList;
}
