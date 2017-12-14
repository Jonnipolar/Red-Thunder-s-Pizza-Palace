#ifndef PIZZAPLACEREPOSITORY_H
#define PIZZAPLACEREPOSITORY_H
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "PizzaPlace.h"
#include "InvalidFileNotOpenException.h"
using namespace std;


class PizzaPlaceRepository
{
    public:
        void store_pizza_places(vector <PizzaPlace> pizza_place) throw (InvalidFileNotOpenException);
        vector <PizzaPlace> get_pizza_place() throw (InvalidFileNotOpenException);
    private:
};

#endif // PIZZAPLACEREPOSITORY_H
