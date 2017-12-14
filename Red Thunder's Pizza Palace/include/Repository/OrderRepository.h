#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Order.h"
#include "InvalidFileNotOpenException.h"

using namespace std;
class OrderRepository
{
    public:
        OrderRepository();
        void store_order(vector <Order> order, int sel) throw (InvalidFileNotOpenException);
        vector <Order> get_order(int sel) throw (InvalidFileNotOpenException);
        ~OrderRepository();

    private:
};

#endif // ORDERREPOSITORY_H
