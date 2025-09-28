#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 54, 9, 5, 6, 7};

    cout << "Begin: " << *vec.begin() << endl;
    cout << "End: " << *vec.end() << endl; // indicates the idx after the last one

    // a vector iterator(loop)
    vector<int>::iterator i;
    for (i = vec.begin(); i != vec.end(); i++)
        cout << *i << " ";

    cout << "\n";

    // vector reverse iterator
    vector<int>::reverse_iterator j;
    for (j = vec.rbegin(); j != vec.rend(); j++)
        cout << *j << " ";

    // ANOTHER WAY TO DECALRE ITERATOR
    // compiler will know the type of i bcoz of auto
    for (auto i = vec.begin(); i != vec.end(); i++)
        cout
            << *i << " ";
}