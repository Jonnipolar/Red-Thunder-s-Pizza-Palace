#define OTHERPRODUCTSREPOSITORY_H
#define OTHERPRODUCTSREPOSITORY_H
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "OtherProducts.h"
#include "InvalidFileNotOpenException.h"

using namespace std;


class OtherProductsRepository
{
    public:
        OtherProductsRepository();
        void store_other_products(vector <OtherProducts> other_products) throw (InvalidFileNotOpenException);
        vector <OtherProducts> get_other_products() throw (InvalidFileNotOpenException);
};

