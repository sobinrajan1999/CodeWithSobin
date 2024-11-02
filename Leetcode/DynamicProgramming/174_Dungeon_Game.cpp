//question : https://leetcode.com/problems/dungeon-game/description/

class Solution {
public:
    int n, m; // Dimensions of the dungeon grid
    int dp[201][201]; // DP table for memoization

    // Recursive function to calculate the minimum health needed at each cell (i, j)
    int solve(vector<vector<int>>& dungeon, int i, int j) {
        // If we go out of bounds (beyond grid dimensions), return a large number as it’s an invalid path
        if (i >= n || j >= m) {
            return INT_MAX;
        }

        // Base case: if we're at the bottom-right cell, calculate the minimum health required here
        if (i == n - 1 && j == m - 1) {
            //if there is a dragon at this point we need the exact amount of health + 1 else we will 
            //return 1 as there is not dragon and you will gain health which we don't need to add it 
            //in our answer.
            return (dungeon[i][j] <= 0) ? -dungeon[i][j] + 1 : 1;
        }

        // If we have already calculated the value for this cell, return it from dp table
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Calculate minimum health needed if we move to the right or move downward
        int rightmove = solve(dungeon, i, j + 1);
        int downmove = solve(dungeon, i + 1, j);

        // Find the minimum health needed for the current cell (i, j).
        //the catch is, here we are subtracting the current grid value from the from the min we got from other cells.
        //that means if there is a orc then the value may go to -ve side but if there is a dragon, then
        //the value may go to the positive side.
        int temp = std::min(rightmove, downmove) - dungeon[i][j];

        // Ensure the minimum health is at least 1 (as health cannot drop below 1)
        //if the value is -ve that means there is no dragon in the current grid and we will return 1 as there will no health loss 
        //and the person will have +ve health at this stage.
        return dp[i][j] = (temp <= 0) ? 1 : temp;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // Initialize the dp array with -1 (indicating uncomputed states)
        memset(dp, -1, sizeof(dp));

        // Set the dimensions of the dungeon grid
        n = dungeon.size();
        m = dungeon[0].size();

        // Start recursion from the top-left cell to determine the minimum initial health needed
        return solve(dungeon, 0, 0);
    }
};
