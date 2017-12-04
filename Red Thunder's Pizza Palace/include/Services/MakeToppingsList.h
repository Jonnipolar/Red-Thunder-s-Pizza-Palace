#ifndef MAKETOPPINGSLIST_H
#define MAKETOPPINGSLIST_H
#include <string>
#include <iostream>

using namespace std;

class MakeToppingsList
{
    public:
        /// 0 class constructor
        MakeToppingsList();
        /// class constructor
        MakeToppingsList(string name, int price, char type);
        string get_name();
        int get_price();
        /// sends information to toppings repository
        void save_topping_list(MakeToppingsList toppings);
        /// overwrite ostream
        friend ostream& operator << (ostream& out, MakeToppingsList& topping);
    private:
        string name;
        int price;
        char type;
};

#endif // MAKETOPPINGSLIST_H
