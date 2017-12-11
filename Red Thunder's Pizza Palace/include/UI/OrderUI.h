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
#include "OrderServices.h"

using namespace std;
class Order_UI
{
    public:
        Order_UI();
        ///Start The UI
        void UI_Start();
        void UI_Add_Order();
        Pizza UI_Add_Order_Pizza();
        ///Sub UI to UImake_pizza to add topping to pizza
        vector <Toppings> SubUI_add_topping();
        PizzaBottom UI_Get_Bottom();
        PizzaSize UI_Get_Size();
        int get_price_of_toppings(vector <Toppings> toppings);
        Pizza get_pizza_menus();
        ~Order_UI();

    private:
        MakeToppingsList toppings_list;
        PizzaSizeService pizza_size;
        MakePizzaBottomList pizza_bottom;
        PizzaPlaceService pizza_places;
        PizzaService pizza_service;
        OrderServices order_service;
};

#endif // ORDER_UI_H
