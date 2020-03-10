#include <iostream>
using namespace std;

// Type your code here
void RotateRight3(int &n1, int &n2, int &n3)
{
    int temp;

    temp = n1;
    n1 = n3;
    n3 = temp;

    temp = n3;
    n3 = n2;
    n2 = temp;

    return;
}

int main()
{
    int n1, n2, n3;

    cin >> n1;
    cin >> n2;
    cin >> n3;

    RotateRight3(n1, n2, n3);

    cout << n1 << " " << n2 << " " << n3 << endl;

    return 0;
}