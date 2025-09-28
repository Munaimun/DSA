// Time Complexity: O(n)
// Space Complexity: O(n) because a new array 'ans' of size n is created

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    // Input the array elements
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // taking the input of ration time
    int k;
    cin >> k;

    // Normalize k to ensure it's within bounds of array size
    k = k % n;

    // Create a new array to store the rotated result
    int ans[n];

    // Calculate the new index for each element after rotating left by k positions
    for (int i = 0; i < n; i++)
    {
        int newInd = (i + n - k) % n; // Shifting left by k is same as (i - k + n) % n
        ans[newInd] = a[i];
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}
