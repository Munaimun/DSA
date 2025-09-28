// MAP is like a table which has [key: value] pairs

// 3 kinds of map is: Map, Multi Map, Unordered Map
// Multi Map can hold multiple key with same name
// Unordered map doesnt sort the pairs

#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> m;

    m["tv"] = "LG";
    m["AC"] = "General";
    m["Laptop"] = "Mac";

    // insertion in map
    m.insert({"watch", "Patek Phillipe"});

    for (auto p : m)
        cout << p.first << ": " << p.second << "\n";

    cout << "\n";
}