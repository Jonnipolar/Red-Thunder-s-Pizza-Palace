#include "OrderUI.h"

Order_UI::Order_UI()
{
    //ctor
}
void Order_UI::UI_Start() {
    char selection;                                                             // Create Variable to keep hold of user selection
    while (selection != '2') {                                                  // While loop
        system("CLS");
        cout << "Hello and welcome to Red Thunder's Pizza" << endl;           // Welcome Message
        cout << "How may i help you?" << endl;                                  // -||-
        cout << "1: Add an order" << endl;                                      // Choice
        cout << "2: Quit" << endl;                                              // Choice
        cin >> selection;                                                       // Get user Input
        switch (selection) {
            case '1':
                UI_Add_Order();
                break;
            case '2':
                break;

        }
    }
}
void Order_UI::UI_Add_Order() {

}
Order_UI::~Order_UI()
{
    //dtor
}
