#ifndef ORDERSERVICES_H
#define ORDERSERVICES_H
#include <iostream>
#include "OrderRepository.h"

using namespace std;
class OrderServices
{
    public:
        OrderServices();
        void SaveOrder(const Order& order);
        vector <Order> get_orders();
        ~OrderServices();


    private:
        OrderRepository order_repo;
};

#endif // ORDERSERVICES_H
