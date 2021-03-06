#ifndef MAKEPIZZABOTTOMLIST_H
#define MAKEPIZZABOTTOMLIST_H
#include "PizzaBottomRepository.h"

using namespace std;

class MakePizzaBottomList
{
    public:
        ///send order to repo
        void save_pizza_bottom(string name, int price);
        ///get order from repo
        vector <PizzaBottom> Get_Pizza_Bottom();
    private:
        PizzaBottomRepository pizza_bottom_repo;
};

#endif // MAKEPIZZABOTTOMLIST_H
