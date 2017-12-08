#include "PizzaRepository.h"

PizzaRepository::PizzaRepository() {

}
void PizzaRepository::store_pizza(const Pizza& pizza) {
    ofstream fout;
    fout.open("Pizzas.txt", ios::app);
    if(fout.is_open()){
        fout << pizza;                        /// prints to .txt and is not final, just made it to test
        fout.close();
    }
}
PizzaRepository::~PizzaRepository() {
    //dtor
}
