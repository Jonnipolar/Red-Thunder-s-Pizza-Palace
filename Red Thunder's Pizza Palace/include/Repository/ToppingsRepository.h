#ifndef TOPPINGSREPOSITORY_H
#define TOPPINGSREPOSITORY_H
#include <fstream>
#include "MakeToppingsList.h"
#include <string>
#include <iostream>

using namespace std;

class ToppingsRepository
{
    public:
        ToppingsRepository();
        /// function to write to document
        void store_toppings(MakeToppingsList topping);
    private:
};

#endif // TOPPINGSREPOSITORY_H
