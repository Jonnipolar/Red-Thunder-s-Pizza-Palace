#include "ToppingsRepository.h"
using namespace std;

ToppingsRepository::ToppingsRepository() {
        //ctor
}

void ToppingsRepository::store_toppings(MakeToppingsList topping) {

    ofstream fout;
    fout.open("Toppings.txt", ios::app);

    fout << topping;                        /// prints to .txt and is not final, just made it to test

    fout.close();
}
