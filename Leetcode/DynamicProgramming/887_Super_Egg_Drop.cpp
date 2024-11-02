//question : https://leetcode.com/problems/super-egg-drop/description/

class Solution {
public:
    // Memoization table to store results for subproblems
    int dp[101][10001];

    // Recursive function to calculate minimum number of attempts
    // required to find the critical floor
    int solve(int k, int n) {
        // Base cases
        if (n == 0 || n == 1) {
            return n; // 0 or 1 floor requires 0 or 1 attempt
        }
        if (k == 1) {
            return n; // With one egg, we have to try every floor
        }

        // If result is already calculated, use it to save computation
        if (dp[k][n] != -1) {
            return dp[k][n];
        }

        long long minresult = INT_MAX; // Initialize minimum attempts as max value
        int start = 1; // Binary search starting point
        int end = n;   // Binary search ending point

        // Use binary search to optimize the choice of floor
        while (start <= end) {
            int mid = (start + end) / 2;

            // Recursively compute results for breaking and non-breaking cases
            int breakegg = solve(k - 1, mid - 1);  // Case when egg breaks
            int nobreakegg = solve(k, n - mid);    // Case when egg doesn't break

            // Calculate number of attempts for this floor choice
            long long tempans = 1 + std::max(breakegg, nobreakegg);

            // Update the minimum number of attempts needed
            minresult = std::min(minresult, tempans);

            // Adjust search range based on which case had more attempts
            if (breakegg > nobreakegg) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        // Store the computed result in dp array
        return dp[k][n] = minresult;
    }

    // Main function to find the minimum number of attempts needed
    int superEggDrop(int k, int n) {
        // Initialize dp array with -1 (uncomputed state)
        memset(dp, -1, sizeof(dp));
        
        // Start solving with given eggs (k) and floors (n)
        return solve(k, n);
    }
};
