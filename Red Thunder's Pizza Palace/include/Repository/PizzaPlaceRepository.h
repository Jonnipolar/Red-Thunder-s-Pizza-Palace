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
        PizzaPlaceRepository();
        ~PizzaPlaceRepository();
        void store_pizza_places(const PizzaPlace& pizza_place);
        vector <PizzaPlace> get_pizza_place();
    private:
};

#endif // PIZZAPLACEREPOSITORY_H
