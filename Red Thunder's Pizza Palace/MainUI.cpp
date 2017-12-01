#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}
void MainUI::startUI() {

    char selection;                                     // Selection for menu
    while(selection != 'q'){                            // loop until user quit's
        cout << "c: Create list if toppings" << endl,   // Menu for user to pick
        cout << "s: Set prize" << endl;                 // ------""-------------
        cout << "p: Make pizza" << endl;                // ------""-------------
        cout << "q: Quit" << endl;                      // ------""-------------
        cin >> selection;                               // user picks
        if(selection == 'c'){                           // if user picks c go to create topping list class
            manager_sub_ui();
        }else if(selection == 's'){                     // if user picks s go to set prize class

        }else if(selection == 'p'){                     // if user picks p go to make pizza class

        }
    }
}
void MainUI::manager_sub_ui() {

    MakeToppingsList toppings;
    cin >> toppings;
}
