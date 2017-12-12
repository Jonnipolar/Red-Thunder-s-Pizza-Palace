#ifndef INVALIDMENUNUMBEREXCEPTION_H
#define INVALIDMENUNUMBEREXCEPTION_H
#include <string>
using namespace std;
class InvalidMenuNumberException
{
public:
    InvalidMenuNumberException();

    string get_message();

    private:

    string _message;

};

#endif // INVALIDMENUNUMBEREXCEPTION_H
