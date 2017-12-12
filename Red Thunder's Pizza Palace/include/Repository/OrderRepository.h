#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include <vector>
#include <iostream>
#include <fstream>
#include "Order.h"

using namespace std;
class OrderRepository
{
    public:
        OrderRepository();
        void store_order(const Order& order);
        vector <Order> get_order();
        ~OrderRepository();

    private:
};

#endif // ORDERREPOSITORY_H
