// Time Complexity: O(n)
// Space Complexity: O(n) because a new array 'ans' of size n is created

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // taking the input of ration time
    int k;
    cin >> k;

    int ans[n];
    for (int i = 0; i < n; i++)
    {
        int newInd = (i + k) % n;
        ans[newInd] = a[i];
    }

    // Calculate the new index for each element after rotating left by k positions
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}