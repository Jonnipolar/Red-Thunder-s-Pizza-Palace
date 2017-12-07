#ifndef MAKETOPPINGSLIST_H
#define MAKETOPPINGSLIST_H
#include <string>
#include <iostream>
#include <vector>
#include "ToppingsRepository.h"

using namespace std;

class MakeToppingsList
{
    public:
        /// sends information to toppings repository
        void save_topping_list(const Toppings& toppings);
        vector <Toppings> get_topping_list();
        vector <Toppings> get_cheese_list();
        vector <Toppings> get_vegetable_list();
        vector <Toppings> get_meat_list();
    private:
        ToppingsRepository repo;
};

#endif // MAKETOPPINGSLIST_H
