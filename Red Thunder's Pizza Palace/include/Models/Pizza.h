#ifndef PIZZA_H
#define PIZZA_H
#include "Toppings.h"
#include <iostream>
#include <string>
#include <vector>
#include "PizzaSize.h"
#include "PizzaBottom.h"
#include "PizzaSize.h"
#include "PizzaBottom.h"
using namespace std;
class Pizza
{
    public:
        Pizza();
        Pizza(string name, int price, vector <Toppings> toppings, PizzaBottom bottom, PizzaSize pizzasize);
        ~Pizza();
        string get_name();
        int get_price();
        vector <Toppings> get_toppings();
        PizzaBottom get_bottom();
        PizzaSize get_size();
        friend ostream& operator <<(ostream& out, const Pizza& pizza);
        friend istream& operator >>(istream& in, Pizza& pizza);

    private:
        string name;
        int price;
        vector<Toppings> toppings;
        PizzaBottom bottom;
        PizzaSize pizzaSize;

};

#endif // PIZZA_H
