//question : https://leetcode.com/problems/find-a-safe-walk-through-a-grid/

class Solution {
public:

    vector<vector<int>> dist;
    vector<vector<bool>> visited;
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    void DijkstarsAlgorithm(vector<vector<int>>& grid, int n, int m)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty())
        {
            auto [wt, index] = pq.top();
            auto [i, j] = index;
            pq.pop();
            visited[i][j] = true;
            for(auto it : dir)
            {
                int row = i + it.first;
                int col = j + it.second;
                if(row >= 0 and col >= 0 and row < n and col < m and !visited[row][col] and dist[i][j] != INT_MAX and dist[row][col] > dist[i][j] + grid[row][col])
                {
                    dist[row][col] = dist[i][j] + grid[row][col];
                    pq.push({dist[row][col], {row, col}});
                }
            }
        }
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        dist = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        DijkstarsAlgorithm(grid, n, m);
        std::cout<<dist[n-1][m-1]<<std::endl;
        return ((health - dist[n-1][m-1]) >= 1);
    }
};