// TC: O(n)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Store the last element to place it at the start after right rotation
    int temp = a[n - 1];
    // Shift all elements one position to the right
    for (int i = n - 2; i >= 0; i--)
        a[i + 1] = a[i];
    // Place the last element at the first position
    a[0] = temp;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}