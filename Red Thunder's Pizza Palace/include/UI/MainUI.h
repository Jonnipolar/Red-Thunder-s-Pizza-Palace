#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>
#include <string>
#include "ManagerSubUI.h"
#include "OrderUI.h"
#include "BakeryUI.h"
#include "DeliveryUI.h"
#include "InvalidMenuNumberException.h"
#include <stdlib.h>

using namespace std;

class MainUI
{
    public:
        MainUI();
        /// only function in class, sets up UI when logging in
        void startUI() throw (InvalidMenuNumberException);
        /// UI for Manager

    private:
        /// to type in topping
        void make_topping();
        ManagerSubUI man_sub_ui;
        Order_UI order_UI;
        BakeryUI bakery_ui;
        DeliveryUI delivery_ui;
};

#endif // MAINUI_H
