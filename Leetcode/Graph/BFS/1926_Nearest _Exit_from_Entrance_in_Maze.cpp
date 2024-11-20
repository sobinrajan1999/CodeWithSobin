//question : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

class Solution {
public:
    // Define movement directions: up, right, down, left.
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();    // Number of rows in the maze
        int m = maze[0].size(); // Number of columns in the maze
        
        // Queue to store cells to visit, along with their distance from the entrance
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0}); // Push entrance coordinates and step count (0)
        
        // Visited array to mark cells that have been visited to prevent revisiting
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[entrance[0]][entrance[1]] = true; // Mark the entrance as visited
        
        // Perform BFS to find the nearest exit
        while (!q.empty()) {
            // Get the current cell and the number of steps taken to reach it
            auto [coord, steps] = q.front();
            q.pop();
            auto [i, j] = coord; // Extract row and column indices
            
            // Check if the current cell is an exit (on the boundary) 
            // and not the entrance
            if ((i == n - 1 || i == 0 || j == m - 1 || j == 0) && 
                (i != entrance[0] || j != entrance[1])) {
                return steps; // Return the number of steps to the nearest exit
            }
            
            // Explore all four possible directions (up, right, down, left)
            for (auto it : dir) {
                int row = i + it.first; // Calculate new row
                int col = j + it.second; // Calculate new column
                
                // Check if the new cell is within bounds, not visited, and not a wall
                if (row >= 0 && row < n && col >= 0 && col < m && 
                    !visited[row][col] && maze[row][col] != '+') {
                    visited[row][col] = true; // Mark the new cell as visited
                    q.push({{row, col}, steps + 1}); // Add new cell to queue with incremented step count
                }
            }
        }
        
        // If no exit is reachable, return -1
        return -1;
    }
};
