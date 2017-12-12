#include "InvalidMenuNumberException.h"

InvalidMenuNumberException::InvalidMenuNumberException()
{
    _message = "Invalid choice: Please select an option from the list. \n";

}

string InvalidMenuNumberException::get_message()
{
    return _message;
}
