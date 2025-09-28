#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Read number of nodes (n) and number of edges (m)
    int n, m;
    cin >> n >> m;

    // Create a vector to store all edges as pairs
    // Each pair represents a directed edge from first element to second element
    vector<pair<int, int>> edges;

    // Read m edges from input
    for (int i = 0; i < m; i++)
    {
        int u, v;  // u and v are the two nodes connected by an edge
        cin >> u >> v;

        // Since this is an undirected graph, we need to add both directions:
        // Edge from u to v
        edges.push_back(make_pair(u, v));
        // Edge from v to u (making it bidirectional)
        edges.push_back(make_pair(v, u));
    }

    // Print the adjacency list representation
    // For each node from 1 to n
    for (int i = 1; i <= n; i++)
    { 
        cout << i << ": ";  // Print current node number
        
        // Look through all edges to find ones starting from node i
        for (auto edge : edges)
        {
            if (edge.first == i)
            {                               // If this edge starts from node i
                cout << edge.second << " "; // Print the destination node
            }
        }
        cout << endl;  // Move to next line after printing all neighbors of node i
    }

    return 0;
}

/*
EXPLANATION:
This program creates and displays an adjacency list representation of an undirected graph.

Key Concepts:
1. Graph: A collection of nodes (vertices) connected by edges
2. Adjacency List: A way to represent a graph where for each node, 
   we store a list of all nodes it's directly connected to
3. Undirected Graph: Edges work both ways (if A connects to B, then B connects to A)

Example Input:
4 3
1 2
2 3
3 4

This represents a graph with 4 nodes and 3 edges:
- Node 1 connects to Node 2
- Node 2 connects to Node 3  
- Node 3 connects to Node 4

Example Output:
1: 2 
2: 1 3 
3: 2 4 
4: 3 

Time Complexity: O(n * m) where n is number of nodes and m is number of edges
Space Complexity: O(m) for storing all edges

Note: This implementation is simple but not the most efficient for large graphs.
A more efficient approach would use vector<vector<int>> adjacency list.
*/