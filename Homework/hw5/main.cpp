/*  
    Name: Khalyl Smith
    UH ID: 1894480
    Date: March 10th, 2020

    Overview: You have been greeted by a traveling sales merchant who is selling some wares. 
    You will have access to view the items he is selling and will be able to purchase his wares according to his prices.

    Simulates an antique shop using classes and objects
*/

#include "merchant.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define size 10

using namespace std;

int main()
{
    Antique t1("Car", 10);
    Antique t2("Bowl", 5);

    if(t1 == t2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not equal" << endl;
    }

    Antique t3(t1);
    if(t3 == t1)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not equal" << endl;
    }
    
    cout << "This is t3: " << t3.getName() << " " << t3.getPrice() << endl;

    cout << "Adding t1 and t2" << endl;
    Antique t4 = t1 + t2;
    cout << t4.getName() << endl;
    cout << fixed << setprecision(2) << t4.getPrice() << endl;
    
    Antique antiques[size];     // Array of Antique objects with size 10
    int quant[size];            // Antique quantity array that corresponds with the antiques array

    // Creates I/O File
    string filename;
    fstream file;
    cout << "Input filename: \n> ";
    cin >> filename;

    // Open new file. Terminates program if file is not found
    file.open(filename);
    if(file.fail())
    {
        cout << "File not found" << endl;
        return 0;
    }

    string setter;  // Used to acquire data from file
    for(int i = 0; i < size; i++)
    {
        // Set antiques name
        getline(file, setter, ',');
        antiques[i].setName(setter);

        // Set antiques price
        getline(file, setter, ',');
        antiques[i].setPrice(atof(setter.c_str()));

        // Set antiques quantity
        getline(file, setter);
        quant[i] = stoi(setter);
    }

    // Creates object from merchant class using antiques and quantity array
    Merchant merchant(antiques, quant);
    
    // Set user's budget
    float budget;
    cout << "Enter your budget: \n$";
    cin >> budget;
    cout << endl;

    // Menu selection and execution
    int selection;
    while(selection != 4)
    {
        cout << "Make a selection (You have $" << fixed << setprecision(2) << budget << "):" << endl;
        cout << "1 - Haggle" << endl;
        cout << "2 - View menu" << endl;
        cout << "3 - Select an antique" << endl;
        cout << "4 - Leave" << endl;
        cout << "> ";
        cin >> selection;
        cout << endl;

        switch(selection)
        {
            case 1: // Haggle (10% off all items)
            {
                merchant.haggle(antiques);
                break;
            }
            case 2: // View antique menu
            {
                merchant.printMenu(antiques);
                break;
            }
            case 3: // Select an antique to purchase
            {
                merchant.selectAntique(antiques, quant, budget);
                break;
            }
            case 4: // Leave shop
            {
                merchant.leave(budget);
                break;
            }
            default: // Default action
            {
                cout << "Invalid option." << endl;
                break;
            }
        }
    }

    return 0; 
}