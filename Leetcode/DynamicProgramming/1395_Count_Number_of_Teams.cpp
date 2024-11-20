//question : https://leetcode.com/problems/count-number-of-teams/description

#include <vector>
#include <cstring> // For memset
#include <algorithm> // For reverse

using namespace std;

class Solution {
public:
    int n; // Size of the rating vector
    int dp[1000][3]; // DP table to store intermediate results for subproblems

    // Recursive function to count valid teams starting from `index` with current `count` of selected members
    int solve(int index, vector<int>& rating, int count) {
        // Base case: if we have a team of 3 members, it's a valid team
        if (count == 3) {
            return 1;
        }
        
        // If already computed, return the stored result
        if (dp[index][count] != -1) {
            return dp[index][count];
        }
        
        int ans = 0;
        // Try to add a new member to the team
        for (int i = index + 1; i < n; i++) {
            // Ensure the team remains in increasing order
            if (rating[i] > rating[index]) {
                ans += solve(i, rating, count + 1);
            }
        }
        
        // Memoize the result for this subproblem
        return dp[index][count] = ans;
    }

    int numTeams(vector<int>& rating) {
        n = rating.size();
        int result = 0;

        // Initialize dp with -1 indicating no subproblem has been solved yet
        memset(dp, -1, sizeof(dp));

        // Calculate increasing teams
        for (int it = 0; it < n; it++) {
            result += solve(it, rating, 1); // Start a new team from each position
        }

        // Reset dp table for the next calculation
        memset(dp, -1, sizeof(dp));

        // Calculate decreasing teams by reversing the rating order
        reverse(rating.begin(), rating.end());
        for (int i = 0; i < n; i++) {
            result += solve(i, rating, 1); // Start a new team from each position
        }

        return result;
    }
};
