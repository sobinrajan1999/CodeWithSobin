//Question : https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        //for dynamic programming
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j <=m;j++)
            {
                //if both the characters are equal then we will take the diagonal value and add 1. i.e. previously made subsequence.
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                //which the characters are not equal, then we will take max of the upper and left index.i.e. we are ignoring the character for the subsequence.
                else
                {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};