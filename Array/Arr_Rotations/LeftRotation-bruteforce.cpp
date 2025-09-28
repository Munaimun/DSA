// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    //  taking input the array elements
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Store the first element to place it at the end after left rotation
    int temp = a[0];

    // Shift all elements one position to the left
    for (int i = 1; i < n; i++)
        a[i - 1] = a[i];

    // Place the first element at the last position
    a[n - 1] = temp;

    // Output the rotated array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
