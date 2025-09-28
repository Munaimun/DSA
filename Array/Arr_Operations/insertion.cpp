// TC: O(N)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[n + 1];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int idx, val;
    cin >> idx >> val;

    for (int i = n - 1; i >= idx; i--)
    {
        a[i + 1] = a[i];
    }

    a[idx] = val;

    for (int i = 0; i <= n; i++)
        cout << a[i] << " ";
    ;
    return 0;
}