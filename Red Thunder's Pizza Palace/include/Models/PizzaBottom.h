#ifndef PIZZABOTTOM_H
#define PIZZABOTTOM_H
#include <string>
#include <iostream>

using namespace std;

class PizzaBottom
{
    public:
        PizzaBottom();
        PizzaBottom(string type, int price);
        string get_type();
        int get_price();
        friend ostream& operator << (ostream& out, const PizzaBottom& bottom);
    private:
        string type;
        int price;
};

#endif // PIZZABOTTOM_H
