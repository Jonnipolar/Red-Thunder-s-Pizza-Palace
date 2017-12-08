#ifndef PIZZASIZEREPOSITORY_H
#define PIZZASIZEREPOSITORY_H
#include <iostream>
#include <fstream>
#include "PizzaSize.h"
#include <vector>
#include <stdlib.h>

using namespace std;

class PizzaSizeRepository
{
    public:
        void store_pizza_size(const PizzaSize& pizza_size);
        vector <PizzaSize> get_pizza_size();
    private:
};

#endif // PIZZASIZEREPOSITORY_H
