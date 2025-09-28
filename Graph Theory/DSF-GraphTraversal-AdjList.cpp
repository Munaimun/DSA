#include <bits/stdc++.h>
using namespace std;

// GLOBAL ADJACENCY LIST - stores the graph
vector<int> adj[100];  // adj[i] contains all neighbors of node i

void dfs(int u, vector<bool>& isVisited)
{
    // Mark current node as visited
    isVisited[u] = true;
    cout << "Visiting node: " << u << endl;
    
    // Visit all unvisited neighbors of node u
    for (auto v : adj[u])  // For each neighbor v of node u
    {
        if (!isVisited[v])  // If neighbor v is not visited yet
        {
            cout << "  Going from " << u << " to " << v << endl;
            dfs(v, isVisited);  // Recursively visit neighbor v
        }
    }
    cout << "Finished exploring node: " << u << endl;
}

int main()
{
    // Example: Create a graph
    // Graph structure:
    //     0
    //    / \
    //   1   2
    //  /   / \
    // 3   4   5
    
    // Add edges (undirected graph)
    adj[0].push_back(1);  adj[1].push_back(0);  // Edge 0-1
    adj[0].push_back(2);  adj[2].push_back(0);  // Edge 0-2  
    adj[1].push_back(3);  adj[3].push_back(1);  // Edge 1-3
    adj[2].push_back(4);  adj[4].push_back(2);  // Edge 2-4
    adj[2].push_back(5);  adj[5].push_back(2);  // Edge 2-5
    
    cout << "Adjacency List Representation:\n";
    for (int i = 0; i < 6; i++) {
        cout << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    
    // Initialize visited array
    vector<bool> isVisited(6, false);
    
    cout << "\n=== DFS Traversal starting from node 0 ===\n";
    dfs(0, isVisited);
    
    return 0;
}

/*
DETAILED BREAKDOWN:

1. FUNCTION SIGNATURE:
   void dfs(int u, vector<bool>& isVisited)
   - u: current node we're visiting
   - isVisited: reference to visited array (tracks which nodes we've seen)

2. ADJACENCY LIST:
   vector<int> adj[100];
   - adj[i] = vector containing all neighbors of node i
   - Example: if adj[2] = {0, 4, 5}, then node 2 connects to nodes 0, 4, and 5

3. ALGORITHM STEPS:
   a) Mark current node u as visited
   b) For each neighbor v of node u:
      - If v is not visited, recursively call dfs(v)

4. HOW IT WORKS:
   
   Starting from node 0:
   
   dfs(0):
   ├── Mark 0 as visited
   ├── Check neighbors of 0: [1, 2]
   ├── Neighbor 1 not visited → call dfs(1)
   │   │
   │   └── dfs(1):
   │       ├── Mark 1 as visited  
   │       ├── Check neighbors of 1: [0, 3]
   │       ├── Neighbor 0 already visited → skip
   │       ├── Neighbor 3 not visited → call dfs(3)
   │       │   │
   │       │   └── dfs(3):
   │       │       ├── Mark 3 as visited
   │       │       ├── Check neighbors of 3: [1] 
   │       │       ├── Neighbor 1 already visited → skip
   │       │       └── Return (no more neighbors)
   │       └── Return (finished with node 1)
   │   
   ├── Neighbor 2 not visited → call dfs(2)
   │   └── dfs(2): ... (similar process)
   └── Return (finished with node 0)

5. KEY DIFFERENCES FROM GRID DFS:
   - Grid DFS: moves in 4 directions (up/down/left/right)
   - Graph DFS: visits neighbors from adjacency list
   - Grid DFS: checks bounds (nx < n, ny < m)  
   - Graph DFS: checks if neighbor exists in adjacency list

6. WHEN TO USE:
   - Finding connected components
   - Detecting cycles in graphs
   - Topological sorting
   - Path finding in graphs
   - Tree/graph traversals

EXAMPLE OUTPUT:
Adjacency List:
0: 1 2
1: 0 3  
2: 0 4 5
3: 1
4: 2
5: 2

DFS Traversal: 0 → 1 → 3 → 2 → 4 → 5
*/