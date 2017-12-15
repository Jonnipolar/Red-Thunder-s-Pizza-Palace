#ifndef PIZZAPLACESERVICE_H
#define PIZZAPLACESERVICE_H
#include "PizzaPlaceRepository.h"

class PizzaPlaceService
{
    public:
        ///Save the pizza place to the text file
        void save_pizza_place(string street, int number);
        ///Get list of pizza places from the text file
        vector <PizzaPlace> get_pizza_place();
    private:
        PizzaPlaceRepository pizza_places;
};

#endif // PIZZAPLACESERVICE_H
