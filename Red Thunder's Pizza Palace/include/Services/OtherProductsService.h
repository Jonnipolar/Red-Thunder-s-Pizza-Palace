#ifndef OTHERPRODUCTSSERVICE_H
#define OTHERPRODUCTSSERVICE_H
#include <vector>
#include "OtherProductsRepository.h"

using namespace std;

class OtherProductsService
{
    public:
        ///Save other products to the text file
        void save_other_products(string name, int price, int type);
        ///Get list of other products from text file
        vector <OtherProducts> get_other_product();
        ///Get list of soda products from text file
        vector <OtherProducts> get_soda_list();
        ///Get list of sauce products from text file
        vector <OtherProducts> get_sauces_list();
        ///Get list of side products from text file
        vector <OtherProducts> get_side();
    private:
        OtherProductsRepository repo;
};

#endif // OTHERPRODUCTSSERVICE_H
