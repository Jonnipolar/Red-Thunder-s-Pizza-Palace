#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>
#include <string>
<<<<<<< HEAD:Red Thunder's Pizza Palace/include/UI/MainUI.h
#include "Manager_Sub_UI.h"
#include "Order_UI.h"
=======
#include "ManagerSubUI.h"
#include "OrderUI.h"
>>>>>>> kjartan_test:Red Thunder's Pizza Palace/include/UI/MainUI.h

using namespace std;

class MainUI
{
    public:
        MainUI();
        /// only function in class, sets up UI when logging in
        void startUI();
        /// UI for Manager
<<<<<<< HEAD:Red Thunder's Pizza Palace/include/UI/MainUI.h
        
=======

>>>>>>> kjartan_test:Red Thunder's Pizza Palace/include/UI/MainUI.h
    private:
        /// to type in topping
        void make_topping();
};

#endif // MAINUI_H
