#include <iostream>
using namespace std;

// Write your code here to implement the function below
void replace_nonalphnum_to_space(char s[], int size)
{
    char *sP = s;
    for(int i = 0; i < size; i++)
    {
        if(isalnum(s[i]))
        {
            cout << *(sP+i);
        }
        else
        {
            *(sP+i) = ' ';
            cout << *(sP+i);
        }
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of char array" << endl;
    cin >> size;

    char s[size];
    cout << "Enter elements of char array" << endl;
    
    for(int i = 0; i < size; i++)
    {
        cin >> s[i];
        while(isspace(s[i]))
        {
            cout << "You can not enter a space in your input array!" << endl;
            cin >> s[i];
        }
    }
    replace_nonalphnum_to_space(s, sizeof(s));
}