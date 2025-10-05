#include <bits/stdc++.h>
using namespace std;

// Direction arrays for moving in 4 directions: Down, Up, Right, Left
int dx[] = {1, -1, 0, 0};  // Change in x-coordinate (row)
int dy[] = {0, 0, 1, -1};  // Change in y-coordinate (column)

// DFS function to explore connected cells in a 2D grid
void dsf(int x, int y, int n, int m, vector<vector<bool>> &isVisited, vector<vector<int>> &grid)
{
    // Mark the current cell as visited
    isVisited[x][y] = 1;
    
    // Loop should run from i=0 to i<4 bcoz of 4 directions
    for(int i = 0; i < 4; i++){  // Should be 4, not n!
        
        // Calculate new coordinates by adding direction offsets
        int nx = x + dx[i];  // New x-coordinate (new row)
        int ny = y + dy[i];  // New y-coordinate (new column)
        
        // Check all boundary conditions and validity before moving
        if(nx >= 0 &&           // Not going above the grid (valid row)
           ny >= 0 &&           // Not going left of the grid (valid column)  
           nx < n &&            // Not going below the grid (within row bounds)
           ny < m &&            // Not going right of the grid (within column bounds)
           grid[nx][ny] == 1 && // Target cell contains 1 (valid cell to visit)
           !isVisited[nx][ny]   // Target cell hasn't been visited yet
          ){
            // Recursively explore the valid neighboring cell
            dsf(nx, ny, n, m, isVisited, grid);
        }
    }
}

int main()
{
    // Initialize a 4x4 grid with 1s and 0s
    // 1 = valid cell that can be visited
    // 0 = blocked cell that cannot be visited
    vector<vector<int>> grid = {
        {1, 1, 0, 1},  // Row 0: cells (0,0), (0,1) are connected
        {0, 1, 0, 1},  // Row 1: cell (1,1) connects to (0,1)
        {1, 1, 1, 0},  // Row 2: cells (2,0), (2,1), (2,2) form a component
        {1, 1, 0, 1}   // Row 3: cells (3,0), (3,1) connect to (2,0), (2,1)
    };
    
    // Get grid dimensions
    int n = grid.size();        // Number of rows = 4
    int m = grid[0].size();     // Number of columns = 4
    
    // Create a visited array to track which cells we've explored
    // Initialize all cells as unvisited (false/0)
    vector<vector<bool>> isVisited(n, vector<bool>(m, 0));
    
    // Start DFS from position (0,0) - top-left corner
    dsf(0, 0, n, m, isVisited, grid);
    
    
    
    return 0;
}

/*
LEARNING NOTES:

1. WHAT THIS CODE DOES:
   - Performs DFS traversal on a 2D grid starting from position (0,0)
   - Visits all connected cells containing value 1
   - Marks visited cells to avoid infinite loops

2. DIRECTION ARRAYS EXPLAINED:
   dx[] = {1, -1, 0, 0}  →  Down, Up, Stay, Stay
   dy[] = {0, 0, 1, -1}  →  Stay, Stay, Right, Left
   
   Combined movements:
   i=0: (x+1, y+0) = Move Down
   i=1: (x-1, y+0) = Move Up  
   i=2: (x+0, y+1) = Move Right
   i=3: (x+0, y-1) = Move Left

3. BOUNDARY CONDITIONS:
   - nx >= 0: Don't go above the grid
   - ny >= 0: Don't go left of the grid
   - nx < n:  Don't go below the grid  
   - ny < m:  Don't go right of the grid

4. VALID CELL CONDITIONS:
   - grid[nx][ny] == 1: Only visit cells with value 1
   - !isVisited[nx][ny]: Don't revisit already explored cells

5. APPLICATIONS:
   - Finding connected components in a grid
   - Flood fill algorithm
   - Finding islands in a matrix
   - Path finding in mazes
   - Region growing in image processing

6. TIME & SPACE COMPLEXITY:
   - Time: O(n × m) - visit each cell at most once
   - Space: O(n × m) - for visited array + recursion stack depth

*/