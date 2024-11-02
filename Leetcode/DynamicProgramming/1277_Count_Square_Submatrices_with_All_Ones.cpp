//question : https://leetcode.com/problems/count-square-submatrices-with-all-ones/description

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Get the dimensions of the matrix
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Create a DP table with the same dimensions as the matrix
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Variable to store the total count of square submatrices
        int ans = 0;
        
        // Initialize the first column of the DP table
        // Each cell in the first column can only form a 1x1 square if matrix[i][0] == 1
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            ans += matrix[i][0]; // Add the count of squares from the first column
        }
        
        // Initialize the first row of the DP table
        // Each cell in the first row can only form a 1x1 square if matrix[0][i] == 1
        for (int i = 1; i < m; i++) {
            dp[0][i] = matrix[0][i];
            ans += matrix[0][i]; // Add the count of squares from the first row
        }
        
        // Fill the DP table for the remaining cells
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // Only process if the current cell in the matrix is 1
                if (matrix[i][j] == 1) {
                    // For each cell, check the minimum value among:
                    // 1. Left cell (dp[i][j-1])
                    // 2. Top cell (dp[i-1][j])
                    // 3. Top-left diagonal cell (dp[i-1][j-1])
                    // Add 1 to this minimum value
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                    
                    // Add the current cell's value to the total count
                    ans += dp[i][j];
                }
            }
        }
        
        // Return the total count of square submatrices
        return ans;
    }
};
