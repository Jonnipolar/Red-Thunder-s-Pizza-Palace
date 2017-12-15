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
#include <ValidationService.h>
#include "LegacyService.h"
using namespace std;

class DeliveryUI
{
    public:
        DeliveryUI();
        virtual ~DeliveryUI();
        /// Start UI
        void StartUI();
        /// sub UI for start
        void UI_sub(string street);
        /// work with all order list
        void list_all_orders(string street);
        /// work with done order list
        void list_done_orders(string street);
    private:
        PizzaPlaceService pizza_service;
        OrderServices order_service;
        LegacyService legacy_serv;
        ValidationService valid;
};

#endif // DELIVERYUI_H
