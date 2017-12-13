#include "OrderServices.h"

OrderServices::OrderServices()
{

}
void OrderServices::SaveOrder(const Order& order) {
    vector <Order> orders = get_processing_orders();
    orders.push_back(order);
    order_repo.store_order(orders);
}
vector <Order> OrderServices::get_orders() {
    vector <Order> orders = order_repo.get_order();
    return orders;
}
vector <Order> OrderServices::get_processing_orders() {
    vector <Order> orders = get_orders();
    vector <Order> process_orders;
    for(unsigned int i = 0; i < orders.size(); i++) {
        if(orders[i].get_orderStatus() == "Processing") {
            process_orders.push_back(orders[i]);
        }
    }
    return process_orders;
}
OrderServices::~OrderServices()
{

}
