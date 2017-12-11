#include "OtherProductsService.h"

void OtherProductsService::save_other_products(const OtherProducts& other_products) {
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
        if(other_products[i].get_type()) {
            side_prod.push_back(other_products[i]);
        }
    }
    return side_prod;
}
