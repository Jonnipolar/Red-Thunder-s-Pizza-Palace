#include "InvalidNameException.h"

InvalidNameException::InvalidNameException()
{
    _message = "Name of item cannot be more that 20 letters, nor can there be no name.\n";
}

string InvalidNameException::get_message()
{
    return _message;
}
