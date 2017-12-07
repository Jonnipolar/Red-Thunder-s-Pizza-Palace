#ifndef PIZZAPLACEREPOSITORY_H
#define PIZZAPLACEREPOSITORY_H
#include "PizzaPlace.h"
#include <fstream>
using namespace std;


class PizzaPlaceRepository
{
    public:
        PizzaPlaceRepository();
        virtual ~PizzaPlaceRepository();
        void store_pizza_places(const PizzaPlace& pizza_place);
    private:
};

#endif // PIZZAPLACEREPOSITORY_H
