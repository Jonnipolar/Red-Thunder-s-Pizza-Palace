#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>
#include "MakeToppingsList.h"
#include <string>

using namespace std;


class MainUI
{
    public:
        MainUI();
        /// only function in class, sets up UI when logging in
        void startUI();
        /// screen to type in toppings
        void manager_sub_ui();
    private:
};

#endif // MAINUI_H
