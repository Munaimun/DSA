#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(14);

    for (auto val : s)
        cout << val << " ";

    cout << "\n";

    // multi set can hold multiple same values in ascending order
    multiset<int> s2;
    s2.insert(14);
    s2.insert(14);
    s2.insert(14);
    s2.insert(1);
    s2.insert(1);
    s2.insert(2);
    s2.insert(3);

    for (auto val : s2)
        cout << val << " ";

    cout << "\n";

    // hold in unordered way and can't hold same values
    unordered_set<int> s3;

    s3.insert(14);
    s3.insert(14);
    s3.insert(14);
    s3.insert(1);
    s3.insert(1);
    s3.insert(2);
    s3.insert(3);

    for (auto val : s3)
        cout << val << " ";
}