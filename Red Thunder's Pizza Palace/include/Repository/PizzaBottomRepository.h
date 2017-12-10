#ifndef PIZZABOTTOMREPOSITORY_H
#define PIZZABOTTOMREPOSITORY_H
#include <fstream>
#include "PizzaBottom.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class PizzaBottomRepository
{
    public:
        void store_pizza_bottom(const PizzaBottom& pizza_bottom);
        vector <PizzaBottom> get_pizza_bottom();
    private:
};

#endif // PIZZABOTTOMREPOSITORY_H
