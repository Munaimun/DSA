#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[] = {3, -4, 5, 4, -1, 7, -8};

    int maxSum = 0;
    for (int st = 0; st < n; st++)
    {
        int curSum = 0;
        for (int end = st; end < n; end++)
        {
            curSum += arr[end];
            maxSum = max(maxSum, curSum);
        }
    }

    cout << maxSum << "\n";

    return 0;
}