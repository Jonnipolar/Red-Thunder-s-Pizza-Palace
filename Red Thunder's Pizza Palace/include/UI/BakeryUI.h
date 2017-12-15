#ifndef BAKERYUI_H
#define BAKERYUI_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "OrderServices.h"
#include "PizzaPlaceService.h"
#include "InvalidMenuNumberException.h"
#include "InvalidFileNotOpenException.h"
#include "ValidationService.h"
#include <string>
#include <sstream>
using namespace std;
class BakeryUI
{
    public:
        void StartUI();
        void UI_sub(string street) throw (InvalidMenuNumberException);
        void UI_processing(string street) throw (InvalidFileNotOpenException, InvalidMenuNumberException);
        void UI_in_progress(string street) throw (InvalidFileNotOpenException, InvalidMenuNumberException);
        void UI_add_to_progress(vector <Order> by_street);
        void UI_add_to_done(vector <Order> by_street);
        void UI_change_to_in_progress(Order& order, int sel);
        void UI_change_to_done(Order& order, int sel);
    private:
        PizzaPlaceService pizza_service;
        OrderServices order_service;
        ValidationService valid;
};

#endif // BAKERYUI_H
