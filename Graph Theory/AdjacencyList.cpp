#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[100];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto j : adjList[i])
            cout << j << ", ";
        cout << endl;
    }

    cout << endl;

    return 0;
}

/*
5 6
1 2
2 3
4 5
1 3
1 5
2 5
*/