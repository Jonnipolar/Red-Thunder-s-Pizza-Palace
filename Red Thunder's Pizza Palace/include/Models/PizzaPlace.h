#ifndef PIZZAPLACE_H
#define PIZZAPLACE_H
#include <iostream>
#include <string>

using namespace std;

class PizzaPlace
{
    public:
        PizzaPlace();
        PizzaPlace(string street, int number);
        string get_street();
        int get_number();
        friend ostream& operator << (ostream& out, const PizzaPlace& pizza_place);
    private:
        string street;
        int number;
};

#endif // PIZZAPLACE_H
