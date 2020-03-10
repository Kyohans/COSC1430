#include "antique.h"
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;

/*
    Constructor:
    Assigns name and price of antique
*/
Antique::Antique(string n, float p)
{
    name = n;
    price = p;
}

/*
    Set Name:
    Sets name of an antique
*/
void Antique::setName(string n)
{
    name = n;
}

/*
    Set Price:
    Sets price of an antique
*/
void Antique::setPrice(float p)
{
    price = p;
}

/*
    Get Name:
    Retrieves the name of an antique
*/
const string Antique::getName()
{
    return name; 
}

/*
    Get Price:
    Retrieves the price of an antique
*/
float Antique::getPrice()
{
    return price;
}

/*
    toString:
    Prints information about the antique such as the name and how much it costs
*/
const string Antique::toString()
{
    ostringstream output;
    output << getName() << ": $" << fixed << setprecision(2) << getPrice() << endl; 
    return output.str();
}