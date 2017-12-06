#include "ToppingsRepository.h"


void ToppingsRepository::store_toppings(const Toppings& topping) {

    ofstream fout;
    fout.open("Toppings.txt", ios::app);
    if(fout.is_open()){
        fout << topping;                        /// prints to .txt and is not final, just made it to test
        fout.close();
    }
}
