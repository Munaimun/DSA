#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d = {1, 2, 3, 4, 5, 6};

    d.push_back(22);   // push element at the end
    d.push_front(8);   // push element at the begining
    d.push_front(89);  // push element at the begining
    d.push_front(85);  // push element at the begining
    d.push_front(845); // push element at the begining

    d.pop_front(); // remove element from the begining

    for (auto i = d.begin(); i != d.end(); i++)
        cout << *i << " ";
}