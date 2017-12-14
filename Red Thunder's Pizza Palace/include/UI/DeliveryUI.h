#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "OrderServices.h"
#include "PizzaPlaceService.h"
#include "InvalidMenuNumberException.h"
#include <string>
#include <sstream>
using namespace std;

class DeliveryUI
{
    public:
        DeliveryUI();
        virtual ~DeliveryUI();
        void StartUI();
        unsigned int get_integer_input_variable_size(unsigned int size) throw (InvalidMenuNumberException);
        void UI_sub(string street);
        void list_all_orders(string street);
    private:
        PizzaPlaceService pizza_service;
        OrderServices order_service;
};

#endif // DELIVERYUI_H
