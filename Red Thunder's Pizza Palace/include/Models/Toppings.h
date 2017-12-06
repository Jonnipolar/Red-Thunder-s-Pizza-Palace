#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <string>
#include <iostream>
using namespace std;

class Toppings
{
    public:
        /// class constructor
        Toppings();
        Toppings(string name, int price, int type);
        string get_name();
        int get_price();
        int get_type();
        /// overwrite ostream
        friend ostream& operator << (ostream& out, const Toppings& topping);
    private:
        string name;
        int price;
        int type;
};

#endif // TOPPINGS_H
