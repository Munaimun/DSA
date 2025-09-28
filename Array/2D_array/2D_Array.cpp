#include <bits/stdc++.h>
using namespace std;

// a funcrtion to find and element
bool findElement(int ar[2][3], int a)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ar[i][j] == a)
                return true;
        }
    }

    return false;
}

int main()
{
    // 2D array
    int a[2][3] = {{1, 2, 3}, {3, 4, 5}}; // 3row and 3 column
    int arr2[3][3];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // changing the value
    a[1][2] = 100;

    cout << findElement(a, 99) << endl;
    return 0;
}