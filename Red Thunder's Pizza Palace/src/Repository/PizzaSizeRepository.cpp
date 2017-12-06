#include "PizzaSizeRepository.h"

void PizzaSizeRepository::store_pizza_size(const PizzaSize& pizza_size) {
    ofstream fout;
    fout.open("PizzaSize.txt", ios::app);
    if(fout.is_open()){
        fout << pizza_size;                        /// prints to .txt and is not final, just made it to test
        fout.close();
    }
}
