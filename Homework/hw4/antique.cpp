#include "antique.h"
#include <iomanip>
#include <iostream>
using namespace std;

Antique::Antique(string n, float p)
{
    name = n;
    price = p;
}

void Antique::setName(string n)
{
    name = n;
}

void Antique::setPrice(float p)
{
    price = p;
}

const string Antique::getName()
{
    return name; 
}

float Antique::getPrice()
{
    return price;
}

void Antique::toString()
{
    cout << getName() << ": $" << setprecision(2) << price << endl; 
}