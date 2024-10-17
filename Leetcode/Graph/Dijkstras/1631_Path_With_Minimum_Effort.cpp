class Solution {
public:

    //for horizontal and vertical directions
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> visited(n, vector<int>(m, false));
        //minimum efforts to reach each node from 0,0
        vector<vector<int>> eff(n, vector<int>(m, INT_MAX));
        //this min heap will keep three values 1. minimum effort, 2. index_x, 3. index_y
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        //pushing the source to the heap with min effort as zero
        pq.push({0, {0,0}});
        eff[0][0] = 0;

        while(!pq.empty())
        {
            auto [wt, index] = pq.top();
            auto [i, j] = index;
            visited[i][j] = true;
            pq.pop();
            //if we reach the destination i.e. bottom right side of the matrix then we will return the value we got from the heap.
            if(i == n-1 and j == m-1)
            {
                return wt;
            }
            //traversing all four directions
            for(auto it : dir)
            {
                int row = i + it.first;
                int col = j + it.second;
                //if the new coordinates are within the range and not visited
                if(row >= 0 and col >= 0 and row < n and col < m and !visited[row][col])
                {
                    //keep the max effort with current new coordinate or the one we got from the heap
                    int maxeffort = std::max(wt, abs(heights[row][col] - heights[i][j]));
                    //if the effort is less than the already recorded one then update it.
                    if(maxeffort < eff[row][col])
                    {
                        eff[row][col] = maxeffort;
                        pq.push({maxeffort, {row, col}});
                    }
                }
            }
        }
        //if it is not possible.
        return 0;
    }
};