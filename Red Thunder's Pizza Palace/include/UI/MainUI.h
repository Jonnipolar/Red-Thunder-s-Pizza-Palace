#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>
#include <string>
#include "Manager_Sub_UI.h"
#include "Order_UI.h"

using namespace std;

class MainUI
{
    public:
        MainUI();
        /// only function in class, sets up UI when logging in
        void startUI();
        /// UI for Manager
        
    private:
        /// to type in topping
        void make_topping();
};

#endif // MAINUI_H
