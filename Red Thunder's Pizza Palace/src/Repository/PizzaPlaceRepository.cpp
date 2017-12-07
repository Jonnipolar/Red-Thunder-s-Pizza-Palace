#include "PizzaPlaceRepository.h"

PizzaPlaceRepository::PizzaPlaceRepository()
{
    //ctor
}

PizzaPlaceRepository::~PizzaPlaceRepository()
{
    //dtor
}
void PizzaPlaceRepository::store_pizza_places(const PizzaPlace& pizza_place) {
    ofstream fout;
    fout.open("PizzaPlaces.txt", ios::app);
    if(fout.is_open()){
        fout << pizza_place;                        /// prints to .txt and is not final, just made it to test
        fout.close();
    }
}
