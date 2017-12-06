#ifndef MANAGER_SUB_UI_H
#define MANAGER_SUB_UI_H
#include "MakeToppingsList.h"
#include <iostream>
#include <string>
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
        ~ManagerSubUI();

    private:
        MakeToppingsList toppings_list;
};

#endif // MANAGER_SUB_UI_H
