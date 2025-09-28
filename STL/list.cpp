// implemented as doubly linked list

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // declarations
    list<int> l;
    list<int> l2 = {1, 2, 3, 4, 5, 6};

    l.push_back(22);   // push element at the end
    l.push_front(8);   // push element at the begining
    l.push_front(89);  // push element at the begining
    l.push_front(85);  // push element at the begining
    l.push_front(845); // push element at the begining

    l.pop_front(); // remove element from the begining

    for (auto i = l2.begin(); i != l2.end(); i++)
        cout << *i << " ";
}