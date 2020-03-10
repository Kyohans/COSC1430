#include "merchant.h"
#include <iostream>
#include <iomanip>
#define size 10

bool flag = false;

Merchant::Merchant(Antique a[], int q[])
{
    revenue = 0;
}

void Merchant::haggle()
{
    if(flag)
    {
        cout << "Sorry, you have already haggled" << endl;
        return;
    }

    for(int i = 0; i < 10; i++)
    {
        antiques[i].setPrice(antiques[i].getPrice * 0.10);
    }
    flag = true;
}

void Merchant::printMenu()
{
    for(int i = 0; i < size; i++)
    {
        cout << i << "} " << antiques[i].getName() << ": $" << std::setprecision(2) << antiques[i].getPrice() << endl;
    }
}

void selectAntique(Antique a[], int q[], float &budget)
{
    int aNum;
    cout << "Enter antique number: \n> ";
    cin >> aNum;

    if(q[aNum] == 0)
    {
        cout << "Sorry! Antique is out of stock." << endl;
        return;
    }
    else if(budget < a[aNum].getPrice())
    {
        cout << "Insufficient funds." << endl;
        return;
    }
    else
    {
        budget -= a[aNum].getPrice();
        //revenue += a[aNum].getPrice();
        
    }
    
}