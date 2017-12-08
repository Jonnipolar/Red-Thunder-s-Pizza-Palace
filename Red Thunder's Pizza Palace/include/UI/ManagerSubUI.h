#ifndef MANAGER_SUB_UI_H
#define MANAGER_SUB_UI_H
#include "MakeToppingsList.h"
#include "PizzaSizeService.h"
#include "MakePizzaBottomList.h"
#include "PizzaPlaceService.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Pizza.h"
#include "PizzaPlace.h"

using namespace std;

class ManagerSubUI
{
    public:
        ManagerSubUI();
        ///Start The UI
        void UI_Start();
        ///Function to make pizza
        void UImake_pizza();
        ///Sub UI to UImake_pizza to add topping to pizza
        vector <Toppings> SubUI_add_topping();
        ///Function to make topping
        void UI_make_toppings();
        void UI_make_size();
        void UI_make_bottom();
        void UI_make_pizza_place();
        ~ManagerSubUI();

    private:
        MakeToppingsList toppings_list;
        PizzaSizeService pizza_size;
        MakePizzaBottomList pizza_bottom;
        PizzaPlaceService pizza_places;
};

#endif // MANAGER_SUB_UI_H
