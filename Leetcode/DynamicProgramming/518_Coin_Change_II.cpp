//question : https://leetcode.com/problems/coin-change-ii/description/

//here we have to calculate the number of ways to count coins

class Solution {
public:

    int dp[302][50002];

    int solve(int amount, vector<int>& coins, int n)
    {
        if(n < 0)
        {
            if(amount == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }
        int nopick = solve(amount, coins, n-1);
        int pick = 0;
        if(amount >= coins[n])
        {
            pick = solve(amount - coins[n], coins, n);
        }
        return dp[n][amount] = pick + nopick;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(amount, coins, coins.size()-1);
    }
};