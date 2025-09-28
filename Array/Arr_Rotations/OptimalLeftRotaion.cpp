// TC: O(n)
// SC: O(1) as we create no other space, just roatating the main array

#include <bits/stdc++.h>
using namespace std;

// helper function to reverse a subarray from i to j
void reverse(int i, int j, int a[])
{
    while (i < j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k;
    cin >> k;
    k %= n;

    // Rotate left by k using reversal algorithm
    reverse(0, k - 1, a); // reverse first part
    reverse(k, n - 1, a); // reverse second part
    reverse(0, n - 1, a); // reverse whole array

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
