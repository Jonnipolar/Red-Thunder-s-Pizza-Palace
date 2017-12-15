#ifndef LEGACYSERVICE_H
#define LEGACYSERVICE_H
#include "LegacyRepo.h"
#include "OrderRepository.h"

using namespace std;

class LegacyService
{
    public:
        LegacyService();
        virtual ~LegacyService();
        ///send order to repo
        void save_order(Order& order) throw (InvalidFileNotOpenException);
        ///get order from repo
        vector <Order> get_order() throw (InvalidFileNotOpenException);
        ///change status to checked out
        void change_status(int sel, vector <Order> order) throw (InvalidFileNotOpenException);
    private:
        OrderRepository order_repo;
        LegacyRepo legacy_repo;
};

#endif // LEGACYSERVICE_H
