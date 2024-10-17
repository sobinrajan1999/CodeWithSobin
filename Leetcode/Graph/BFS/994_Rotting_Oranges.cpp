//Questions: https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    //to go to four directions
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //queue to keep the rotten oranges
        queue<pair<int, int>> q;
        //pushing all the rotten oranges to the queue
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        int totalmins = 0;
        bool first = false;

        while(!q.empty())
        {
            //getting the size of queue and pushing all the adjacent nodes to the queue.
            //each loop inside while loop denotes a minute it took to rote adjacent orange.
            int qsize = q.size();
            for(int i = 0; i< qsize; i++)
            {
                auto temp = q.front();
                q.pop();

                for(auto it : dir)
                {
                    int row = temp.first + it.first;
                    int col = temp.second + it.second;
                    if(row >=0 and col >= 0 and row < n and col <m and grid[row][col] == 1)
                    {
                        grid[row][col] = 2;
                        q.push({row, col});
                    }
                }
            }
            //first traversal doesn't count as a minute.
            if(first)
            {
                totalmins++;
            }
            first = true;
        }
        //if there is an orange untouched return -1;
        for(auto it : grid)
        {
            for(auto i : it)
            {
                if(i == 1)
                {
                    return -1;
                }
            }
        }
        return totalmins;
    }
};