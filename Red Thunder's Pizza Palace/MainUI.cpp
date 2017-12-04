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
        if(selection == 'c'){                          // if user picks c go to create topping list class
            make_topping();
        }else if(selection == 's'){                     // if user picks s go to set prize class

        }else if(selection == 'p'){                     // if user picks p go to make pizza class

        }
    }
}
void MainUI::make_topping() {
            string name;
            int price;
            char type;
            cout << "Please type in topping" << endl;
            cout << "Name: ";
            cin >> ws;                                  // ws needed to clear before getline
            getline(cin, name);
            cout << "Price: ";
            cin >> price;
            cout << "Type: \n\tm for meat\n\tv for vegetable\n\tc for cheese" << endl;
            cin >> type;
            MakeToppingsList topping(name, price, type);      // sendir inn í færubreytusmið
            topping.save_topping_list(topping);         // sendir í function sem vistar í skjal
}
