#include "ToppingsRepository.h"

ToppingsRepository::ToppingsRepository() {
        //ctor
}

void ToppingsRepository::store_toppings(vector <Toppings> topping) throw (InvalidFileNotOpenException) {

    ofstream fout;
    fout.open("Toppings.txt6");
    if(fout.is_open()){
        for (unsigned int i = 0; i < topping.size(); i++) {
            fout << topping[i];                        /// prints to .txt and is not final, just made it to test
        }
        fout.close();
    }else{throw InvalidFileNotOpenException();}
}
vector <Toppings> ToppingsRepository::get_topping() throw (InvalidFileNotOpenException){
    vector <Toppings> toppings;
    string name;
    ifstream fin("Toppings.txt6");
    if (fin.is_open()) {
        string str;
        while (getline(fin, str)) {
            int index = str.find(':');
            int indexSecond = str.find(':', index + 1);
            int indexThird = str.find(':', indexSecond + 1);
            name = str.substr(0, index);
            string price = str.substr(index + 1, (indexSecond - 1) - index);
            string type = str.substr(indexSecond + 1,(indexThird - 1) - indexSecond);
            int _price = atoi(price.c_str());
            int _type = atoi(type.c_str());
            Toppings topping(name, _price,_type);
            toppings.push_back(topping);
        }
        fin.close();
    }else{throw InvalidFileNotOpenException();}
    return toppings;
}
