#ifndef MAKEPIZZABOTTOMLIST_H
#define MAKEPIZZABOTTOMLIST_H
#include "PizzaBottomRepository.h"

using namespace std;

class MakePizzaBottomList
{
    public:
        void save_pizza_bottom(const PizzaBottom& pizza_bottom);
    private:
        PizzaBottomRepository pizza_bottoms;
};

#endif // MAKEPIZZABOTTOMLIST_H
