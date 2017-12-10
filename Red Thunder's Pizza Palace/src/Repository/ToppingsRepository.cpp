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
    string name;
    ifstream fin("Toppings.txt");
    if (fin.is_open()) {
        string str;
        while (getline(fin, str)) {
            int index = str.find(':');
            int indexSecond = str.find(':', index + 1 );
            int indexThird = str.find(':', indexSecond + 1 );
            name = str.substr(0, index);
            string price = str.substr(index + 1, (indexSecond - 1) - index );
            string type = str.substr(indexSecond + 1,(indexThird - 1) - indexSecond );
            int _price = atoi(price.c_str());
            int _type = atoi(type.c_str());
            Toppings topping(name, _price,_type);
            toppings.push_back(topping);
        }
        fin.close();
    }
    return toppings;
}
