//question : https://leetcode.com/problems/scramble-string/description/

class Solution {
public:
    // This unordered_map acts as a memoization table to store results of subproblems
    unordered_map<string, bool> dp;

    // Helper function to determine if s1 can be transformed into s2 by scrambling
    bool solve(string s1, string s2) {
        // Base case: if the strings are equal, they are scramble strings
        if(s1.compare(s2) == 0) {
            return true;
        }
        // Base case: if the string length is 1 and they are not equal, they cannot be scramble strings
        if(s1.size() <= 1) {
            return false;
        }
        
        // Create a unique key for the current subproblem using the two strings
        string key = s1 + " " + s2;
        
        // If the subproblem has already been solved, return the stored result
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        bool flag = false;
        int n = s1.size();
        
        // Try splitting the strings at every possible position (from 1 to n-1)
        for(int k = 1; k <= s1.size() - 1; k++) {
            // Check if there exists a valid scramble by splitting the strings and swapping the partitions
            if((solve(s1.substr(0, k), s2.substr(n - k, k)) && solve(s1.substr(k, n - k), s2.substr(0, n - k))) ||
               // Check if there exists a valid scramble by splitting the strings without swapping the partitions
               (solve(s1.substr(0, k), s2.substr(0, k)) && solve(s1.substr(k, n - k), s2.substr(k, n - k)))) {
                flag = true;
                break;
            }
        }
        
        // Store the result of the current subproblem in the memoization table
        return dp[key] = flag;
    }

    // Main function to determine if s1 is a scramble of s2
    bool isScramble(string s1, string s2) {
        // If the lengths of the strings are not equal, they cannot be scramble strings
        if(s1.size() != s2.size()) {
            return false;
        }
        // Start the recursive check
        return solve(s1, s2);
    }
};
