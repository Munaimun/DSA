#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "Hello";
    string s2 = "World";

    string s3 = s1 + " " + s2; // concatenate(which we can't do in char arr)

    cout << s3 << endl;

    string str;

    getline(cin, str); // function to take input with space

    cout << str << endl;
    return 0;
}