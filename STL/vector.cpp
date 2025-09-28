// implemented as dynamic array

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec; // initially it holds nothing

    // other ways to decalre a vector
    vector<int> vec2 = {1, 2, 3, 4, 5}; // declaring the vector with values

    vector<int> vec3(3, 10); // the vector with size 3, and all the elements are 10

    vector<int> vec4(vec3); // vec4 is initialized with vec3
    //--------//

    // operations on vector
    vec.push_back(10);
    cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << endl;

    vec.push_back(20);
    cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << endl;

    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);
    vec.push_back(70);
    vec.push_back(80);
    vec.push_back(90);
    vec.push_back(95);
    vec.push_back(99);

    cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << endl;
    // the capacity gets double every time

    vec.pop_back();                              // it will delete the last element
    vec.erase(vec.begin());                      // erase the first element
    vec.erase(vec.begin() + 3);                  // erase the element at index 3 (begin=0(idx): 0+3=3)
    vec.erase(vec.begin() + 5, vec.begin() + 8); // erase the element at thsi range [start idx, end idx) end idx is excluded
    vec.insert(vec.begin() + 2, 100);            // insert a value. here: insert(idx, value to insert)

    // vec.clear(); // it will clear all the element, now the size will 0, but the capacity will be the same as before
    vec.empty(); // check wheather the vec is empty or not

    cout << "value at idx 2 by []: " << vec[2] << " value at idx 2 by at(): " << vec.at(2) << endl;
    cout << "Element at the front: " << vec.front() << " Element at the back: " << vec.back() << "\n";

    return 0;
}