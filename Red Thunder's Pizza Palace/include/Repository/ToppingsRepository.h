#ifndef TOPPINGSREPOSITORY_H
#define TOPPINGSREPOSITORY_H
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Toppings.h"
#include "InvalidFileNotOpenException.h"

using namespace std;

class ToppingsRepository
{
    public:
        ToppingsRepository();
        /// function to write to document
        void store_toppings(vector <Toppings> topping);
        vector <Toppings> get_topping();
    private:
};

#endif // TOPPINGSREPOSITORY_H
