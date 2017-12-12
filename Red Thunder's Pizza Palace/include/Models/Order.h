#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <vector>
#include <ctime>
#include "Pizza.h"
#include "OtherProducts.h"
#include "PizzaPlace.h"

using namespace std;
class Order
{
    public:
        Order();
        Order(string name, vector <Pizza> pizzas, vector <OtherProducts> other_prod, string OrderTime, int TotalAmount, string TypeOfDelivery, string HasBeenPaidFor, PizzaPlace OrderLocation, string OrderStatus, string Comment);
        string get_name();
        vector <Pizza> get_pizzas();
        vector <OtherProducts> get_other_prod();
        string get_time();
        int get_totalAmount();
        string get_typeOfDelivery();
        string get_HasBeenPaidFor();
        PizzaPlace get_OrderLocation();
        string get_orderStatus();
        string get_Comment();
        void set_time();
        friend ostream& operator << (ostream& out, const Order& order);
        friend istream& operator >>(istream& in, Order& order);
        ~Order();

    private:
        string name;
        vector <Pizza> pizzas;
        vector <OtherProducts> otherProducts;
        string OrderTime;
        int TotalAmount;
        string TypeOfDelivery;
        string HasBeenPaidFor;
        PizzaPlace OrderLocation;
        string OrderStatus;
        string Comment;
};

#endif // ORDER_H
