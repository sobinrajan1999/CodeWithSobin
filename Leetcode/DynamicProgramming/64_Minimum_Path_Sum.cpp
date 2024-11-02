//question : https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    int n, m; // Dimensions of the grid
    int dp[201][201]; // DP table for memoization

    // Recursive function to calculate the minimum path sum to reach (i, j)
    int solve(vector<vector<int>>& grid, int i, int j) {
        // Base case: if indices are out of bounds, return a high value (acts as infinity)
        if (i < 0 || j < 0) {
            return INT_MAX;
        }

        // Base case: if we've reached the starting cell, return its value
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        // If the result is already computed, return it from dp table
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Recursive case: calculate the minimum path sum for cell (i, j)
        // We can come from the top cell (i-1, j) or from the left cell (i, j-1)
        // Add the current cell's value to the minimum of the two options
        return dp[i][j] = grid[i][j] + std::min(solve(grid, i - 1, j), solve(grid, i, j - 1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();    // Number of rows
        m = grid[0].size(); // Number of columns

        // Initialize the dp table with -1 (indicates uncomputed states)
        memset(dp, -1, sizeof(dp));

        // Start the recursion from the bottom-right cell
        return solve(grid, n - 1, m - 1);
    }
};
