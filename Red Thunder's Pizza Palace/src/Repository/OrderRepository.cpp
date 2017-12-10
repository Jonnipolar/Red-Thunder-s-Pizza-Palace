#include "OrderRepository.h"

OrderRepository::OrderRepository()
{
}
void OrderRepository::store_order(const Order& order) {
    ofstream fout;
    fout.open("Orders.txt", ios::app);
    if (fout.is_open()) {
        fout << order;
        fout.close();
    }
}
OrderRepository::~OrderRepository()
{
}
