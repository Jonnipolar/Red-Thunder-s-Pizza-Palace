#include "MakePizzaBottomList.h"

void MakePizzaBottomList::save_pizza_bottom(const PizzaBottom& pizza_bottom) {
    pizza_bottom_repo.store_pizza_bottom(pizza_bottom);
}
vector <PizzaBottom> MakePizzaBottomList::Get_Pizza_Bottom() {
    vector <PizzaBottom> PizzaBottomList = pizza_bottom_repo.get_pizza_bottom();
    return PizzaBottomList;
}
