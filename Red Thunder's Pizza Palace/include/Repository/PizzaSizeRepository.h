#ifndef PIZZASIZEREPOSITORY_H
#define PIZZASIZEREPOSITORY_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "PizzaSize.h"
#include "InvalidFileNotOpenException.h"

using namespace std;

class PizzaSizeRepository
{
    public:
        void store_pizza_size(vector <PizzaSize> pizza_size) throw (InvalidFileNotOpenException);
        vector <PizzaSize> get_pizza_size()throw (InvalidFileNotOpenException);
};

#endif // PIZZASIZEREPOSITORY_H
