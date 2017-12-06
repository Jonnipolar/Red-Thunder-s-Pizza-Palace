#include "PizzaBottomRepository.h"

void PizzaBottomRepository::store_pizza_bottom(const PizzaBottom pizza_bottom) {
    ofstream fout;
    fout.open("PizzaBottom.txt", ios::app);
    if(fout.is_open()){
        fout << pizza_bottom;                        /// prints to .txt and is not final, just made it to test
        fout.close();
    }
}
