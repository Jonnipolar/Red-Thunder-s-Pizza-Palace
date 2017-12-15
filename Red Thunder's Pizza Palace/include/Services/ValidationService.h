#ifndef VALIDATIONSERVICE_H
#define VALIDATIONSERVICE_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdlib.h>
#include <sstream>
#include "Pizza.h"
#include "PizzaPlace.h"
#include "PizzaService.h"
#include "MakeToppingsList.h"
#include "PizzaSizeService.h"
#include "MakePizzaBottomList.h"
#include "PizzaPlaceService.h"
#include "OtherProductsService.h"
#include "InvalidMenuNumberException.h"
#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "InvalidFileNotOpenException.h"

class ValidationService
{
    public:
        unsigned int get_integer_input_variable_size(string input_input, unsigned int size) throw (InvalidMenuNumberException);
        unsigned int get_price(string price_input) throw (InvalidPriceException);
        string get_name(string name) throw (InvalidNameException);
    private:
};

#endif // VALIDATIONSERVICE_H
