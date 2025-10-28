// Problem: Perform Topological Sort on a directed graph using Kahn's Algorithm (BFS approach)
// Topological Sort is a linear ordering of vertices such that for every directed edge u -> v, u comes before v in the ordering.

// Time Complexity (TC):
//   - Reading edges and building adjacency list & inDegree: O(m) average
//   - BFS traversal of nodes and edges: O(n + m)
//   => Overall TC = O(n + m) (using unordered_map & unordered_set)
//
// Space Complexity (SC):
//   - Adjacency list: O(n + m)
//   - inDegree map: O(n)
//   - nodes unordered_set: O(n)
//   - queue and topo vector: O(n)
//   => Overall SC = O(n + m)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    // ADJACENCY LIST: store outgoing edges from each node
    map<string, vector<string>> adj;

    // inDegree: number of incoming edges for each node
    map<string, int> inDegree;

    // nodes: store all unique nodes (sources, destinations, or isolated)
    unordered_set<string> nodes;

    // Read edges and build adjacency list & inDegree map
    for (int i = 0; i < m; i++)
    {
        string u, v;
        cin >> u >> v;      // read edge u -> v

        adj[u].push_back(v); // u has an outgoing edge to v
        inDegree[v]++;       // increase inDegree for v (v has one more parent)
        nodes.insert(u);     // make sure u is tracked as a node
        nodes.insert(v);     // make sure v is tracked as a node
    }

    cout << endl;

    // PRINT ADJACENCY LIST for learning
    cout << "Adjacency List:\n";
    for (auto &it : adj)
    {
        cout << it.first << " -> ";
        for (auto &nbr : it.second)
        {
            cout << nbr << " ";  // show neighbors of current node
        }
        cout << endl;
    }

    cout << endl;

    // PRINT INITIAL indegree values for each node
    cout << "Initial inDegree values:\n";
    for (auto &it : nodes)
    {
        cout << it << ": " << inDegree[it] << endl;  // if node not in map, default is 0
    }

    cout << endl;

    // QUEUE for nodes with indegree 0 (nodes with no dependencies)
    queue<string> q;
    for (auto u : nodes)
    {
        if (inDegree[u] == 0)  // if no parent, ready to process
            q.push(u);
    }

    // VECTOR to store the topological order
    vector<string> topo;

    // KAHN'S ALGORITHM: BFS approach
    while (!q.empty())
    {
        string u = q.front();  // pick a node with indegree 0
        q.pop();
        topo.push_back(u);     // add it to the topological order

        // For all neighbors of u, reduce their indegree
        for (auto v : adj[u])
        {
            inDegree[v]--;      // one parent processed, reduce dependency

            // If neighbor now has indegree 0, push to queue
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    // PRINT FINAL TOPOLOGICAL ORDER
    cout << "Topological Order: ";
    for (auto &x : topo)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
Example Graph for Learning (input format):
6 6           // 6 nodes, 6 edges
A B           // edge A -> B
A C           // edge A -> C
B D           // edge B -> D
C D           // edge C -> D
D E           // edge D -> E
E F           // edge E -> F

Learning Notes:
- Nodes with inDegree 0 can be processed first (A in this example).
- When a node is processed, it reduces inDegree of its neighbors.
- Neighbor enters queue only when all its parents are processed (inDegree becomes 0).
- Topological order is not necessarily unique; depends on the order of nodes in the queue.
- Using `nodes` set ensures we include nodes without incoming or outgoing edges.
*/

// 6 7
// Nasta Office
// Suit Office
// Office Email
// Meeting Home
// Office Meeting
// Email Home
// Home Dinner
