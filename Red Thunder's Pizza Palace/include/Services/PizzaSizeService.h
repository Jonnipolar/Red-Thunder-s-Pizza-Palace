#ifndef PIZZASIZESERVICE_H
#define PIZZASIZESERVICE_H
#include "PizzaSizeRepository.h"

using namespace std;

class PizzaSizeService
{
    public:
        void save_pizza_size(const PizzaSize& pizza_size);
    private:
        PizzaSizeRepository pizza_sizes;
};

#endif // PIZZASIZESERVICE_H
