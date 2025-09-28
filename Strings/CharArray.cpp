#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[12];

    cout << "Enter you array: ";
    // parameters: s=char arr, len=100, '.'= delimeter-recognise when to stop taking input
    cin.getline(s, 12, '.');

    for (auto i : s)
        cout << s << ", ";

    return 0;
}