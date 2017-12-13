#ifndef BAKERYUI_H
#define BAKERYUI_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "OrderServices.h"
#include "PizzaPlaceService.h"
#include "InvalidMenuNumberException.h"
#include <string>
#include <sstream>
using namespace std;
class BakeryUI
{
    public:
        BakeryUI();
        ~BakeryUI();
        void StartUI();
        unsigned int get_integer_input_variable_size(unsigned int size) throw (InvalidMenuNumberException);

    private:
        PizzaPlaceService pizza_service;
};

#endif // BAKERYUI_H
