#include "antique.h"

using namespace std;

#ifndef MERCHANT_H
#define MERCHANT_H

class Merchant
{
    private:
        Antique *antiques = nullptr;
        int *quantity = nullptr;
        int numAnt = 0;
        float revenue;
    public:
        Merchant();
        Merchant(float rev);
        Merchant(const Merchant &copy);
        Merchant &operator=(const Merchant &rhs);
        bool operator==(const Merchant &rhs);
        void addAntique(const Antique &a, int q);
        ~Merchant();
};

#endif