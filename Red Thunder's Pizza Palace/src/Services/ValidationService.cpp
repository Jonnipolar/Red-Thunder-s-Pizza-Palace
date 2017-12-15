#include "ValidationService.h"

unsigned int ValidationService::get_integer_input_variable_size(string input_input, unsigned int size) throw (InvalidMenuNumberException)   //skilar int eftir s
{
    unsigned int input;
        stringstream push_input(input_input);
        push_input >> input;
        if(input > size || input <1 || input_input.empty()) {
            throw InvalidMenuNumberException();
        }
        for(unsigned int i = 0; i < input_input.length(); i++) {
            if(!isdigit(input_input[i])) {      // because of this (see above)
                throw InvalidMenuNumberException();
            } else {};
        }
    return input;
}
unsigned int ValidationService::get_price(string price_input) throw (InvalidPriceException)
{
    unsigned int price;
    for(unsigned int i = 0; i < price_input.length(); i++) {
        if(!isdigit(price_input[i])) {
            throw InvalidPriceException();
        } else {};
    }
    if(price_input.empty()) {                                                        // passar ad madur slai eitthvad inn
        throw InvalidPriceException();
    }
    stringstream push_price(price_input);
    push_price >> price;
    return price;
}
string ValidationService::get_name(string name) throw (InvalidNameException)
{
            if(name.length() > 20 || isspace(name[0])) {
                throw InvalidNameException();
            } else {};
            if(name.empty()) {
                throw InvalidNameException();
            }
    return name;
}
unsigned int ValidationService::get_integer_input_variable_size_with_zero_excep(string input_input, unsigned int size) throw (InvalidMenuNumberException)   //skilar int eftir s
{
    unsigned int input;
        stringstream push_input(input_input);
        push_input >> input;
        if(input > size || input <0 || input_input.empty()) {
            throw InvalidMenuNumberException();
        }
        for(unsigned int i = 0; i < input_input.length(); i++) {
            if(!isdigit(input_input[i])) {      // because of this (see above)
                throw InvalidMenuNumberException();
            } else {};
        }
    return input;
}
