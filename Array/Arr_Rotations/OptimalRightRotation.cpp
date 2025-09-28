// TC: O(n)
// SC: O(1) as we create no other space, just roatating the main array

#include <bits/stdc++.h>
using namespace std;

// helper function to reverse array
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

    reverse(k - 1, n - 1, a);
    reverse(0, k - 2, a);
    reverse(0, n - 1, a);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}