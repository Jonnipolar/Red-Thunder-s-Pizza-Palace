#include "OtherProductsService.h"

OtherProductsService::OtherProductsService()
{
    //ctor
}
vector <OtherProducts> get_other_product() {
    OtherProductsRepository repo;
    vector <OtherProducts> other_products = repo.get_other_products();
    return other_products;
}
OtherProductsService::~OtherProductsService()
{
    //dtor
}
