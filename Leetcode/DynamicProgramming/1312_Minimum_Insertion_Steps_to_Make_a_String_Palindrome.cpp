//question : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

class Solution {
public:
    //similiar to number of deletion to make a valid palindrome. here instead of deleting the extra character, we are adding the same number of characters to make it a palindrome.
    vector<vector<int>> dp;
    int solve(string& s, int n, int m)
    {
        if(n > m)
        {
            return 0;
        }
        if(dp[n][m]  != -1)
        {
            return dp[n][m];
        }
        if(s[n] == s[m])
        {
            if(n == m)
            {
                return dp[n][m] = 1 + solve(s, n+1, m - 1);
            }
            else
            {
                return dp[n][m] = 2 + solve(s, n+1, m-1);
            }
        }
        return dp[n][m] = std::max(solve(s, n+1, m), solve(s, n, m-1));
    }

    int minInsertions(string s) {
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return n - solve(s, 0, n-1);
    }
};