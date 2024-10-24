//question : https://leetcode.com/problems/climbing-stairs/description/

#define N 46

class Solution {
public:

    vector<int> dp;

    int rec(int n, int stair)
    {
        if(stair > n)
        {
            return 0;
        }
        if(stair == n)
        {
            return 1;
        }
        if(dp[stair] != -1)
        {
            return dp[stair];
        }
        return dp[stair] = rec(n, stair + 1) + rec(n, stair + 2);
    }

    int climbStairs(int n) {
        dp = vector<int>(N, -1);
        return rec(n, 0);
    }
};