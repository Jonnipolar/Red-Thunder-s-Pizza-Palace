#include "PizzaRepository.h"

PizzaRepository::PizzaRepository() {

}
void PizzaRepository::store_pizza(vector <Pizza> pizza)  throw (InvalidFileNotOpenException){
    ofstream fout;
    fout.open("Pizzas.txt6");
    if(fout.is_open()){
        for(unsigned int i = 0; i < pizza.size(); i++) {
            fout << pizza[i];                        /// prints to .txt and is not final, just made it to test
        }
        fout.close();
    }else{throw InvalidFileNotOpenException();}
}
vector <Pizza> PizzaRepository::get_pizza () throw (InvalidFileNotOpenException){
    vector <Pizza> pizza;
    ifstream fin("Pizzas.txt6");
    string name;
    string price;
    string parse = "";
    PizzaSize _size;
    PizzaBottom bottom;
    string toppings;
    if (fin.is_open()) {
        string str;
        while (getline(fin, str)) {
            vector <Toppings> topping;
            parse = "";
            int index = str.find(':');
            int index_second = str.find(':', index + 1);
            int index_third = str.find(':', index_second + 1);
            name = str.substr(0, index);
            price = str.substr(index + 1, (index_second - 1) - index);
            toppings = str.substr(index_second + 1, (index_third - 1) - index_second);
            int _price = atoi(price.c_str());
            for(unsigned int i = 0; i < toppings.size();i++) {
                if(toppings[i] == ',') {
                    Toppings _topping(parse,0,0);
                    topping.push_back(_topping);
                    parse = "";
                }else{
                    parse += toppings[i];
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
    }else{throw InvalidFileNotOpenException();};
    return pizza;
}
PizzaRepository::~PizzaRepository() {
    //dtor
}
