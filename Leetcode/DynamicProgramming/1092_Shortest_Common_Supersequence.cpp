//Question : https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution {
public:

    vector<vector<int>> dp;

    void calculateLCS(std::string str1, std::string str2)
    {
        int n = str1.size(); 
        int m = str2.size();

        dp = vector<vector<int>>(n+1, vector<int>(m+1));

        for(int i = 1; i <=n; i++)
        {
            for(int j = 1; j <=m; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        std::string result = "";
        //calculate the LCS that will give us how many common subsequence are there. 
        //the final string should looks like this = n + m - length(LCS).
        calculateLCS(str1, str2);
        int n = str1.size();
        int m = str2.size();
        int i = n, j = m;
        while(i > 0 and j > 0)
        {
            //if the char is same then we will take either one of the string and we decrement both the index.
            if(str1[i-1] == str2[j-1])
            {
                result += str1[i-1];
                i--;
                j--;
            }
            //if upper index is bigger then we will add the left index value and decrement i;
            else if(dp[i-1][j] > dp[i][j-1])
            {
                result += str1[i-1];
                i--;
            }
            //if left index is bigger then we will add the upper index value and decrement j.
            else
            {
                result += str2[j-1];
                j--;
            }
        }
        //adding the leftover chars
        while(i > 0)
        {
            result += str1[i-1];
            i--;
        }
        while( j > 0)
        {
            result += str2[j-1];
            j--;
        }
        //reversing the string as we are traversing in the bottom up manner
        std::reverse(result.begin(), result.end());
        return result;
    }
};