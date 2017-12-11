#ifndef PIZZASIZESERVICE_H
#define PIZZASIZESERVICE_H
#include "PizzaSizeRepository.h"

using namespace std;

class PizzaSizeService
{
    public:
        void save_pizza_size(const PizzaSize& pizza_size);
        vector <PizzaSize> Get_Pizza_Sizes();
    private:
        PizzaSizeRepository pizza_sizes_repo;
};

#endif // PIZZASIZESERVICE_H
