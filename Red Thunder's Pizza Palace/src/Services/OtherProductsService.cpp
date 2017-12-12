#include "OtherProductsService.h"

void OtherProductsService::save_other_products(string name, int price, int type) {
    bool check = true;
    vector <OtherProducts> other_products = get_other_product();
    for(unsigned int i = 0; i < name.size(); i++) {
        name[i] = tolower(name[i]);
    }
    OtherProducts other_product(name, price, type);
    for(unsigned int i = 0; i < other_products.size(); i++) {
        if(other_products[i].get_name() == name) {
            other_products[i] = other_product;
            check = false;
        }
    }
    if(check) {
        other_products.push_back(other_product);
    }
    repo.store_other_products(other_products);
}
vector <OtherProducts> OtherProductsService::get_other_product() {
    vector <OtherProducts> other_products = repo.get_other_products();
    return other_products;
}
vector <OtherProducts> OtherProductsService::get_soda_list() {
    vector <OtherProducts> other_products = repo.get_other_products();
    vector <OtherProducts> soda_prod;
    for (unsigned int i = 0; i < other_products.size(); i++) {
        if(other_products[i].get_type() == 1) {
            soda_prod.push_back(other_products[i]);
        }
    }
    return soda_prod;
}
vector <OtherProducts> OtherProductsService::get_sauces_list() {
    vector <OtherProducts> other_products = repo.get_other_products();
    vector <OtherProducts> sauce_prod;
    for (unsigned int i = 0; i < other_products.size(); i++) {
        if(other_products[i].get_type() == 2) {
            sauce_prod.push_back(other_products[i]);
        }
    }
    return sauce_prod;
}
vector <OtherProducts> OtherProductsService::get_side() {
    vector <OtherProducts> other_products = repo.get_other_products();
    vector <OtherProducts> side_prod;
    for (unsigned int i = 0; i < other_products.size(); i++) {
        if(other_products[i].get_type() == 3) {
            side_prod.push_back(other_products[i]);
        }
    }
    return side_prod;
}
