#ifndef MANAGER_SUB_UI_H
#define MANAGER_SUB_UI_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Pizza.h"
#include "PizzaPlace.h"
#include "PizzaService.h"
#include "MakeToppingsList.h"
#include "PizzaSizeService.h"
#include "MakePizzaBottomList.h"
#include "PizzaPlaceService.h"
#include "OtherProductsService.h"
#include <stdlib.h>
#include <sstream>
#include "InvalidMenuNumberException.h"
#include "InvalidNameException.h"
using namespace std;

class ManagerSubUI
{
    public:
        ManagerSubUI();
        ///Start The UI
        void UI_Start() throw (InvalidMenuNumberException);
        ///Function to make pizza
        void UImake_pizza() throw (InvalidNameException);
        ///Sub UI to UImake_pizza to add topping to pizza
        vector <Toppings> SubUI_add_topping();
        ///Function to make topping
        void UI_make_toppings() throw(InvalidNameException);
        void UI_make_menu();
        void UI_make_size();
        void UI_make_bottom();
        void UI_make_pizza_place();
        void UI_select_make_pizza();
        void UI_make_other_items();
        ~ManagerSubUI();

    private:
        MakeToppingsList toppings_list;
        PizzaSizeService pizza_size;
        MakePizzaBottomList pizza_bottom;
        PizzaPlaceService pizza_places;
        PizzaService pizza_service;
        OtherProductsService serv;
};

#endif // MANAGER_SUB_UI_H
