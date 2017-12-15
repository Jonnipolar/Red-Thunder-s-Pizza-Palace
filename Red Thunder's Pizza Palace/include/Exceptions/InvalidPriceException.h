#ifndef INVALIDPRICEEXCEPTION_H
#define INVALIDPRICEEXCEPTION_H
#include <string>
using namespace std;

class InvalidPriceException
{
    public:
        InvalidPriceException();
        string get_message();
        string get_messagenumber();

    protected:

    private:
        string _message;
        string _messagenumber;
};

#endif // INVALIDPRICEEXCEPTION_H
