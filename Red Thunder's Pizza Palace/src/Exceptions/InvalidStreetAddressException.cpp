#include "InvalidStreetAddressException.h"

InvalidStreetAddressException::InvalidStreetAddressException()
{
    _message = "Street names cannot be longer than 20 letters, nor be left empty.\n"
        "House numbers cannot contain punctuations nor be left empty, if there is only \n"
        "one house on the street you may write that.\n";
}

string InvalidStreetAddressException::get_message(){
    return _message;
}
