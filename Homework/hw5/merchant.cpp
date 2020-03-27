#include "merchant.h"
#include <iostream>
#include <fstream>
#include <iomanip>

/* 
    Constructor:
    Set merchant's revenue to 0
*/
Merchant::Merchant()
{
    revenue = 0;
}

/*
    Copy Constructor:
    Creates a new Merchant object by copying another Merchant's data into the new one
*/
Merchant::Merchant(const Merchant &copy)
{
    numAnt = copy.numAnt;
    revenue = copy.revenue;
    antiques = new Antique[numAnt];
    quantity = new int[numAnt];

    for(int i = 0; i < numAnt; i++)
    {
        antiques[i] = copy.antiques[i];
        quantity[i] = copy.quantity[i];
    }
}

/*
    Constructor:
    Assigns a value to the merchant's revenue
*/
Merchant::Merchant(float rev)
{
    revenue = rev;
}

/*
    Merchant Comparison:
    Checks if two Merchant objects are equal
*/
bool Merchant::operator==(const Merchant &rhs)
{
    for(int i = 0; i < numAnt; i++)
    {
        if(this->quantity[i] != rhs.quantity[i])
        {
            return false;
        }
    }

    if((this->antiques != rhs.antiques) && (this->revenue != rhs.revenue))
    {
        return false;
    }

    return true;
}

/*
    Assignment Operator Overload:
    Deletes contents of a Merchant object and copies another Merchant object
*/
Merchant &Merchant::operator=(const Merchant &rhs)
{
    delete[] antiques;
    delete[] quantity;

    numAnt = rhs.numAnt;
    revenue = rhs.revenue;
    antiques = new Antique[numAnt];
    quantity = new int[numAnt];

    for (int i = 0; i < numAnt; i++)
    {
        antiques[i] = rhs.antiques[i];
        quantity[i] = rhs.quantity[i];
    }

    return *this;
}


/*
    Add Antique:
    Adds new antique to merchant's wares
    Takes an antique object and its quantity as arguments
*/
void Merchant::addAntique(const Antique &a, int q)
{
    numAnt = numAnt + 1;
    Antique *temp = new Antique[numAnt];
    int *quant = new int[numAnt];

    for(int i = 0; i < numAnt-1; i++)
    {
        temp[i] = antiques[i];
        quant[i] = quantity[i];
    }

    temp[numAnt-1] = a;
    if(antiques != nullptr)
        delete[] antiques;

    quant[numAnt-1] = q;
    if(quantity != nullptr)
        delete[] quantity;

    antiques = temp;
    quantity = quant;
}

/*
    Destructor:
    Deallocates memory when the Merchant object is no longer needed
*/
Merchant::~Merchant()
{
    delete[] antiques;
    delete[] quantity;
}
