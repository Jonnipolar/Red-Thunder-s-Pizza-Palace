#ifndef ORDER_UI_H
#define ORDER_UI_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Pizza.h"
#include "PizzaPlace.h"
#include "PizzaService.h"
#include "MakeToppingsList.h"
#include "PizzaSizeService.h"
#include "MakePizzaBottomList.h"
#include "PizzaPlaceService.h"

using namespace std;
class Order_UI
{
    public:
        Order_UI();
        ///Start The UI
        void UI_Start();
        void UI_Add_Order();
        ///Sub UI to UImake_pizza to add topping to pizza
        vector <Toppings> SubUI_add_topping();
        ~Order_UI();

    private:
        MakeToppingsList toppings_list;
        PizzaSizeService pizza_size;
        MakePizzaBottomList pizza_bottom;
        PizzaPlaceService pizza_places;
        PizzaService pizza_service;
};

#endif // ORDER_UI_H
