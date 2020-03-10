#include <iostream>
using namespace std;

int main()
{
    int max = 0;
    int arraySize;
    int userInput;

    cout << "Please declare the size of your array:" << endl;
    cin >> arraySize;

    int userArray[arraySize];
    int *arrayPtr = userArray;
    cout << "\nNow enter each value in the array and we will determine the max value:" << endl;

    for(int i = 0; i < arraySize; i++)
    {
        cout << "Number " << i+1 << ": ";
        cin >> userInput;
        *(arrayPtr+i) = userInput;

        if(arrayPtr[i] > arrayPtr[i-1])
        {
            max = arrayPtr[i];
        }
    }

    cout << "\nYour max value is " << max << endl;
}