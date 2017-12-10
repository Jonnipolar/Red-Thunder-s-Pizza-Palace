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
vector <Pizza> PizzaRepository::get_pizza () {
    vector <Pizza> pizza;
    ifstream fin("Pizzas.txt");
    string name;
    string price;
    PizzaSize _size;
    PizzaBottom bottom;
    string toppings;
    vector <Toppings> topping;
    if (fin.is_open()) {
        string str;
        while (getline(fin, str)) {
            int index = str.find(':');
            int index_second = str.find(':', index + 1);
            int index_third = str.find(':', index_second + 1);
            name = str.substr(0, index);
            price = str.substr(index + 1, (index_second - 1) - index);
            toppings = str.substr(index_second + 1, (index_third - 1) - index_second);
            int _price = atoi(price.c_str());
            for(unsigned int i = 0; i < toppings.size();i++) {
                string parse = "";
                if(toppings[i] != ',') {
                    parse += toppings[i];
                }else{
                    Toppings _topping(parse,0,0);
                    topping.push_back(_topping);
                    parse = "";
                }
                if(i == (topping.size()-1)){
                    Toppings _topping(parse,0,0);
                    topping.push_back(_topping);
                    parse = "";
                }
            }
            Pizza pizzas(name,_price,topping,bottom,_size);
            pizza.push_back(pizzas);
        }
        fin.close();
    }
    return pizza;
}
PizzaRepository::~PizzaRepository() {
    //dtor
}
