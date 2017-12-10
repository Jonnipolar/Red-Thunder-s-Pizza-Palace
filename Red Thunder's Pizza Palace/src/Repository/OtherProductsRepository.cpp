#include "OtherProductsRepository.h"

OtherProductsRepository::OtherProductsRepository()
{
    //ctor
}
void OtherProductsRepository::store_other_products(const OtherProducts& other_products) {
    ofstream fout;
    fout.open("OtherProducts.txt", ios::app);
    if(fout.is_open()) {
        fout << other_products;
        fout.close();
    }
}
OtherProductsRepository::~OtherProductsRepository()
{
    //dtor
}
