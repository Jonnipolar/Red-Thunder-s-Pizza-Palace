#ifndef PIZZASIZESERVICE_H
#define PIZZASIZESERVICE_H
#include "PizzaSizeRepository.h"

using namespace std;

class PizzaSizeService
{
    public:
        ///Save the pizza size to text file
        void save_pizza_size(string name, int price);
        ///Get the list of sizes from the text file
        vector <PizzaSize> Get_Pizza_Sizes();
    private:
        PizzaSizeRepository pizza_sizes_repo;
};

#endif // PIZZASIZESERVICE_H
