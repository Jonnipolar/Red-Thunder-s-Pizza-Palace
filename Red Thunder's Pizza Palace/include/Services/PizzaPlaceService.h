#ifndef PIZZAPLACESERVICE_H
#define PIZZAPLACESERVICE_H
#include "PizzaPlaceRepository.h"

class PizzaPlaceService
{
    public:
        void save_pizza_place(string street, int number);
        vector <PizzaPlace> get_pizza_place();
    private:
        PizzaPlaceRepository pizza_places;
};

#endif // PIZZAPLACESERVICE_H
