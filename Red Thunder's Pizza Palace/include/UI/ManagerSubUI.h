#ifndef MANAGER_SUB_UI_H
#define MANAGER_SUB_UI_H
#include "MakeToppingsList.h"
#include "PizzaSizeService.h"
#include "MakePizzaBottomList.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <Pizza.h>
using namespace std;

class ManagerSubUI
{
    public:
        ManagerSubUI();
        ///Start The UI
        void UI_Start();
        ///Function to make pizza
        void UImake_pizza();
        ///Function to make topping
        void UI_make_toppings();
        void UI_make_size();
        void UI_make_bottom();
        ~ManagerSubUI();

    private:
        MakeToppingsList toppings_list;
        PizzaSizeService pizza_size;
        MakePizzaBottomList pizza_bottom;
};

#endif // MANAGER_SUB_UI_H
