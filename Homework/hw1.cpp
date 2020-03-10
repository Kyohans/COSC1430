#include <iostream>     // Allows for user input
#include <iomanip>      // Allows us to format the user's money to 2 decimal places
using namespace std;

int main()
{
    int userInput;          // Holds user input
    double budget = 10.0;   // User's budget
    double credit = 0.0;    // Additional credit that is added to the budget
    double total = 0.0;     // Total cost of the user's order

    /* Main Menu (Will loop if the user inputs an invalid option) */
    while(userInput != 2)
    {
        cout << "Please select a menu item from the list below:" << endl;
        cout << "1 - View food menu" << endl;
        cout << "2 - Pay total due" << endl;
        cout << "3 - Add $5 in credit" << endl;
        cout << "4 - Clear order" << endl;
        cin >> userInput;
        cout << "> " << userInput << endl;

        // Input Validation
        while (userInput < 1 || userInput > 4)
        {
            cout << "\nERROR: Please select a valid option" << endl;
            cout << "Please select a menu item from the list below:" << endl;
            cout << "1 - View food menu" << endl;
            cout << "2 - Pay total due" << endl;
            cout << "3 - Add $5 in credit" << endl;
            cout << "4 - Clear order" << endl;
            cin >> userInput;
            cout << "> " << userInput << endl;
        }

    /* END OF MAIN MENU */


        /* This switch statement handles the options in the main menu. The user will be able to go back to the main menu when they input '6' */
        switch (userInput)
        {
            case 1: // Food menu
            {
                while (userInput != 6)
                {
                    cout << "What would you like to add to your order?" << endl;
                    cout << "(1) Chicken Sandwich: $3.45" << endl;
                    cout << "(2) Chicken Salad: $4.00" << endl;
                    cout << "(3) French Fries: $1.99" << endl;
                    cout << "(4) Hotdog: $2.99" << endl;
                    cout << "(5) Pizza: $3.99" << endl;
                    cout << "(6) Go to main menu" << endl;
                    std::cout << "Your current total is: $" << fixed << std::setprecision(2) << total << endl;
                    std::cout << "Your budget is $" << fixed << std::setprecision(2) << budget << " and your credits available is $" << fixed << std::setprecision(2) << credit << endl;
                    cin >> userInput;
                    cout << "> " << userInput << endl;

                    // Input validation
                    while(userInput < 1 || userInput > 6)
                    {
                        cout << "\nERROR: Please select a valid option!" << endl;
                        cout << "What would you like to add to your order?" << endl;
                        cout << "(1) Chicken Sandwich: $3.45" << endl;
                        cout << "(2) Chicken Salad: $4.00" << endl;
                        cout << "(3) French Fries: $1.99" << endl;
                        cout << "(4) Hotdog: $2.99" << endl;
                        cout << "(5) Pizza: $3.99" << endl;
                        cout << "(6) Go to main menu" << endl;
                        std::cout << "Your current total is: $" << fixed << std::setprecision(2) << total << endl;
                        std::cout << "Your budget is $" << fixed << std::setprecision(2) << budget << " and your credits available is $" << fixed << std::setprecision(2) << credit << endl;
                        cin >> userInput;
                        cout << "> " << userInput << endl;
                    }

                    // Adds item to user's total
                    switch(userInput)
                    {
                        case 1:
                        {
                            total += 3.45;
                            cout << "\nYou have added a Chicken Sandwich to your order" << endl;
                            break;
                        }
                        case 2:
                        {
                            total += 4.00;
                            cout << "\nYou have added a Chicken Salad to your order" << endl;
                            break;
                        }
                        case 3:
                        {
                            total += 1.99;
                            cout << "\nYou have added French Fries to your order" << endl;
                            break;
                        }
                        case 4:
                        {
                            total += 2.99;
                            cout << "\nYou have added a Hot Dog to your order" << endl;
                            break;
                        }
                        case 5:
                        {
                            total += 3.99;
                            cout << "\nYou have added Pizza to your order" << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 2: // Pay total amount
            {
                if((budget + credit) >= total)
                {
                    budget = (budget + credit) - total;
                    std::cout << "\nYour total amount due is $" << fixed << std::setprecision(2) << total << endl;
                    std::cout << "Thank you! Your change is $" << fixed << std::setprecision(2) << budget << endl;
                    cout << "Enjoy your meal!" << endl;
                    return 0;
                }
                else
                {
                    cout << "\nInsufficient funds! Exiting program..." << endl;
                    return 0;
                }
            }
            case 3: // Add $5 in credit
            {
                credit += 5.0;
                std::cout << "\nCredit available: $" << fixed << std::setprecision(2) << credit << endl;
                break;
            }
            case 4: // Clear order
            {
                total = 0.0;
                std::cout << "\nOrder has been cleared. Current due: $" << fixed << std::setprecision(2) << total << endl;
                break;
            }
            
        }
    }
    
}