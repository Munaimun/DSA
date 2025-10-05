// Quick Sort Algorithm
// --------------------
// Concept:
// Quick Sort is a Divide and Conquer algorithm. It picks a pivot element,
// partitions the array around that pivot so that elements smaller than the pivot
// come before it, and elements greater come after it. Then it recursively sorts
// the left and right parts.
//
// This version uses the last element as pivot (can be modified for random pivot).
//
// Time Complexity:
//   - Best Case: O(n log n)  → pivot divides array evenly
//   - Average Case: O(n log n)
//   - Worst Case: O(n²) → happens if pivot is always smallest/largest element
//
// Space Complexity: O(log n)
//   - Due to recursion stack (for in-place sorting, no extra array used)
//
// Stable: ❌ (order of equal elements is not guaranteed)
// In-place: ✅ (no significant extra space used)

#include <bits/stdc++.h>
using namespace std;

// Function to partition the array around a pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;        // Index of smaller element

    // Traverse through array and move smaller elements to left
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in its correct sorted position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive QuickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Sort the array using Quick Sort
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}