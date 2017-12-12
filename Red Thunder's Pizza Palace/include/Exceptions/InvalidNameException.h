#ifndef INVALIDNAMEEXCEPTION_H
#define INVALIDNAMEEXCEPTION_H
#include <string>
using namespace std;


class InvalidNameException
{
    public:
        InvalidNameException();
        string get_message();
    private:
        string _message;
};

#endif // INVALIDNAMEEXCEPTION_H
