#include "PizzaPlaceRepository.h"

void PizzaPlaceRepository::store_pizza_places(vector <PizzaPlace> pizza_place)  throw (InvalidFileNotOpenException){
    ofstream fout;
    fout.open("PizzaPlaces.txt6");
    if(fout.is_open()){
        for(unsigned int i = 0; i < pizza_place.size(); i++) {
            fout << pizza_place[i];                        /// prints to .txt and is not final, just made it to test
        }
        fout.close();
    }else{throw InvalidFileNotOpenException();}
}
vector <PizzaPlace> PizzaPlaceRepository::get_pizza_place()  throw (InvalidFileNotOpenException){
    vector <PizzaPlace> pizza_place;
    ifstream fin("PizzaPlaces.txt6");
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
    }else{ throw InvalidFileNotOpenException();}
    return pizza_place;
}
