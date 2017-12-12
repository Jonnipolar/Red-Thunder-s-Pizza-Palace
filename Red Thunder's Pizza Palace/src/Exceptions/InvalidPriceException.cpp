#include "InvalidPriceException.h"

InvalidPriceException::InvalidPriceException()
{
    _message = "Price can only be number on integer form. Please try again.\n";
}

string InvalidPriceException::get_message()
{
    return _message;
}
