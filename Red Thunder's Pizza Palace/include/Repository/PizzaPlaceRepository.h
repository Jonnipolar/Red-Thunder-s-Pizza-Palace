#ifndef PIZZAPLACEREPOSITORY_H
#define PIZZAPLACEREPOSITORY_H
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "PizzaPlace.h"
using namespace std;


class PizzaPlaceRepository
{
    public:
        void store_pizza_places(vector <PizzaPlace> pizza_place);
        vector <PizzaPlace> get_pizza_place();
    private:
};

#endif // PIZZAPLACEREPOSITORY_H
