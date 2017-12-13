#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Order.h"

using namespace std;
class OrderRepository
{
    public:
        OrderRepository();
        void store_order(vector <Order> order);
        vector <Order> get_order();
        ~OrderRepository();

    private:
};

#endif // ORDERREPOSITORY_H
