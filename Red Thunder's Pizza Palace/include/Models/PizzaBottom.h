#ifndef PIZZABOTTOM_H
#define PIZZABOTTOM_H
#include <string>
#include <iostream>

using namespace std;

class PizzaBottom
{
    public:
        PizzaBottom(string size, int price);
        friend ostream& operator << (ostream& out, const PizzaBottom& bottom);
    private:
        string size;
        int price;
};

#endif // PIZZABOTTOM_H
