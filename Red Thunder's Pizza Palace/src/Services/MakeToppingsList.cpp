#include "MakeToppingsList.h"

void MakeToppingsList::save_topping_list(string name, int price, int type) {
    bool check = true;
    vector <Toppings> toppings = get_topping_list();
    for(unsigned int i = 0; i < name.size(); i++) {
        name[i] = tolower(name[i]);
    }
    Toppings topping(name, price, type);
    for (unsigned int i = 0; i < toppings.size(); i++) {
        if(toppings[i].get_name() == name) {
            toppings[i] = topping;
            check = false;
        }
    }
    if (check) {
        toppings.push_back(topping);
    }
    repo.store_toppings(toppings);                                    // send information to write to document
}
vector <Toppings> MakeToppingsList::get_topping_list() {
    vector <Toppings> toppings = repo.get_topping();
    return toppings;
}
vector <Toppings> MakeToppingsList::get_cheese_list() {
    vector <Toppings> toppings = repo.get_topping();
    vector <Toppings> cheeseTopp;
    for (unsigned int i = 0; i < toppings.size(); i++) {
        if (toppings[i].get_type() == 3) {
            cheeseTopp.push_back(toppings[i]);
        }
    }
    return cheeseTopp;
}
vector <Toppings> MakeToppingsList::get_vegetable_list() {
    vector <Toppings> toppings = repo.get_topping();
    vector <Toppings> vegetableTopp;
    for (unsigned int i = 0; i < toppings.size(); i++) {
        if (toppings[i].get_type() == 2) {
            vegetableTopp.push_back(toppings[i]);
        }
    }
    return vegetableTopp;
}
vector <Toppings> MakeToppingsList::get_meat_list() {
    vector <Toppings> toppings = repo.get_topping();
    vector <Toppings> meatTopp;
    for (unsigned int i = 0; i < toppings.size(); i++) {
        if (toppings[i].get_type() == 1) {
            meatTopp.push_back(toppings[i]);
        }
    }
    return meatTopp;
}
