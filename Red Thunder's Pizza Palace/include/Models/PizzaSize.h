#ifndef PIZZASIZE_H
#define PIZZASIZE_H
#include <string>
#include <iostream>

using namespace std;

class PizzaSize
{
    public:
        PizzaSize(string size, int price);
        friend ostream& operator << (ostream& out, PizzaSize& size);
    private:
        string size;
        int price;
};

#endif // PIZZASIZE_H
