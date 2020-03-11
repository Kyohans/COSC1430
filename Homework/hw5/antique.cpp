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
    Copy Constructor:
    Creates a new antique object with the same contents of another
*/
Antique::Antique(const Antique& baseAntique)
{
    name = baseAntique.name;
    price = baseAntique.price;
}

/*
    Addition Operator Overload:
    Combines two antique items together
*/
Antique Antique::operator+(Antique& rhs)
{
    Antique newAntique;
    newAntique.name = name;
    newAntique.price = price;
    ostringstream newName;
    
    newName << newAntique.name << " and " << rhs.name;
    newAntique.name = newName.str();
    newAntique.price = newAntique.price + rhs.price;
}

/*
    Antique Comparison:
    Compares the name and price of two antique objects
    Returns true if they are equivalent
*/
bool Antique::operator==(const Antique& rhs)
{
    Antique lhs;
    lhs.name = name;
    lhs.price = price;
    return (lhs.name == rhs.name && lhs.price == rhs.price);
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