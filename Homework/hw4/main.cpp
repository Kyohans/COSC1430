#include "merchant.h"
#include <iostream>
#include <fstream>
#include <string>
#define size 10

using namespace std;

int main()
{
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
    cout << "Enter your budget: \n> ";
    cin >> budget;

    // Menu selection and execution
    int selection;
    while(selection != 4)
    {
        cout << "Make a selection:" << endl;
        cout << "1 - Haggle" << endl;
        cout << "2 - View menu" << endl;
        cout << "3 - Select an antique" << endl;
        cout << "4 - Leave" << endl;
        cout << "> ";
        cin >> selection;
        cout << endl;

        switch(selection)
        {
            case 1:
            {
                merchant.haggle();
                break;
            }
            case 2:
            {
                merchant.printMenu();
                break;
            }
            case 3:
            {
                merchant.selectAntique(antiques, quant, budget);
                break;
            }
            case 4:
            {
                merchant.leave(budget);
                break;
            }
            default:
            {
                cout << "Invalid option." << endl;
                break;
            }
        }
    }

    return 0;
}