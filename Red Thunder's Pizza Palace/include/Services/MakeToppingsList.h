#ifndef MAKETOPPINGSLIST_H
#define MAKETOPPINGSLIST_H
#include <string>
#include <iostream>
#include "ToppingsRepository.h"

using namespace std;

class MakeToppingsList
{
    public:
        /// sends information to toppings repository
        void save_topping_list(const Toppings& toppings);
    private:
        ToppingsRepository repo;
};

#endif // MAKETOPPINGSLIST_H
