#ifndef PIZZABOTTOMREPOSITORY_H
#define PIZZABOTTOMREPOSITORY_H
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "PizzaBottom.h"
#include "InvalidFileNotOpenException.h"

using namespace std;

class PizzaBottomRepository
{
    public:
        void store_pizza_bottom(vector <PizzaBottom> pizza_bottom) throw (InvalidFileNotOpenException);
        vector <PizzaBottom> get_pizza_bottom() throw (InvalidFileNotOpenException);
    private:
};

#endif // PIZZABOTTOMREPOSITORY_H
