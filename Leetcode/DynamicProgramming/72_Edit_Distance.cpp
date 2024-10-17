//Question : https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
    int minDistance(string word1, string word2) {
        std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1));

        for(int i = 0; i<= word2.size(); i++)
        {
            dp[0][i] = i;
        }

        for(int i = 0; i<= word1.size(); i++)
        {
            dp[i][0] = i;
        }

        for(int i = 1; i<= word1.size(); i++)
        {
            for(int j = 1; j <= word2.size(); j++)
            {
                //if the char are same then we are not performing any operation
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                //if are not same then we are performing either of the 2 operations. 1. updation, 2. deletion. if [i, j-1] is min then we are deleting, if [i-1][j-1] is min then are updating the value
                else
                {
                    dp[i][j] = std::min(dp[i][j-1], std::min(dp[i-1][j-1], dp[i-1][j])) +1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};