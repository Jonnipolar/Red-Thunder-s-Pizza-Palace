#ifndef OTHERPRODUCTS_H
#define OTHERPRODUCTS_H
#include <string>
#include <iostream>

using namespace std;


class OtherProducts
{
    public:
        OtherProducts(string name, int price, int type);
        string get_name();
        int get_price();
        int get_type();
        virtual ~OtherProducts();
    private:
        string name;
        int price;
        int type;
};

#endif // OTHERPRODUCTS_H
