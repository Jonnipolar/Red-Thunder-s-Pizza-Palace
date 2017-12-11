#ifndef INVALIDPRICEEXCEPTION_H
#define INVALIDPRICEEXCEPTION_H
#include <string>
using namespace std;

class InvalidPriceException
{
    public:
        InvalidPriceException();
        string get_message();

    protected:

    private:
        string _message;
};

#endif // INVALIDPRICEEXCEPTION_H
