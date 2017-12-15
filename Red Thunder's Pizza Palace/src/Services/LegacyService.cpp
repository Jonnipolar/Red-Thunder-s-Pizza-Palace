#include "LegacyService.h"

LegacyService::LegacyService()
{
    //ctor
}
void LegacyService::save_order(Order& order) throw (InvalidFileNotOpenException){
    legacy_repo.store_order(order);
}
vector <Order> LegacyService::get_order() throw (InvalidFileNotOpenException){
    vector <Order> order = legacy_repo.get_order();
    return order;
}
void LegacyService::change_status(int sel, vector <Order> orders) throw (InvalidFileNotOpenException){
        Order order = orders[sel-1];
        order.set_orderStatus("Checked Out");
        order.set_HasBeenPaidFor("Paid");
        save_order(order);
}
LegacyService::~LegacyService()
{
    //dtor
}
