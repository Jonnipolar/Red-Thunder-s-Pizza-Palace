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
        void store_order(vector <Order> order) throw (InvalidFileNotOpenException);
        vector <Order> get_order() throw (InvalidFileNotOpenException);
        ~OrderRepository();

    private:
};

#endif // ORDERREPOSITORY_H
