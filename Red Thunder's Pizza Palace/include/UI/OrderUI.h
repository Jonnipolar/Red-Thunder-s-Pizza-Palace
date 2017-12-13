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
#include "OtherProductsService.h"
#include <sstream>
#include "InvalidMenuNumberException.h"
#include "InvalidFileNotOpenException.h"
using namespace std;
class Order_UI
{
    public:
        Order_UI();
        ///Start The UI
        void UI_Start();
        void UI_Add_Order();
        Pizza add_custom_pizza();
        Pizza add_menu_pizza();
        Pizza UI_Add_Order_Pizza();
        ///Sub UI to UImake_pizza to add topping to pizza
        vector <Toppings> SubUI_add_topping();
        PizzaBottom UI_Get_Bottom();
        PizzaSize UI_Get_Size();
        int get_price_of_toppings(vector <Toppings> toppings);
        Pizza get_pizza_menus();
        OtherProducts add_other_prduct();
        int get_price_of_pizzas(vector <Pizza> pizzas);
        string get_time();
        string get_type_of_delivery();
        string get_has_been_paid_for();
        PizzaPlace get_order_location()throw (InvalidMenuNumberException);
        string get_order_status() throw (InvalidMenuNumberException);
        string get_comment();
        ~Order_UI();

        unsigned int get_integer_input_variable_size(unsigned int size) throw (InvalidMenuNumberException);
        ///skilar integer eftir staerd vectors setur inn (vector.size())
//        int get_integer_input2() throw (InvalidMenuNumberException);
//        int get_integer_input3() throw (InvalidMenuNumberException);
//        int get_integer_input4() throw (InvalidMenuNumberException);

    private:
        MakeToppingsList toppings_list;
        PizzaSizeService pizza_size;
        MakePizzaBottomList pizza_bottom;
        PizzaPlaceService pizza_places;
        PizzaService pizza_service;
        OrderServices order_service;
        OtherProductsService other_prod_service;
};

#endif // ORDER_UI_H
