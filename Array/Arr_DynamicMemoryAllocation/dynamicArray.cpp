// Time Complexity: O(n)
// - Initializing array 'a' takes O(n)
// - Copying elements from 'a' to 'b' takes O(n)
// - Printing n + 5 elements takes O(n) as well (since n is a constant offset)
// Overall: O(n)

// Space Complexity: O(n + 5) ≈ O(n)
// - Array 'a' takes O(n) space
// - Array 'b' takes O(n + 5) space, which is still linear in terms of n
// Overall: O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;

    // Dynamically allocate array 'a' of size n
    int *a = new int[n];

    // Initialize array 'a' with values 0 to n-1
    for (int i = 0; i < n; i++)
        a[i] = i;

    // Allocate a new, larger dynamic array 'b' of size n + 5
    int *b = new int[n + 5];

    // Copy all values from 'a' to 'b'
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    // Output all n + 5 elements of array 'b'
    // Note: the extra 5 elements contain garbage values (uninitialized)
    for (int i = 0; i < n + 5; i++)
        cout << b[i] << " ";

    // Free memory allocated for array 'a' since it's no longer needed
    delete[] a;

    return 0;
}
