#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include <fstream>
#include "Pizza.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Toppings.h"
#include "PizzaBottom.h"
#include "PizzaSize.h"

using namespace std;
class PizzaRepository
{
    public:
        PizzaRepository();
        void store_pizza(const Pizza& pizza);
        vector <Pizza> get_pizza();
        ~PizzaRepository();

    private:
};

#endif // PIZZAREPOSITORY_H
