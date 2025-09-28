#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;
    int b[m];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int c[n + m]; // arr c which hold two arrays elemetns
    // taking all the elements of arr a
    for (int i = 0; i < n; i++)
        c[i] = a[i];
    // taking all the elements from arr b
    for (int i = 0; i < m; i++)
        c[i + n] = b[i];

    for (int i = 0; i < n + m; i++)
        cout << c[i] << " ";

    return 0;
}