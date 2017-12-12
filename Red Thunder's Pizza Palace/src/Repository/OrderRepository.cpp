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
    string NameOfPerson;
    vector <Pizza> Pizzas;
    string Price;
    string OrderTime;
    string TypeOfDelivery;
    string HasBeenPaidFor;
    PizzaPlace OrderLocation;
    string OrderStatus;
    string comment;
    if (fin.is_open()) {
        string str;
        while (getline(fin, str)) {

        }
    }


    return orders;
}
OrderRepository::~OrderRepository()
{
}
