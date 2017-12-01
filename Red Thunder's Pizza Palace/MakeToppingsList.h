#ifndef MAKETOPPINGSLIST_H
#define MAKETOPPINGSLIST_H
#include <string>
#include <iostream>

using namespace std;

class MakeToppingsList
{
    public:
        MakeToppingsList();
        MakeToppingsList(string name, int price);
        void fill_toppings_list();
        friend istream& operator >> (istream& in, MakeToppingsList toppings);
        friend ostream& operator << (ostream& out, const MakeToppingsList& topping);
    private:
        string name;
        int price;
};

#endif // MAKETOPPINGSLIST_H
