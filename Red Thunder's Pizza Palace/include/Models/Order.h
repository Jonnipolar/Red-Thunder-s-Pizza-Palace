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
        int get_totalAmount();
        string get_typeOfDelivery();
        string get_HasBeenPaidFor();
        string get_OrderLocation();
        string get_Comment();
        void set_time();
        friend ostream& operator << (ostream& out, Order& order);
        friend istream& operator >>(istream& in, Order& order);
        ~Order();

    private:
        string name;
        vector <Pizza> pizzas;
        string OrderTime;
        int TotalAmount;
        string TypeOfDelivery;
        string HasBeenPaidFor;
        string OrderLocation;
        string Comment;
};

#endif // ORDER_H
