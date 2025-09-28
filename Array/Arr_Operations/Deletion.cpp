// TC: O(n)
// SP: O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    // taking all the elements
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // taking index to delete the element
    int x;
    cin >> x;

    for (int i = x; i < n - 1; i++)
        a[i] = a[i + 1];

    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";

    return 0;
}