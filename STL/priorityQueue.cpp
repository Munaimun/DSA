// for pop and push function in priority queue, TC is O(logn). bcoz ultimately this is a tree

#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> q;

    q.push(2);
    q.push(5);
    q.push(3);
    q.push(6);
    q.push(23);
    q.push(22);

    cout << "q1: ";
    // in priority queue, highest value by default gets most priority. that's why it will show in sorted order
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }

    cout << "\n";

    // declaration syntax for reverse order
    priority_queue<int, vector<int>, greater<int>> q2;

    q2.push(5);
    q2.push(3);
    q2.push(6);
    q2.push(2);
    q2.push(23);
    q2.push(22);

    cout << "q2: ";
    // in priority queue, highest value by default gets most priority. that's why it will show in sorted order
    while (!q2.empty())
    {
        cout << q2.top() << " ";
        q2.pop();
    }
}