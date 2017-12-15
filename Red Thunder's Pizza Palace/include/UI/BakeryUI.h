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
        ///Start the UI select while
        void StartUI();
        ///UI sub for start ui
        void UI_sub(string street) throw (InvalidMenuNumberException);
        /// ui sub sub for processing orders
        void UI_processing(string street) throw (InvalidFileNotOpenException, InvalidMenuNumberException);
        /// ui  sub sub for in progress orders
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
