#ifndef ORDERSERVICES_H
#define ORDERSERVICES_H
#include <iostream>
#include "OrderRepository.h"

using namespace std;
class OrderServices
{
    public:
        OrderServices();
        ///Save order to text file
        void SaveOrder(const Order& order);
        ///Change order's status to paid
        void change_paid_status(int select, string street);
        ///Change order from 'processing' to 'in progress' (Is in oven or being done)
        void change_proc_to_inPro(int select, string street);
        ///Change order from 'in progress' to 'Done'
        void change_inPro_to_Done(int select, string street);
        ///Get Orders from text file
        vector <Order> get_orders(int sel);
        ///Get all 'Processing' orders by street
        vector <Order> get_processing_orders_by_street(string street);
        ///Get all 'In Progress' orders by street
        vector <Order> get_in_progress_orders_by_street(string street);
        ///Get all 'Done' orders by street
        vector <Order> get_done_orders_by_street(string street);
        ///Get all orders by street
        vector <Order> get_all_orders_by_street(string street);
        ///Get all 'Processing' orders that are not on specified street
        vector <Order> get_processing_orders_by_not_street(string street);
        ///Get all 'In Progress' orders that are not on specified street
        vector <Order> get_in_progress_orders_by_not_street(string street);
        ///Get all 'Done' orders that are not on specified street
        vector <Order> get_done_orders_by_not_street(string street);
        ///Get all orders that are not on specified street
        vector <Order> get_all_orders_by_not_street(string street);
        ///Get all 'In Progress' orders
        vector <Order> get_all_in_pro();
        ///Get all 'Done' orders
        vector <Order> get_all_in_done();
        ///Set order to Done
        void set_done_orders(vector <Order> order, int sel);
        ~OrderServices();


    private:
        OrderRepository order_repo;
};

#endif // ORDERSERVICES_H
