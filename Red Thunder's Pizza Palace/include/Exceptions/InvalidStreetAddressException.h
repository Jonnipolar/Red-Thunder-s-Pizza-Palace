#ifndef INVALIDSTREETADDRESSEXCEPTION_H
#define INVALIDSTREETADDRESSEXCEPTION_H
#include <string>
using namespace std;


class InvalidStreetAddressException
{
    public:
        InvalidStreetAddressException();
        string get_message();



    private:
        string _message;
};

#endif // INVALIDSTREETADDRESSEXCEPTION_H
