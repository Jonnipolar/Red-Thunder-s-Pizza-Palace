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
    private:
        /// to type in topping
        void make_topping();
};

#endif // MAINUI_H
