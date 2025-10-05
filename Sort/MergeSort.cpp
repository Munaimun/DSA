// Merge Sort Algorithm
// --------------------
// Concept:
// Merge Sort is a classic divide and conquer algorithm. 
// It divides the array into two halves, sorts each half recursively, 
// and then merges the sorted halves into a single sorted array.

// Time Complexity: O(n log n)
//   - Each level of recursion splits the array into two halves (log n levels).
//   - Each merge operation takes O(n) time.
//   - Therefore, total complexity = O(n log n).
//
// Space Complexity: O(n)
//   - Temporary array `temp[]` is used during merging for copying elements.

// Stable: YES (Maintains order of equal elements)
// In-place: NO (Uses extra memory for merging)

#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted halves of the array
void Merge(int arr[], int l, int mid, int r)
{
  int i = l;        // Pointer for left subarray
  int j = mid + 1;  // Pointer for right subarray
  int k = 0;        // Pointer for temp array
  int temp[r - l + 1]; // Temporary array to store merged result

  // Merge elements from both halves in sorted order
  while (i <= mid && j <= r)
  {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  // Copy remaining elements from left half (if any)
  while (i <= mid)
    temp[k++] = arr[i++];

  // Copy remaining elements from right half (if any)
  while (j <= r)
    temp[k++] = arr[j++];

  // Copy sorted elements from temp[] back to arr[]
  for (i = l, k = 0; i <= r; i++, k++)
    arr[i] = temp[k];
}

// Recursive function to divide the array and sort
void mergeSort(int arr[], int l, int r)
{
  if (l >= r)
    return;  // Base case: single element is already sorted

  int mid = (l + r) / 2;  // Find the middle point

  // Recursively sort the left half and right half
  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);

  // Merge the two sorted halves
  Merge(arr, l, mid, r);
}

int main()
{
  int arr[] = {4, 5, 1, 3, 2, 3, 10, 7};

  // Apply merge sort on the array
  mergeSort(arr, 0, 7);

  // Print sorted array
  for (int i = 0; i < 8; i++)
    cout << arr[i] << " ";

  cout << endl;
  return 0;
}
