#ifndef OTHERPRODUCTSSERVICE_H
#define OTHERPRODUCTSSERVICE_H
#include <vector>
#include "OtherProductsRepository.h"

using namespace std;

class OtherProductsService
{
    public:
        OtherProductsService();
        virtual ~OtherProductsService();
        vector <OtherProducts> get_other_product();
    private:
        OtherProductsRepository repo;
};

#endif // OTHERPRODUCTSSERVICE_H
