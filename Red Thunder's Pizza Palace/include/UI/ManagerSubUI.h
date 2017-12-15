#ifndef MANAGER_SUB_UI_H
#define MANAGER_SUB_UI_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdlib.h>
#include <sstream>
#include "Pizza.h"
#include "PizzaPlace.h"
#include "PizzaService.h"
#include "MakeToppingsList.h"
#include "PizzaSizeService.h"
#include "MakePizzaBottomList.h"
#include "PizzaPlaceService.h"
#include "OtherProductsService.h"
#include "InvalidMenuNumberException.h"
#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "InvalidFileNotOpenException.h"
#include "ValidationService.h"
#include "LegacyService.h"
using namespace std;

class ManagerSubUI
{
public:
       ///Start The UI
    void UI_Start() throw (InvalidMenuNumberException, InvalidFileNotOpenException);
       ///Function to make pizza
    void UImake_pizza();
       ///Sub UI to UImake_pizza to add topping to pizza
    vector <Toppings> SubUI_add_topping();
       ///Function to make topping
    void UI_make_toppings();
       ///Make new pizza sizes
    void UI_make_size();
        ///make new pizza bottom types
    void UI_make_bottom();
        ///Make new pizza places
    void UI_make_pizza_place();
        ///Make new pizza for menu
    void UI_select_make_pizza()throw (InvalidMenuNumberException);
        ///Make new products
    void UI_make_other_items();
    ~ManagerSubUI();
    ///Print the pizza menu list
    void Print_pizza_menu() throw (InvalidFileNotOpenException);
    void get_legacy_list();

private:
    MakeToppingsList toppings_list;
    PizzaSizeService pizza_size;
    MakePizzaBottomList pizza_bottom;
    PizzaPlaceService pizza_places;
    PizzaService pizza_service;
    OtherProductsService serv;
    ValidationService valid;
    LegacyService leg_serv;
};

#endif // MANAGER_SUB_UI_H
