#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <vector>
#include "Pizza.h"
#include <ctime>

using namespace std;
class Order
{
    public:
        Order();
        Order(string name, vector <Pizza> pizzas, string OrderTime);
        string get_name();
        vector <Pizza> get_pizzas();
        string get_time();
        void set_time();
        ~Order();

    private:
        string name;
        vector <Pizza> pizzas;
        string OrderTime;
};

#endif // ORDER_H
