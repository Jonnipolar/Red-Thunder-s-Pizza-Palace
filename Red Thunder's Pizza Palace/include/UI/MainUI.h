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
<<<<<<< HEAD:Red Thunder's Pizza Palace/include/UI/MainUI.h
        /// UI for Manager
=======
>>>>>>> b6c3ff64e503bb22198904bd633c8458244c5475:Red Thunder's Pizza Palace/MainUI.h
    private:
        /// to type in topping
        void make_topping();
};

#endif // MAINUI_H
