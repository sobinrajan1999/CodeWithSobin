//question : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description

class Solution {
public:
    // Direction vectors representing the possible moves (down-right, right, and up-right)
    vector<pair<int, int>> dir = {{-1, 1}, {0, 1}, {1, 1}};
    // Visited matrix to track the cells we have already processed
    vector<vector<bool>> visited;

    // Breadth-First Search (BFS) to find the maximum number of moves possible
    int bfs(vector<vector<int>>& grid) {
        int result = INT_MIN; // Variable to track the maximum moves
        int n = grid.size();  // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid
        
        // Initialize the visited matrix with false values
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        
        // Queue to hold the current position and move count
        queue<pair<pair<int, int>, int>> q;
        
        // Start BFS from the first column in every row
        for(int i = 0; i < n; i++) {
            q.push({{i, 0}, 0});
            visited[i][0] = true; // Mark starting cell as visited
        }
        
        // Process the queue until it's empty
        while(!q.empty()) {
            auto [val, distance] = q.front(); // Get the current cell and distance
            auto [i, j] = val; // Extract row (i) and column (j) from the position
            q.pop();
            
            // Update result to keep track of the maximum distance
            if(distance > result) {
                result = distance;
            }
            
            // Explore all three possible moves from the current cell
            for(auto it : dir) {
                int u = i + it.first; // Row index for the next cell
                int v = j + it.second; // Column index for the next cell
                
                // Check if the new cell (u, v) is within bounds, unvisited, and has a greater value
                if(u >= 0 && v >= 0 && u < n && v < m && !visited[u][v] && grid[i][j] < grid[u][v]) {
                    q.push({{u, v}, distance + 1}); // Enqueue the cell with incremented distance
                    visited[u][v] = true; // Mark the new cell as visited
                }
            }
        }
        
        // Return the maximum distance (moves) found
        return result;
    }

    // Main function to find the maximum moves possible starting from any cell in the first column
    int maxMoves(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
