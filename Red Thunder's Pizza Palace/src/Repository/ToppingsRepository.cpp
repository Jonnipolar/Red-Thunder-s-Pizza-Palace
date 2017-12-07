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
    string str;
    string name;
    string delim = ":";
    string substr;
    stringstream ss;
    int price;
    int pos;
    int type;
    ifstream fin;
    fin.open("Toppings.txt");
    if (fin.is_open()) {
        while (getline(fin, str)) {
            name = str.substr(0, str.find(delim));
            pos = str.find(delim);
            str.erase(0, pos + delim.length());
            substr = str.substr(0, str.find(delim));
            ss << substr;
            ss >> price;
            pos = str.find(delim);
            str.erase(0, pos + delim.length());
            substr = str.substr(0, str.find(delim));
            ss << substr;
            ss >> type;
            Toppings topping(name, price, type);
            toppings.push_back(topping);
        }
    }
    return toppings;
}
