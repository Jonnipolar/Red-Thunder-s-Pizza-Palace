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
void OrderServices::change_paid_status (int select, string street) {
    vector <Order> order = get_all_orders_by_street(street);
    vector <Order> other_order = get_all_orders_by_not_street(street);
    vector <Order> proc_order;
    vector <Order> prog_order;
    vector <Order> done_order;
    order[select-1].set_HasBeenPaidFor("Paid");
    for(unsigned int i = 0; i < order.size(); i++) {
        if(order[i].get_orderStatus() == "Processing") {
            proc_order.push_back(order[i]);
        }else if(order[i].get_orderStatus() == "In Progress") {
            prog_order.push_back(order[i]);
        }else if(order[i].get_orderStatus() == "Done") {
            done_order.push_back(order[i]);
        }
    }
    for(unsigned int i = 0; i < other_order.size(); i++) {
        if(other_order[i].get_orderStatus() == "Processing") {
            proc_order.push_back(other_order[i]);
        }else if(other_order[i].get_orderStatus() == "In Progress") {
            prog_order.push_back(other_order[i]);
        }else if(other_order[i].get_orderStatus() == "Done") {
            done_order.push_back(other_order[i]);
        }
    }
    order_repo.store_order(proc_order, 1);
    order_repo.store_order(prog_order, 2);
    order_repo.store_order(done_order, 3);
}
void OrderServices::change_proc_to_inPro(int select, string street){
    vector <Order> proc_order = get_processing_orders_by_street(street);
    vector <Order> proc_other_order = get_processing_orders_by_not_street(street);
    vector <Order> prog_order = get_in_progress_orders_by_street(street);
    vector <Order> prog_other_order = get_in_progress_orders_by_not_street(street);
    proc_order[select-1].set_orderStatus("In Progress");
    Order new_order = proc_order[select - 1];
    proc_order.erase(proc_order.begin() + select - 1);
    for ( unsigned int i = 0; i < proc_other_order.size(); i++ ) {
        proc_order.push_back(proc_other_order[i]);
    }
    for ( unsigned int i = 0; i < prog_other_order.size(); i++ ) {
        prog_order.push_back(proc_other_order[i]);
    }
    prog_order.push_back(new_order);
    order_repo.store_order(proc_order, 1);
    order_repo.store_order(prog_order, 2);
}
void OrderServices::change_inPro_to_Done(int select, string street){
    vector <Order> prog_order = get_in_progress_orders_by_street(street);
    vector <Order> prog_other_order = get_in_progress_orders_by_not_street(street);
    vector <Order> done_order = get_done_orders_by_street(street);
    vector <Order> done_other_order = get_done_orders_by_not_street(street);
    prog_order[select-1].set_orderStatus("In Progress");
    Order new_order = prog_order[select - 1];
    prog_order.erase(prog_order.begin() + select - 1);
    for ( unsigned int i = 0; i < prog_other_order.size(); i++ ) {
        prog_order.push_back(prog_other_order[i]);
    }
    for ( unsigned int i = 0; i < done_other_order.size(); i++ ) {
        done_order.push_back(done_other_order[i]);
    }
    done_order.push_back(new_order);
    order_repo.store_order(prog_order, 2);
    order_repo.store_order(done_order, 3);
}
vector <Order> OrderServices::get_all_in_pro() {
    return order_repo.get_order(2);
}
vector <Order> OrderServices::get_processing_orders_by_not_street(string street) {
    vector <Order> orders = get_orders(1);
    vector <Order> process_orders;
    for(unsigned int i = 0; i < orders.size(); i++) {
        PizzaPlace place = orders[i].get_OrderLocation();
        if(orders[i].get_orderStatus() == "Processing" && place.get_street() != street) {
            process_orders.push_back(orders[i]);
        }
    }
    return process_orders;
}
vector <Order> OrderServices::get_in_progress_orders_by_not_street(string street) {
    vector <Order> orders = get_orders(2);
    vector <Order> in_progress_orders;
    for(unsigned int i = 0; i < orders.size(); i++) {
        PizzaPlace place = orders[i].get_OrderLocation();
        if(orders[i].get_orderStatus() == "In Progress" && place.get_street() != street) {
            in_progress_orders.push_back(orders[i]);
        }
    }
    return in_progress_orders;
}
vector <Order> OrderServices::get_done_orders_by_not_street(string street) {
    vector <Order> orders = get_orders(3);
    vector <Order> done_orders;
    for(unsigned int i = 0; i < orders.size(); i++) {
        PizzaPlace place = orders[i].get_OrderLocation();
        if(orders[i].get_orderStatus() == "Done" && place.get_street() != street) {
            done_orders.push_back(orders[i]);
        }
    }
    return done_orders;
}
vector <Order> OrderServices::get_all_orders_by_not_street(string street) {
    vector <Order> processing_orders = get_processing_orders_by_not_street(street);
    vector <Order> in_progress_orders = get_in_progress_orders_by_not_street(street);
    vector <Order> done_orders = get_done_orders_by_not_street(street);
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
