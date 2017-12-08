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
vector <PizzaPlace> PizzaPlaceRepository::get_pizza_place() {
    vector <PizzaPlace> pizza_place;
    ifstream fin("PizzaPlaces.txt");
    if(fin.is_open()) {
        string str;
        while (getline(fin, str)) {
            int index = str.find(':');
            int index_second = str.find(':', index +1);
            string street = str.substr(0, index);
            string number = str.substr(index + 1, (index_second - 1) - index);
            int _number = atoi(number.c_str());
            PizzaPlace pizza_places(street, _number);
            pizza_place.push_back(pizza_places);
        }
        fin.close();
    }
    return pizza_place;
}
