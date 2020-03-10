#include <iostream>
#include <vector> // Must include vector library to use vectors
using namespace std;

int main()
{
    vector<int> userInts; // A vector to hold the user's input integers

    /* Type your code here. */
    int userInput;

    cout << "Please enter a list of integers (You can stop by inputting '-1'):" << endl;
    do{
        cin >> userInput;
        if(userInput != -1)
        {
            userInts.push_back(userInput);
        }

    } while(userInput != -1);

    cout << "Old vector: ";
    for(int i = 0; i < userInts.size(); i++)
        cout << userInts[i] << " ";

    cout << "\nNew vector: ";
    vector<int> newInts;
    for(int i = 0; i < userInts.size(); i++)
    {
        int temp = userInts[userInts.size()-1-i];
        newInts.push_back(temp);
        cout << newInts[i] << " ";
    }

    return 0;
}
