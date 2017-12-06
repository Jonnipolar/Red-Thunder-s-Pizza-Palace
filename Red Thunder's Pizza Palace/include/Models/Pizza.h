#ifndef PIZZA_H
#define PIZZA_H
#include "Toppings.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Pizza
{
    public:
        Pizza();
        ~Pizza();
        friend ostream& operator <<(ostream& out, const Pizza& pizza);
        friend istream& operator >>(istream& in, Pizza& pizza);

    private:
        string name;
        int price;
        vector<Toppings> toppings;
        string bottom;
        string pizzaSize;

};

#endif // PIZZA_H
