#ifndef BAKERYUI_H
#define BAKERYUI_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "OrderServices.h"
#include "PizzaPlaceService.h"
#include "InvalidMenuNumberException.h"
#include "InvalidFileNotOpenException.h"
#include <string>
#include <sstream>
using namespace std;
class BakeryUI
{
    public:
        void StartUI();
        unsigned int get_integer_input_variable_size(unsigned int size) throw (InvalidMenuNumberException);
        void UI_sub(string street);
        void UI_processing(string street) throw (InvalidFileNotOpenException);
        void UI_add_to_progress(vector <Order> by_street);
    private:
        PizzaPlaceService pizza_service;
        OrderServices order_service;
};

#endif // BAKERYUI_H
