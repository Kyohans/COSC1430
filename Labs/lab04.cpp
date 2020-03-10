#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define MAX_SIZE 100

using namespace std;

void BubbleSort(int arr[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n - i - 1; ++j)
        {
            // Comparing consecutive data and switching values if value at j > j+1.
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{

    string filename;
    int *data = new int[MAX_SIZE];
    int count = 0;

    //Your solution here
    ifstream file;
    cout << "Input your filename:" << endl;
    cin >> filename;
    file.open(filename);

    if(file.fail())
    {
        cout << "File not found" << endl;
        return 0;
    }

    while(!file.eof())
    {
        file >> data[count];
        count++;
    }

    
    // Call the sort function here
    BubbleSort(data, count);

    for(int i=0;i<count;i++){
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
