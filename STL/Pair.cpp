#include <bits/stdc++.h>
using namespace std;

int main()
{
    // declartions, it can be pair with any data types
    pair<int, char> p1 = {1, 'a'};
    pair<int, int> p2 = {54, 6};
    pair<string, int> std = {"Fahad", 7};
    pair<int, pair<int, int>> p3 = {5, {12, 98}};

    cout << p1.first << " " << p1.second << endl;
    cout << std.first << " " << std.second << endl;
    cout << p3.second.second << " ";

    vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};

    vec.push_back({4, 5});
    vec.emplace_back(5, 6); // in emplace back we dont need the curly brace

    for (auto p : vec)
        cout << p.first << " " << p.second << "\n";
}