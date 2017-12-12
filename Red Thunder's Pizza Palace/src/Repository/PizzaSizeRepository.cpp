#include "PizzaSizeRepository.h"

void PizzaSizeRepository::store_pizza_size(vector <PizzaSize> pizza_size) {
    ofstream fout;
    fout.open("PizzaSize.txt");
    if(fout.is_open()){
        for(unsigned int i = 0; i < pizza_size.size(); i++) {
                    fout << pizza_size[i];                        /// prints to .txt and is not final, just made it to test
        }
        fout.close();
    }
}
vector <PizzaSize> PizzaSizeRepository::get_pizza_size() {
    vector <PizzaSize> pizza_sizes;
    ifstream fin("PizzaSize.txt");
    if(fin.is_open()) {
        string str;
        while (getline(fin,str)) {
            int index = str.find(':');
            int index_second = str.find(':', index + 1);
            string size = str.substr(0, index);
            string price = str.substr(index + 1, (index_second - 1) - index);
            int _price = atoi(price.c_str());
            PizzaSize pizza_size(size, _price);
            pizza_sizes.push_back(pizza_size);
        }
        fin.close();
    }
    return pizza_sizes;
}
