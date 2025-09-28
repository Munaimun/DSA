#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){

    if(n==0 || n==1) return true;

    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}

int main() {
    int arr[]={1,2,3,4,5,6,7};
    
    cout<<isSorted(arr, 7)<<endl;

    return 0;
}