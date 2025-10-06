// BFS with Grid traversal
// ------------------------------------------------------
// This program performs Breadth-First Search (BFS) on a
// 2D grid (matrix). Each '.' cell represents a free path,
// and '#' represents a blocked wall.
// The goal is to calculate the minimum distance (in steps)
// from a given starting cell to every reachable cell.
// ------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    // The grid layout:
    // '#' = wall (cannot go through)
    // '.' = open path (can move)
    vector<vector<char>> grid = {
        {'#', '.', '.', '#', '#'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#'},
        {'#', '#', '.', '.', '.'}
    };

    // Movement directions: up, down, right, left
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    int n = grid.size();       // total number of rows
    int m = grid[0].size();    // total number of columns

    // Level (distance) matrix initialized to -1
    // level[i][j] = distance from the starting cell (unvisited = -1)
    vector<vector<int>> level(n, vector<int>(m, -1));

    // Starting point (2,2) in 0-based indexing
    pair<int, int> s = {2, 2};

    // Standard BFS setup using a queue
    queue<pair<int, int>> q;
    q.push(s);
    level[s.first][s.second] = 0; // distance to itself = 0

    // BFS traversal
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        int x = u.first;
        int y = u.second;

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check bounds and ensure we only visit unvisited open cells
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                grid[nx][ny] == '.' && level[nx][ny] == -1) {
                
                // Set distance for this new cell
                level[nx][ny] = level[x][y] + 1;

                // Push this cell into the queue for further exploration
                q.push({nx, ny});
            }
        }
    }

    // Print the final distance (level) grid
    // -1 means unreachable or wall
    cout << "BFS Distance Grid:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << level[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
------------------------------------------------------
🧠 Learning Notes:

1. BFS works level by level — perfect for finding the
   shortest path in an unweighted grid.

2. The 'level' array keeps track of the distance
   from the starting point to every other reachable cell.

3. Queue ensures we always expand the nearest nodes first.

4. Direction arrays (dx, dy) make movement concise.

5. Time Complexity: O(N*M)
   - Each cell is processed at most once.

6. Space Complexity: O(N*M)
   - For the level grid and BFS queue.

7. Try changing the start cell or adding more walls
   to visualize how BFS explores the grid differently.
------------------------------------------------------
*/
