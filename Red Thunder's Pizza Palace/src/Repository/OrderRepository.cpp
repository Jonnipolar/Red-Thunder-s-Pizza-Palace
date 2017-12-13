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
    vector <Toppings> Topping;
    vector <OtherProducts> Other_prod;
    string Price;
    string OrderTime;
    string TypeOfDelivery;
    string HasBeenPaidFor;
    PizzaPlace OrderLocation;
    string OrderStatus;
    string comment;
    string pizzas;
    string other_prod;
    string orderLoc;
    string pizza_name;
    string pizza_size;
    string pizza_bottom;
    string pizza_toppings;
    char delim = '|';
    if (fin.is_open()) {
        string str;
        while (getline(fin, str)) {
            string parse = "";
            int first_index = str.find(delim);
            int second_index = str.find(delim, first_index + 1);
            int third_index = str.find(delim, second_index + 1);
            int fourth_index = str.find(delim, third_index + 1);
            int fifth_index = str.find(delim, fourth_index + 1);
            int sixth_index = str.find(delim, fifth_index + 1);
            int seventh_index = str.find(delim, sixth_index + 1);
            int eigth_index = str.find(delim, seventh_index + 1);
            int ninth_index = str.find(delim, eigth_index + 1);
            int tenth_index = str.find(delim, ninth_index + 1);
            int eleventh_index = str.find(delim, tenth_index + 1);
            NameOfPerson = str.substr(0,first_index);
            pizzas = str.substr(first_index + 1, (second_index - 1) - first_index);
            other_prod = str.substr(second_index + 1, (third_index - 1) - second_index);
            OrderTime = str.substr(third_index + 1, (fourth_index - 1) - third_index);
            Price = str.substr(fourth_index + 1, (fifth_index - 1) - fourth_index);
            TypeOfDelivery = str.substr(sixth_index + 1, (seventh_index - 1) - sixth_index);
            HasBeenPaidFor = str.substr(seventh_index + 1, (eigth_index - 1) - seventh_index);
            orderLoc = str.substr(eigth_index + 1, (ninth_index - 1) - eigth_index);
            OrderStatus = str.substr(ninth_index + 1, (tenth_index - 1) - ninth_index);
            comment = str.substr(tenth_index + 1, (eleventh_index - 1) - tenth_index);
            int price_total = atoi(Price.c_str());
            while(0 != pizzas.size()){
                first_index = pizzas.find(';');
                second_index = pizzas.find(';', first_index + 1);
                third_index = pizzas.find(';', second_index + 1);
                fourth_index = pizzas.find(';', third_index + 1);
                pizza_name = pizzas.substr(0, first_index);
                pizza_size = pizzas.substr(first_index + 1, (second_index - 1) - first_index);
                pizza_bottom = pizzas.substr(second_index + 1, (third_index - 1) - second_index);
                pizza_toppings = pizzas.substr(third_index + 1, (fourth_index - 1) - third_index);
                int k = (pizza_name.size() + pizza_size.size() + pizza_bottom.size() + pizza_toppings.size() + 4);
                PizzaSize Pizza_size(pizza_size, 0);
                PizzaBottom Pizza_bottom(pizza_bottom, 0);
                for(unsigned int i = 0; i < pizza_toppings.size();i++) {
                    if(pizza_toppings[i] == ',') {
                        Toppings _topping(parse,0,0);
                        Topping.push_back(_topping);
                        parse = "";
                    }else{
                        parse += pizza_toppings[i];
                    }
                    if(i == (pizza_toppings.size()-1)){
                        Toppings _topping(parse,0,0);
                        Topping.push_back(_topping);
                        parse = "";
                    }
                }
                Pizza Pizz(pizza_name, 0, Topping, Pizza_bottom, Pizza_size);
                Pizzas.push_back(Pizz);
                pizzas.erase(0,k);
                Topping.clear();
            }
            for(unsigned int i = 0; i < other_prod.size();i++) {
                if(other_prod[i] == ';') {
                    OtherProducts other_products(parse,0,0);
                    Other_prod.push_back(other_products);
                    parse = "";
                }else{
                    parse += other_prod[i];
                }
                if(i == (other_prod.size()-1)){
                    OtherProducts other_products(parse,0,0);
                    Other_prod.push_back(other_products);
                    parse = "";
                }
            }
            Order order(NameOfPerson, Pizzas, Other_prod, OrderTime, price_total, TypeOfDelivery, HasBeenPaidFor, OrderLocation, OrderStatus, comment);
            Other_prod.clear();
            Pizzas.clear();
            orders.push_back(order);
        }
        fin.close();
    }


    return orders;
}
OrderRepository::~OrderRepository()
{
}
