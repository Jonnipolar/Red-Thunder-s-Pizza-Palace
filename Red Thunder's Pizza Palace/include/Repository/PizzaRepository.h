#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include <fstream>
#include "Pizza.h"
#include <iostream>
#include <vector>

using namespace std;
class PizzaRepository
{
    public:
        PizzaRepository();
        void store_pizza(const Pizza& pizza);
        ~PizzaRepository();

    private:
};

#endif // PIZZAREPOSITORY_H
