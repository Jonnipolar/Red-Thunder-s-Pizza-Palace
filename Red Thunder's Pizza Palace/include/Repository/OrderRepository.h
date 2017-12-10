#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include "Order.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class OrderRepository
{
    public:
        OrderRepository();
        void store_order(const Order& order);
        ~OrderRepository();

    private:
};

#endif // ORDERREPOSITORY_H
