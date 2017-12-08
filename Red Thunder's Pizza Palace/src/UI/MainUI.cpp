#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}
void MainUI::startUI() {

    char selection;                                                         // Selection for menu
    while(selection != '5'){                                                // loop until user quit's
        system("CLS");
        cout << "Welcome to Red Thunder's Pizza" << endl;                   //Welcome message
        cout << "Please choose the service you wish to use:" << endl;       // -||-
        cout << "[1] Manager" << endl,                                       // Menu for user to pick
        cout << "[2] Sales" << endl;                                         // ------""-------------
        cout << "[3] Bakery" << endl;                                        // ------""-------------
        cout << "[4] Delivery" << endl;                                      // ------""-------------
        cout << "[5] Quit" << endl;                                          // ------""-------------
        cin >> selection;
        ManagerSubUI man_sub_ui;
        Order_UI order_ui;
        switch(selection){                                                 // user picks
            case '1':                                               // if user picks c go to Manager's function
                man_sub_ui.UI_Start();                                          // Go to Manager's sub-UI
                break;
            case '2':                                         // if user picks s go to Order pizza functiobn
                order_ui.UI_Start();
                break;
            case '3':                                         // if user picks b go to Bakery function
                break;
            case '4':
                break;                                      // if user picks d go to Delivery function
        }                                                                   // if q quit
    }
}
