#ifndef INVALIDFILENOTOPENEXCEPTION_H
#define INVALIDFILENOTOPENEXCEPTION_H
#include <string>
using namespace std;


class InvalidFileNotOpenException
{
    public:
        InvalidFileNotOpenException();
        string get_message;

    private:
        string _message;
};

#endif // INVALIDFILENOTOPENEXCEPTION_H
