#ifndef OTHERPRODUCTSREPOSITORY_H
#define OTHERPRODUCTSREPOSITORY_H
#include <fstream>
#include "OtherProducts.h"
#include <iostream>
using namespace std;


class OtherProductsRepository
{
    public:
        OtherProductsRepository();
        void store_other_products(const OtherProducts& other_products);
        virtual ~OtherProductsRepository();

    protected:

    private:
};

#endif // OTHERPRODUCTSREPOSITORY_H
