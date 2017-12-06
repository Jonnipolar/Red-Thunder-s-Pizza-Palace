#ifndef PIZZASIZEREPOSITORY_H
#define PIZZASIZEREPOSITORY_H
#include <iostream>
#include <fstream>
#include "PizzaSize.h"

using namespace std;

class PizzaSizeRepository
{
    public:
        void store_pizza_size(const PizzaSize& pizza_size);
    private:
};

#endif // PIZZASIZEREPOSITORY_H
