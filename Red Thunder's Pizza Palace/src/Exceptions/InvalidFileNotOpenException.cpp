#include "InvalidFileNotOpenException.h"

InvalidFileNotOpenException::InvalidFileNotOpenException()
{
    _message = "A problem came up while accessing the appropriate file.\n"
            "Please contact a system administrator.\n";
}

string InvalidFileNotOpenException::get_message()
{
    return _message;
}
