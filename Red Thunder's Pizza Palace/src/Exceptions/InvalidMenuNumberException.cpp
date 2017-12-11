#include "InvalidMenuNumberException.h"

InvalidMenuNumberException::InvalidMenuNumberException()
{
    string _message = "Invalid choice: Please select an option from the list.";
}

string InvalidMenuNumberException::get_message()
{
    return _message;
}
