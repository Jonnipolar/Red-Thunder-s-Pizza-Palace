#ifndef MAKETOPPINGSLIST_H
#define MAKETOPPINGSLIST_H
#include <string>
#include <iostream>
#include <vector>
#include "ToppingsRepository.h"

using namespace std;

class MakeToppingsList
{
    public:
        /// sends information to toppings repository
        void save_topping_list(string name, int price, int type);
        ///Get Complete list of toppings
        vector <Toppings> get_topping_list();
        ///Get a list of toppings specified by type
        vector <Toppings> get_selected_list(int sel);
    private:
        ToppingsRepository repo;
};

#endif // MAKETOPPINGSLIST_H
