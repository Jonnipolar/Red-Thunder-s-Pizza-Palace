#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}
void MainUI::startUI() {

    char selection;                                                         // Selection for menu
    while(selection != '5'){                                                // loop until user quit's
        cout << "Welcome to Red Thunder's Pizza" << endl;                   //Welcome message
        cout << "Please choose the service you wish to use:" << endl;       // -||-
        cout << "1: Manager" << endl,                                       // Menu for user to pick
        cout << "2: Sales" << endl;                                         // ------""-------------
        cout << "3: Bakery" << endl;                                        // ------""-------------
        cout << "4; Delivery" << endl;                                      // ------""-------------
        cout << "5: Quit" << endl;                                          // ------""-------------
        cin >> selection;                                                   // user picks
        if(selection == '1'){                                               // if user picks c go to Manager's function
<<<<<<< HEAD
            Manager_Sub_UI man_sub_ui;
=======
            ManagerSubUI man_sub_ui;
>>>>>>> kjartan_test
            man_sub_ui.UI_Start();                                          // Go to Manager's sub-UI
        }else if(selection == '2'){                                         // if user picks s go to Order pizza functiobn
            Order_UI order_ui;
            order_ui.UI_Start();
        }else if(selection == '3'){                                         // if user picks b go to Bakery function

        }
        else if (selection == '4') {                                        // if user picks d go to Delivery function

        }
        else {

        }                                                                   // if q quit
    }
}
