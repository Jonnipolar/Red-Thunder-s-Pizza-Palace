#ifndef LEGACYREPO_H
#define LEGACYREPO_H
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Order.h"
#include "InvalidFileNotOpenException.h"
using namespace std;

class LegacyRepo
{
    public:
        void store_order(Order& order) throw (InvalidFileNotOpenException);
        vector <Order> get_order()  throw (InvalidFileNotOpenException);
    private:
};

#endif // LEGACYREPO_H
