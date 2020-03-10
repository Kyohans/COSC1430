#include "merchant.h"
#include <iostream>
#include <fstream>
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

    for(int i = 0; i < size; i++)
    {
        antiques[i].setPrice(antiques[i].getPrice() * 0.10);
    }
    cout << "You have successfuly haggled and everything is 10% off" << endl;
    flag = true;
    return;
}

void Merchant::printMenu()
{
    for(int i = 0; i < size; i++)
    {
        cout << i+1 << ") "; 
        antiques[i].toString();
    }
}

void Merchant::addRevenue(float rev)
{
    revenue += rev;
}

float Merchant::getRevenue()
{
    return revenue;
}

void Merchant::selectAntique(Antique a[], int q[], float &budget)
{   
    ofstream receipt;
    receipt.open("log2.txt", ios_base::app);

    int aNum;
    cout << "Enter antique number: \n> ";
    cin >> aNum;

    while(aNum < 1 || aNum > 10)
    {
        cout << "Invalid antique number. Please try again: \n> " << endl;
        cin >> aNum;
    }

    if(q[aNum-1] == 0)
    {
        cout << "Sorry! Antique is out of stock." << endl;
        return;
    }
    else if(budget < a[aNum-1].getPrice())
    {
        cout << "Insufficient funds.\n" << endl;
        return;
    }
    else
    {
        cout << "Enjoy your " << a[aNum-1].getName() << "!\n" << endl;
        budget -= a[aNum-1].getPrice();
        q[aNum-1]--;
        addRevenue(a[aNum-1].getPrice());

        receipt << "Sold " << a[aNum-1].getName() << " for $" << fixed << setprecision(2) << a[aNum-1].getPrice() << endl;
    }
}

void Merchant::leave(float _budget)
{
    ofstream output;
    output.open("log2.txt", ios_base::app);

    cout << "Hehehehe, thank you" << endl;
    output << "\nTotal revenue: $" << fixed << setprecision(2) << getRevenue() << endl;
    output << "Remaining budget: $" << fixed << setprecision(2) << _budget << endl;
}
