#include "OrderServices.h"

OrderServices::OrderServices()
{

}
void OrderServices::SaveOrder(const Order& order) {
    vector <Order> orders = get_orders(1);
    orders.push_back(order);
    order_repo.store_order(orders, 1);
}
vector <Order> OrderServices::get_orders(int sel) {
    vector <Order> orders = order_repo.get_order(sel);
    return orders;
}
vector <Order> OrderServices::get_processing_orders_by_street(string street) {
    vector <Order> orders = get_orders(1);
    vector <Order> process_orders;
    for(unsigned int i = 0; i < orders.size(); i++) {
        PizzaPlace place = orders[i].get_OrderLocation();
        if(orders[i].get_orderStatus() == "Processing" && place.get_street() == street) {
            process_orders.push_back(orders[i]);
        }
    }
    return process_orders;
}
vector <Order> OrderServices::get_in_progress_orders_by_street(string street) {
    vector <Order> orders = get_orders(2);
    vector <Order> in_progress_orders;
    for(unsigned int i = 0; i < orders.size(); i++) {
        PizzaPlace place = orders[i].get_OrderLocation();
        if(orders[i].get_orderStatus() == "In Progress" && place.get_street() == street) {
            in_progress_orders.push_back(orders[i]);
        }
    }
    return in_progress_orders;
}
vector <Order> OrderServices::get_done_orders_by_street(string street) {
    vector <Order> orders = get_orders(3);
    vector <Order> done_orders;
    for(unsigned int i = 0; i < orders.size(); i++) {
        PizzaPlace place = orders[i].get_OrderLocation();
        if(orders[i].get_orderStatus() == "Done" && place.get_street() == street) {
            done_orders.push_back(orders[i]);
        }
    }
    return done_orders;
}
vector <Order> OrderServices::get_delivered_orders_by_street(string street) {
    vector <Order> orders = get_orders(4);
    vector <Order> delivered_orders;
    for(unsigned int i = 0; i < orders.size(); i++) {
        PizzaPlace place = orders[i].get_OrderLocation();
        if(orders[i].get_orderStatus() == "Delivered" && place.get_street() == street) {
            if(orders[i].get_HasBeenPaidFor() == "In Advance" || orders[i].get_HasBeenPaidFor() == "Paid") {
                delivered_orders.push_back(orders[i]);
            }
        }
    }
    return delivered_orders;
}
vector <Order> OrderServices::get_all_orders_by_street(string street) {
    vector <Order> processing_orders = get_processing_orders_by_street(street);
    vector <Order> in_progress_orders = get_in_progress_orders_by_street(street);
    vector <Order> done_orders = get_done_orders_by_street(street);
    vector <Order> all_orders;
    for(unsigned int i = 0; i < processing_orders.size(); i++) {
        all_orders.push_back(processing_orders[i]);
    }
    for(unsigned int i = 0; i < in_progress_orders.size(); i++) {
        all_orders.push_back(in_progress_orders[i]);
    }
    for(unsigned int i = 0; i < done_orders.size(); i++) {
        all_orders.push_back(done_orders[i]);
    }
    return all_orders;
}
OrderServices::~OrderServices()
{

}
