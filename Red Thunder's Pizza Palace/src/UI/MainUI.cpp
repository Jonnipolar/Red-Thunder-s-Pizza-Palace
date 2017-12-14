#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}
void MainUI::startUI()throw (InvalidMenuNumberException)
{

    char selection;
    bool is_valid = true;                                                       // Selection for menu
    while(selection != '5') {                                                   // loop until user quit's
        system("CLS");
        cout << "Welcome to Red Thunder's Pizza" << endl;                       //Welcome message
        cout << "Please choose the service you wish to use:" << endl;           // -||-
        cout << "[1] Manager" << endl,                                          // Menu for user to pick
        cout << "[2] Sales" << endl;                                            // ------""-------------
        cout << "[3] Bakery" << endl;                                           // ------""-------------
        cout << "[4] Delivery" << "inactive ATM" << endl ;                       // ------""-------------
        cout << "[5] Quit" << endl;                                             // ------""-------------
        do {
            try {
                is_valid = true;
                cout << "Select option: ";
                cin.sync();
                cin >> selection;
                switch (selection) {
                case '1':
                    man_sub_ui.UI_Start();                                      // Go to Manager's sub-UI
                    break;
                case '2':
                    order_UI.UI_Start();
                    break;
                case '3':
                    bakery_ui.StartUI();                                        // if user picks b go to Bakery function
                    break;
                case '4':
                    cout << "vantar";
                    break;
                case '5':
                    cout << "Goodbye User" << endl;
                    system("exit");
                    break;
                default:
                    is_valid = false;
                    throw InvalidMenuNumberException();
                }
            } catch(InvalidMenuNumberException e) {
                cout << e.get_message();
            };
        } while(!is_valid);                                                     // if 5 quit

    }
}
