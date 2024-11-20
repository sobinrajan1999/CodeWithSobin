//question : https://leetcode.com/problems/decode-ways/description/

class Solution {
public:

    // DP array to store results of subproblems
    vector<int> dp;

    // Recursive function to calculate the number of ways to decode a substring ending at index `n`
    int solve(string& s, int n) {
        // Base case: If we've processed all characters successfully, return 1 (one valid way)
        if (n < 0) {
            return 1;
        }

        // If result for this index has already been computed, return it (Memoization)
        if (dp[n] != -1) {
            return dp[n];
        }

        int ans = 0;

        // If the current character at `n` is not '0', it can be decoded as a single character
        if (s[n] != '0') {
            ans += solve(s, n - 1);  // Decode this single character and move to the previous one
        }

        // Check if the last two characters form a valid two-digit number between 10 and 26
        if (n >= 1 && stoi(s.substr(n - 1, 2)) >= 10 && stoi(s.substr(n - 1, 2)) <= 26) {
            ans += solve(s, n - 2);  // Decode these two characters together and move two steps back
        }

        // Store the result in dp array for future lookups
        return dp[n] = ans;
    }

    // Main function to calculate the number of ways to decode the string `s`
    int numDecodings(string s) {
        int n = s.size();
        
        // Resize the dp array to the size of the string, initialized to -1 (uncomputed state)
        dp.resize(n, -1);

        // Start solving from the end of the string
        return solve(s, n - 1);
    }
};
