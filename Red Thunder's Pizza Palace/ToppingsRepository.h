#ifndef TOPPINGSREPOSITORY_H
#define TOPPINGSREPOSITORY_H
#include <fstream>
#include "MakeToppingsList.h"

using namespace std;

class ToppingsRepository
{
    public:
        /// function to write to document
        void store_toppings(MakeToppingsList topping);
    private:
};

#endif // TOPPINGSREPOSITORY_H
