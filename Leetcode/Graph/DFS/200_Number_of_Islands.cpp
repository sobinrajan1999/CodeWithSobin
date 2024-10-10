class Solution {
public:

//coordinates to move to four directions in the matrix
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    //function to calculate the aree of island in the matrix
    void calculateIsland(vector<vector<char>>& arr, vector<vector<bool>>& visited, int i, int j)
    {
        //base case. if it satisfies then have to move to another direction
        if(i >= 0 and i < arr.size() and j >= 0 and j < arr[i].size() and (!visited[i][j] and arr[i][j] == '1'))
        {
            //if it is a valid node then mark it as visited
            visited[i][j] = true;
            //loop to move to all the direction from the current node.
            for(auto it : dir)
            {
                calculateIsland(arr, visited, i+it.first, j + it.second);
            }
        }
        
    }

    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        //loop to visit all the node in the matrix
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //if the node is starting point of new island that we haven't traversed, then this below condition will satisfy.
                if(!visited[i][j] and arr[i][j] == '1')
                {
                    //this below function will mark one island and will increase the count.
                    count++;
                    calculateIsland(arr, visited, i, j);
                }
            }
        }

        // for(auto it : visited)
        // {
        //     for(auto i : it)
        //     {
        //         std::cout<<i<< " ";
        //     }
        //     std::cout<<std::endl;
        // }
        return count;
    }
};