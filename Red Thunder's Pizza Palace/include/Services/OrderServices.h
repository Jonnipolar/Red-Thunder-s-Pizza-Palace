#ifndef ORDERSERVICES_H
#define ORDERSERVICES_H
#include "OrderRepository.h"
#include <iostream>

using namespace std;
class OrderServices
{
    public:
        OrderServices();
        void SaveOrder(const Order& order);
        ~OrderServices();


    private:
        OrderRepository order_repo;
};

#endif // ORDERSERVICES_H
