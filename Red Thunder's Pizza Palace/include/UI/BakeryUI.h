#ifndef BAKERYUI_H
#define BAKERYUI_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "OrderServices.h"
#include "PizzaPlaceService.h"

using namespace std;
class BakeryUI
{
    public:
        BakeryUI();
        ~BakeryUI();
        void StartUI();

    private:
        PizzaPlaceService pizza_service;
};

#endif // BAKERYUI_H
