#include "OrderServices.h"

OrderServices::OrderServices()
{

}
void OrderServices::SaveOrder(const Order& order) {
    order_repo.store_order(order);
}
OrderServices::~OrderServices()
{

}
