#include <bits/stdc++.h>
using namespace std;

// Global adjacency matrix to store edges
// adjMat[i][j] = 1 if there is an edge between node i and node j
// Maximum size: 1000 x 1000
int adjMat[1000][1000]; // it will put 0 in every sell bcoz of being in global scope

int main() {
    int n, m; 
    cin >> n >> m; 
    // n = number of nodes (vertices)
    // m = number of edges

    // Reading m edges
    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;  
        // u and v are the two vertices that form an edge

        // Since this is an undirected graph, 
        // we mark both adjMat[u][v] and adjMat[v][u] as 1
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    // Printing the adjacency matrix
    // This shows the connectivity between nodes
    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    // Query section
    // User can keep entering pairs of nodes (u, v)
    // Program checks if an edge exists between u and v
    cout << "\nEnter node pairs to check edge existence (Ctrl+C to stop):\n";
    while (true) {
        int u, v; 
        cin >> u >> v;

        // If adjMat[u][v] is 1, edge exists
        if (adjMat[u][v] == 1) 
            cout << "Edge exists between " << u << " and " << v << "\n";
        else 
            cout << "No edge between " << u << " and " << v << "\n";
    }

    return 0;
}
