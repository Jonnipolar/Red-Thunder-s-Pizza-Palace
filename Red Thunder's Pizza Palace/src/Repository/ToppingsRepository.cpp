#include "ToppingsRepository.h"

ToppingsRepository::ToppingsRepository() {
        //ctor
}

void ToppingsRepository::store_toppings(const Toppings& topping) {

    ofstream fout;
    fout.open("Toppings.txt", ios::app);
    if(fout.is_open()){
        fout << topping;                        /// prints to .txt and is not final, just made it to test
        fout.close();
    }
}
vector <Toppings> ToppingsRepository::get_topping() {
    vector <Toppings> toppings;
    ifstream fin;
    Toppings topping;

    fin.open("Toppings.txt");


    return toppings;
}
