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
        void change_paid_status(int select, string street);
        void change_proc_to_inPro(int select, string street);
        void change_inPro_to_Done(int select, string street);
        vector <Order> get_orders(int sel);
        vector <Order> get_processing_orders_by_street(string street);
        vector <Order> get_in_progress_orders_by_street(string street);
        vector <Order> get_done_orders_by_street(string street);
        vector <Order> get_all_orders_by_street(string street);
        vector <Order> get_processing_orders_by_not_street(string street);
        vector <Order> get_in_progress_orders_by_not_street(string street);
        vector <Order> get_done_orders_by_not_street(string street);
        vector <Order> get_all_orders_by_not_street(string street);
        vector <Order> get_all_in_pro();
        vector <Order> get_all_in_done();
        void set_done_orders(vector <Order> order, int sel);
        ~OrderServices();


    private:
        OrderRepository order_repo;
};

#endif // ORDERSERVICES_H
