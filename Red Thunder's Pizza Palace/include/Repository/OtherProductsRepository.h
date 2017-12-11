#define OTHERPRODUCTSREPOSITORY_H
#define OTHERPRODUCTSREPOSITORY_H
#include <fstream>
#include "OtherProducts.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


class OtherProductsRepository
{
    public:
        OtherProductsRepository();
        void store_other_products(const OtherProducts& other_products);
        vector <OtherProducts> get_other_products();
};

