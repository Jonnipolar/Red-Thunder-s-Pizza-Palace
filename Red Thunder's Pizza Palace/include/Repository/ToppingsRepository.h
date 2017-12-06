#ifndef TOPPINGSREPOSITORY_H
#define TOPPINGSREPOSITORY_H
#include <fstream>
#include "Toppings.h"
#include <iostream>

using namespace std;

class ToppingsRepository
{
    public:
        /// function to write to document
        void store_toppings(const Toppings& topping);
    private:
};

#endif // TOPPINGSREPOSITORY_H
