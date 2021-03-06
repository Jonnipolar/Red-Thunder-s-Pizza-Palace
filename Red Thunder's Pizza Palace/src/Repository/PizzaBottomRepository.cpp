#include "PizzaBottomRepository.h"

void PizzaBottomRepository::store_pizza_bottom(vector <PizzaBottom> pizza_bottom)  throw (InvalidFileNotOpenException){
    ofstream fout;
    fout.open("PizzaBottom.txt");
    if(fout.is_open()){
        for (unsigned int i = 0; i < pizza_bottom.size(); i++) {
            fout << pizza_bottom[i];                        /// prints to .txt and is not final, just made it to test
        }
        fout.close();
    }else{throw InvalidFileNotOpenException();}
}
vector <PizzaBottom> PizzaBottomRepository::get_pizza_bottom()  throw (InvalidFileNotOpenException){
    vector <PizzaBottom> pizza_bottoms;
    ifstream fin("PizzaBottom.txt");
    if (fin.is_open()) {
        string str;
        while (getline(fin, str)) {
            int index = str.find(':');
            int index_second = str.find(':', index + 1);
            string type = str.substr(0, index);
            string price = str.substr(index +1, (index_second - 1) - index);
            int _price = atoi(price.c_str());
            PizzaBottom pizza_bottom(type, _price);
            pizza_bottoms.push_back(pizza_bottom);
        }
        fin.close();
    }else{throw InvalidFileNotOpenException();}
    return pizza_bottoms;
}
