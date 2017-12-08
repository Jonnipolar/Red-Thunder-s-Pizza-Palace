#ifndef PIZZAPLACEREPOSITORY_H
#define PIZZAPLACEREPOSITORY_H
#include "PizzaPlace.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


class PizzaPlaceRepository
{
    public:
        PizzaPlaceRepository();
        virtual ~PizzaPlaceRepository();
        void store_pizza_places(const PizzaPlace& pizza_place);
        vector <PizzaPlace> get_pizza_place();
    private:
};

#endif // PIZZAPLACEREPOSITORY_H
