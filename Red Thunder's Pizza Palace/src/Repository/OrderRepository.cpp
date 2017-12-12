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
vector <Order> OrderRepository::get_order() {
    vector <Order> orders;
    ifstream fin("Orders.txt");



    return orders;
}
OrderRepository::~OrderRepository()
{
}
