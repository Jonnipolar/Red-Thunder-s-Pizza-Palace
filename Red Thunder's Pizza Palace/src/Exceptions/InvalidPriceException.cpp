#include "InvalidPriceException.h"

InvalidPriceException::InvalidPriceException()
{
    _message = "Price can only be number on integer form. Please try again.\n";
    _messagenumber = "House number must be integer, if there is only one house, type zero (0)";
}

string InvalidPriceException::get_message()
{
    return _message;
}

string InvalidPriceException::get_messagenumber()
{
    return _messagenumber;
}
