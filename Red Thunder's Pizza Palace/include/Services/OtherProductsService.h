#ifndef OTHERPRODUCTSSERVICE_H
#define OTHERPRODUCTSSERVICE_H
#include <vector>
#include "OtherProductsRepository.h"

using namespace std;

class OtherProductsService
{
    public:

        void save_other_products(string name, int price, int type);
        vector <OtherProducts> get_other_product();
        vector <OtherProducts> get_soda_list();
        vector <OtherProducts> get_sauces_list();
        vector <OtherProducts> get_side();
    private:
        OtherProductsRepository repo;
};

#endif // OTHERPRODUCTSSERVICE_H
