//question : https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& coins, int amount, int n)
    {
        if(n < 0)
        {
            if(amount == 0)
            {
                return 0;
            }
            //if the amount is greater than 0 or less then we will return INT_MAX value.
            else
            {
                return INT_MAX - 1;
            }
        }
        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }
        int nopick = 0 + solve(coins, amount, n-1);
        int pick = INT_MAX;
        //picking the coin and adding the count of coins picked into the pick variable.
        if(amount >= coins[n])
        {
            pick = 1 + solve(coins, amount - coins[n], n);
        }
        //picking the choice where i get minimum coin count;
        return dp[n][amount] = std::min(nopick, pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        dp = vector<vector<int>>(coins.size()+1, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, coins.size()-1);
        if(ans == INT_MAX-1)
        {
            return -1;
        }
        return ans;
    }
};