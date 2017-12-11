#include "InvalidNameException.h"

InvalidNameException::InvalidNameException()
{
    _message = "Name of item cannot be more that 30 letters.\n";
}

string InvalidNameException::get_message()
{
    return _message;
}
