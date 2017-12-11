#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H
#include "PizzaRepository.h"
#include <iostream>
using namespace std;
class PizzaService
{
    public:
        PizzaService();
        void save_pizza(const Pizza& pizza);
        vector <Pizza> get_pizzas();
        ~PizzaService();

    private:
        PizzaRepository pizzaRepo;
};

#endif // PIZZASERVICE_H
