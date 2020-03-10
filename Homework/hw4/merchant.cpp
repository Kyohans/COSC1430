#include "merchant.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#define size 10

bool flag = false; // Used to avoid the usage of the haggle function more than once

/* 
    Constructor:
    Assigns antique array, quantity array, and set merchant's revenue to 0
*/
Merchant::Merchant(Antique a[], int q[])
{
    revenue = 0;
}

/*
    Haggle:
    Sets every item on the menu to 10% off (Can only be used once)
*/
void Merchant::haggle(Antique a[])
{
    float discount;
    if(flag)
    {
        cout << "Sorry, you have already haggled" << endl;
        return;
    }

    for(int i = 0; i < size; i++)
    {
        discount = a[i].getPrice() - (a[i].getPrice() * 0.10);
        a[i].setPrice(discount);
    }
    cout << "You have successfully haggled and everything is 10% off" << endl;
    flag = true;
    return;
}

/*
    Print Menu:
    Prints information regarding antique number, name, and price
*/
void Merchant::printMenu(Antique a[])
{
    for(int i = 0; i < size; i++)
    {
        cout << i+1 << ") " << a[i].toString(); 
    }
    cout << endl;
}

/*
    Add To Revenue:
    Increases revenue to the amount of the sale made
*/
void Merchant::addRevenue(float rev)
{
    revenue += rev;
}

/*
    Get Revenue:
    Returns revenue amount
*/
float Merchant::getRevenue()
{
    return revenue;
}

/*
    Purchase Antique:
    Allows user to choose an antique to buy.
    Purchase is finalized if and only if said antique is in stock and the user has enough money in their budget
    Details about the sale is appended to log2.txt
*/
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

/*
    Leave:
    Appends the merchant's total revenue and remaining budget to log2.txt
    Terminates program after execution (in main)
*/
void Merchant::leave(float _budget)
{
    ofstream output;
    output.open("log2.txt", ios_base::app);

    cout << "Thank you for shopping!" << endl;
    output << "\nTotal revenue: $" << fixed << setprecision(2) << getRevenue() << endl;
    output << "Remaining budget: $" << fixed << setprecision(2) << _budget << "\n" << endl;
}
