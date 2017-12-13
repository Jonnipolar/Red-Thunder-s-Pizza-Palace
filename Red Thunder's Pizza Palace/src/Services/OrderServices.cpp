#include "OrderServices.h"

OrderServices::OrderServices()
{

}
void OrderServices::SaveOrder(const Order& order) {
    order_repo.store_order(order);
}
vector <Order> OrderServices::get_orders() {
    vector <Order> orders = order_repo.get_order();
    return orders;
}
OrderServices::~OrderServices()
{

}
