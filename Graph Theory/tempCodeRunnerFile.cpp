#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr={1,2,6,7,9};
    
    for(int i=0; i<10; i++) cin>>arr[i];   // ✅ Now this works
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";
    
    return 0;
}