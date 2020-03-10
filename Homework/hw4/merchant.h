#ifndef MERCHANT_H
#define MERCHANT_H

#include "antique.h"

class Merchant
{
    private:
        Antique antiques[10];
        int quantities[10];
        float revenue;
    public:
        Merchant(Antique a[], int q[]);
        void haggle();
        void printMenu();
        void addRevenue(float rev);
        float getRevenue();
        void selectAntique(Antique a[], int q[], float &budget);
        void leave(float _budget);
};

#endif