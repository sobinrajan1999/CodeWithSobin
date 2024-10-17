//Question : https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        //here diagonals represent the index of the string
        vector<vector<int>> dp(n, vector<int>(n));
        //diagonals are 1 because single strings are always palindromic of length 1.
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        //i denotes the length of the string. strating with 2.
        for(int i =2 ; i<= n; i++)
        {
            //index var will help in point to the j+i index, which denotes he length;
            int index = i-1;
            for(int j = 0; j <= n-i; j++)
            {
                //if the two characters in the first and last index of the length is same then we will add 2 with the longest palindromic subsquence inside that length.
                if(s[j] == s[j+index])
                {
                    dp[j][j+index] = 2 + dp[j+1][j + index-1];
                }
                //else we will take the longest palindromic subsequence inside that substring.
                else
                {
                    dp[j][j+index] = std::max(dp[j+1][j+index], dp[j][j + index-1]);
                }
            }
        }
        //top left index of array will have the answer to the longest palindromic subsequence.
        return dp[0][n-1];
    }
};