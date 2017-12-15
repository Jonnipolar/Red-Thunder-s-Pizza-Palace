#include "OtherProductsRepository.h"

OtherProductsRepository::OtherProductsRepository()
{
    //ctor
}
void OtherProductsRepository::store_other_products(vector <OtherProducts> other_products)  throw (InvalidFileNotOpenException){
    ofstream fout;
    fout.open("OtherProducts.txt");
    if(fout.is_open()) {
        for(unsigned int i = 0; i < other_products.size(); i++) {
            fout << other_products[i];
        }
        fout.close();
    }else{throw InvalidFileNotOpenException();}
}
vector <OtherProducts> OtherProductsRepository::get_other_products()  throw (InvalidFileNotOpenException){
    vector <OtherProducts> other_products;
    ifstream fin("OtherProducts.txt");
    if(fin.is_open()) {
        string str;
        while (getline(fin, str)) {
            int index = str.find(':');
            int index_second = str.find(':', index + 1);
            int index_third = str.find(':', index_second + 1);
            string name = str.substr(0, index);
            string price = str.substr(index + 1, (index_second - 1) - index);
            string type = str.substr(index_second + 1, (index_third - 1) - index_second);
            int _price = atoi(price.c_str());
            int _type = atoi(type.c_str());
            OtherProducts other_product(name, _price, _type);
            other_products.push_back(other_product);
        }
        fin.close();
    }else{throw InvalidFileNotOpenException();}
    return other_products;
}
