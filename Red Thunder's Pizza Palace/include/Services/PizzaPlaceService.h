#ifndef PIZZAPLACESERVICE_H
#define PIZZAPLACESERVICE_H
#include "PizzaPlaceRepository.h"

class PizzaPlaceService
{
    public:
        PizzaPlaceService();
        virtual ~PizzaPlaceService();
        void save_pizza_place(const PizzaPlace& pizza_place);
    private:
        PizzaPlaceRepository pizza_places;
};

#endif // PIZZAPLACESERVICE_H
