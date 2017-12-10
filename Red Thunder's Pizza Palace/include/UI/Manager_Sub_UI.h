#ifndef MANAGER_SUB_UI_H
#define MANAGER_SUB_UI_H
#include "MakeToppingsList.h"
#include <iostream>
#include <string>
using namespace std;

class Manager_Sub_UI
{
    public:
        Manager_Sub_UI();
        ///Start The UI
        void UI_Start();
        ///Function to make pizza
        void UI_make_pizza();
        ///Function to make topping
        void UI_make_toppings();
        ~Manager_Sub_UI();

    private:
};

#endif // MANAGER_SUB_UI_H
