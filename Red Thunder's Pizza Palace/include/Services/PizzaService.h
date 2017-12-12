#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H
#include <iostream>
#include "PizzaRepository.h"
using namespace std;
class PizzaService
{
    public:
        PizzaService();
        void save_pizza(string name, int price, vector <Toppings> toppings, PizzaBottom bottom, PizzaSize pizza_size);
        vector <Pizza> get_pizzas();
        ~PizzaService();

    private:
        PizzaRepository pizzaRepo;
};

#endif // PIZZASERVICE_H
