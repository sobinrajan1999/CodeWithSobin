//question : https://leetcode.com/problems/house-robber/description/

class Solution {
public:

    vector<int> dp;

    int solve(vector<int>& nums, int n)
    {
        if(n == 0)
        {
            return nums[n];
        }
        if(n < 0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int pick = nums[n] + solve(nums, n-2);
        int nopick = solve(nums, n-1);
        return dp[n] = std::max(pick, nopick);
    }

    int rob(vector<int>& nums) {
        dp = vector<int>(402, -1);
        return solve(nums, nums.size()-1);
    }
};