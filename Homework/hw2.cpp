#include <iostream>
#include <string>
using namespace std;

int main()
{
    int rosterNum = 0;
    int userNum;
    string userString;
    char userChar;
    const int noOfKittens = 10;

    /* Initiliazing the arrays:
    We increment by 1 to accommodate the case where
    the user decides to delete a last kitten from a roster that is full
    */
    string catName[noOfKittens+1];
    string catColor[noOfKittens+1];
    int catScore[noOfKittens+1];

    cout << "Enter the following information for five kittens:" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "Enter kitten " << i+1 << "'s name:" << endl;
        cin >> userString;
        catName[i] = userString;

        cout << "Enter kitten " << i+1 << "'s color:" << endl;
        cin >> userString;
        catColor[i] = userString;

        cout << "Enter kitten " << i+1 << "'s cuteness score:" << endl;
        cin >> userNum;
        catScore[i] = userNum;

        rosterNum++;
    }

    // Prints roster
    cout << "\nROSTER: " << rosterNum << endl;
    for(int i = 0; i < rosterNum; i++)
    {
        cout << "Kitten " << i+1 << " -- Name: " << catName[i] << ", Color: " << catColor[i] << ", Score: " << catScore[i] << endl;
    }

    /* MENU - Loops until the user inputs 'q' (Checks for input validity) */
    while(userChar != 'q')
    {
        cout << "\nMENU" << endl;
        cout << "a - Add kitten" << endl;
        cout << "d - Remove kitten" << endl;
        cout << "u - Update kitten color and cuteness score" << endl;
        cout << "r - Output kittens above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl;
        cin >> userChar;

        switch(userChar)
        {
            case 'a': // Add kitten to roster
            {
                if(rosterNum == 10)
                {
                    cout << "ERROR: Kitten roster is full" << endl;
                }
                else
                {
                    for(int i = 0; i < noOfKittens; i++)
                    {
                        if(catName[i] == "\0")
                        {
                            cout << "Enter new kitten's name:" << endl;
                            cin >> userString;
                            catName[i] = userString;

                            cout << "Enter new kitten's color:" << endl;
                            cin >> userString;
                            catColor[i] = userString;

                            cout << "Enter new kitten's cuteness score:" << endl;
                            cin >> userNum;
                            catScore[i] = userNum;
                            
                            rosterNum++;
                            i = noOfKittens;
                        }
                    }
                }
                break;
            }
            case 'd': // Remove kitten to roster
            {
                if(rosterNum == 0)
                {
                    cout << "ERROR: Roster is empty" << endl;
                    break;
                }

                cout << "Enter a kitten's name (Case-sensitive):" << endl;
                cin >> userString;

                bool catFound = false;
                string tempStr;
                int pos;

                for(int i = 0; i < rosterNum; i++)
                {
                    if(catName[i] == userString)
                    {
                        catFound = true;
                        pos = i;
                        break;
                    }
                }

                if(!catFound)
                {
                    cout << "ERROR: Kitten " << userString << " not found!" << endl;
                    break;
                }
                else
                {
                    for(int i = pos; i < rosterNum; i++)
                    {
                        catName[i] = catName[i+1];
                        catColor[i] = catColor[i+1];
                        catScore[i] = catScore[i+1];
                    }
                }
                rosterNum--;
                break;
            }
            case 'u': // Update kitten color and cuteness score
            {
                int pos;
                bool catFound = false;
                cout << "Enter kitten's name (Case-sensitive):" << endl;
                cin >> userString;

                for(int i = 0; i < rosterNum; i++)
                {
                    if(catName[i] == userString)
                    {
                        pos = i;
                        catFound = true;
                        break;
                    }
                }

                if(!catFound)
                {
                    cout << "ERROR: Kitten " << userString << " not found!" << endl;
                    break;
                }

                cout << "Enter new color for " << userString << endl;
                cin >> catColor[pos];

                cout << "Enter new cuteness score for " << userString << endl;
                cin >> catScore[pos];
                break;
            }
            case 'r': // Output roster above rating
            {
                cout << "Enter rating:" << endl;
                cin >> userNum;

                cout << "\nABOVE " << userNum << ":" << endl;
                for(int i = 0; i < rosterNum; i++)
                {
                    if(catScore[i] >= userNum)
                    {
                        cout << "Kitten " << i + 1 << " -- Name: " << catName[i] << ", Color: " << catColor[i] << ", Score: " << catScore[i] << endl;
                    }
                }
                break;
            }
            case 'o': // Output roster
            {
                cout << "\nROSTER: " << rosterNum << endl;
                for (int i = 0; i < rosterNum; i++)
                {
                    if(catName[i] != "\0")
                    {
                         cout << "Kitten " << i + 1 << " -- Name: " << catName[i] << ", Color: " << catColor[i] << ", Score: " << catScore[i] << endl;
                    }
                }
                break;
            }
            case 'q': // Quit program
            {
                return 0;
                break;
            }
            case 's': // Easter egg! Sorts roster by cuteness score in descending order
            {
                cout << "Executing secret option!" << endl;
                int tempVal;
                string tempStr;

                for(int i = 0; i < rosterNum; i++)
                {
                    for(int j = i+1; j < rosterNum; j++)
                    {
                        if(catScore[i] < catScore[j])
                        {
                            tempVal = catScore[i];
                            catScore[i] = catScore[j];
                            catScore[j] = tempVal;

                            tempStr = catName[i];
                            catName[i] = catName[j];
                            catName[j] = tempStr;

                            tempStr = catColor[i];
                            catColor[i] = catColor[j];
                            catColor[j] = tempStr;
                        }
                    }
                }
                break;
            }
            default: // Input validation
            {
                cout << "ERROR: Invalid input, try again!" << endl;
                break;
            }
        }
    }
}