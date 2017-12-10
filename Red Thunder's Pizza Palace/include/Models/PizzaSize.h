#ifndef PIZZASIZE_H
#define PIZZASIZE_H
#include <string>
#include <iostream>

using namespace std;

class PizzaSize
{
    public:
        PizzaSize();
        PizzaSize(string _size, int price);
        string get_size();
        int get_price();
        friend ostream& operator << (ostream& out, const PizzaSize& size);
    private:
        string _size;
        int price;
};

#endif // PIZZASIZE_H
