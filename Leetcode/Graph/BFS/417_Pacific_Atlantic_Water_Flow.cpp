//questions : https://leetcode.com/problems/pacific-atlantic-water-flow/description/

class Solution {
public:
    vector<vector<bool>> pacificVisited, atlanticVisited;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        int n = heights.size();
        int m = heights[0].size();
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (auto dir : directions) {
                int newRow = i + dir.first;
                int newCol = j + dir.second;
                
                // Check if the new cell is within bounds, unvisited, and has a valid height
                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && !visited[newRow][newCol] && heights[newRow][newCol] >= heights[i][j]) {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        if (n == 0) return {};
        int m = heights[0].size();
        
        // Initialize visited matrices
        pacificVisited = vector<vector<bool>>(n, vector<bool>(m, false));
        atlanticVisited = vector<vector<bool>>(n, vector<bool>(m, false));
        
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;
        
        // Fill the boundary cells for both oceans
        for (int i = 0; i < n; i++) {
            // Pacific Ocean: first column
            pacificVisited[i][0] = true;
            pacificQueue.push({i, 0});
            
            // Atlantic Ocean: last column
            atlanticVisited[i][m-1] = true;
            atlanticQueue.push({i, m-1});
        }
        
        for (int j = 0; j < m; j++) {
            // Pacific Ocean: first row
            pacificVisited[0][j] = true;
            pacificQueue.push({0, j});
            
            // Atlantic Ocean: last row
            atlanticVisited[n-1][j] = true;
            atlanticQueue.push({n-1, j});
        }
        
        // Perform BFS for Pacific and Atlantic oceans
        bfs(heights, pacificQueue, pacificVisited);
        bfs(heights, atlanticQueue, atlanticVisited);
        
        // Collect the result where both oceans can be reached
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};
