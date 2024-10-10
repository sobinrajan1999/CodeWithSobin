//Question : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
//vector for directions
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        //priority queue to keep the element in descending order to count the increasing sequence
        priority_queue<pair<int, pair<int, int>>> pq;
        //pushing all the values to the priority queue
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j< m; j++)
            {
                pq.push({matrix[i][j], {i, j}});
            }
        }
        int maxResult = 0;
        //traversing through all the elements from pq
        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            int value = 0;
            //using dir vector to visit all its adjacent nodes
            for(auto it : dir)
            {
                int row = temp.second.first + it.first;
                int col = temp.second.second + it.second;
                //if the new coordinates are under the limit and new coordinates are bigger than the current value then will try to get the max value from dp
                if(row >= 0 and col >= 0 and row < n and col < m and matrix[row][col] > temp.first)
                {
                    value = std::max(value, dp[row][col]);
                }
            }
            //updating the max value from its adjacent nodes to the current node.
            dp[temp.second.first][temp.second.second] = 1+ value;
            //storing the maxvalue to a variable for the longest increasing path
            maxResult = std::max(maxResult, dp[temp.second.first][temp.second.second]);
        }
        return maxResult;
    }
};