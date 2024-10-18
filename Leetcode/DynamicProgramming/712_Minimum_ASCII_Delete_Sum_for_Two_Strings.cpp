//Question : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    //same like edit distance but there instead of count we will be calcualting based on the ascii value of each characters.
    int minimumDeleteSum(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m+1));
        for(int i = 1; i<=n; i++)
        {
            dp[i][0] = dp[i-1][0] + word1[i-1];
        }
        for(int i = 1; i <=m; i++)
        {
            dp[0][i] = dp[0][i-1] + word2[i-1];
        }
        for(int i =1 ; i <=n; i++)
        {
            for(int j = 1; j <=m; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = std::min(dp[i-1][j] + word1[i-1], dp[i][j-1] + word2[j-1]);
                }
            }
        }
        return dp[n][m];
    }
};