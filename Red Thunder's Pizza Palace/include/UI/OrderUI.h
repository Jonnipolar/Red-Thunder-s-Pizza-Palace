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
#include "InvalidNameException.h"
#include "ValidationService.h"
using namespace std;
class Order_UI
{
    public:
        Order_UI();
        ///Start The UI
        void UI_Start();
        /// create order UI
       void UI_Add_Order() throw (InvalidFileNotOpenException, InvalidMenuNumberException);
        /// add custom pizza to order
        Pizza add_custom_pizza();
        /// add pre made pizza to order
        Pizza add_menu_pizza();
        /// Sub UI to Add_Order to select pizzas
        Pizza UI_Add_Order_Pizza();
        ///Sub UI to UImake_pizza to add topping to pizza
        vector <Toppings> SubUI_add_topping();
        ///sub ui for custom and menu pizzas to select bottom type
        PizzaBottom UI_Get_Bottom();
        ///sub ui for custom and menu pizzas to select size
        PizzaSize UI_Get_Size();
        ///get total price for toppings per pizza
        int get_price_of_toppings(vector <Toppings> toppings);
        /// get pizzas from menu to select
        Pizza get_pizza_menus();
        /// add other products to order
        OtherProducts add_other_product();
        /// get total price for order
        int get_price_of_pizzas(vector <Pizza> pizzas);
        /// get time order is made
        string get_time();
        /// set type of delivery
        string get_type_of_delivery() throw (InvalidFileNotOpenException);
        /// set paid status
        string get_has_been_paid_for() throw (InvalidFileNotOpenException);
        /// set location for order
        PizzaPlace get_order_location()throw (InvalidMenuNumberException, InvalidFileNotOpenException);
        /// set comment
        string get_comment();
        ~Order_UI();
        /// 2 validation that should have been in service
        unsigned int get_integer_input_variable_size(unsigned int size) throw (InvalidMenuNumberException);
        unsigned int get_integer_input_variable_size_with_zeroescape(unsigned int size) throw (InvalidMenuNumberException); /// nota thar sem null er escape char
    private:
        MakeToppingsList toppings_list;
        PizzaSizeService pizza_size;
        MakePizzaBottomList pizza_bottom;
        PizzaPlaceService pizza_places;
        PizzaService pizza_service;
        OrderServices order_service;
        OtherProductsService other_prod_service;
        ValidationService valid;
};

#endif // ORDER_UI_H
