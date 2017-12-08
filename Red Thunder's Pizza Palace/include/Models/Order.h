#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <vector>
#include "Pizza.h"

using namespace std;
class Order
{
    public:
        Order();
        string get_name();
        vector <Pizza> get_pizzas();
        ~Order();

    private:
        string name;
        vector <Pizza> pizzas;

};

#endif // ORDER_H
