//question : https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:

    int dp[202][20002];

    bool subsetsum(vector<int>& arr, int sum_left, int i)
    {
        if(sum_left < 0)
        {
            return false;
        }
        if(sum_left == 0)
        {
            return true;
        }
        if(i == arr.size())
        {
            return false;
        }

        if(dp[i][sum_left] != -1)
        {
            return dp[i][sum_left];
        }
        //based on pick and no pick creating the subsets.
        return dp[i][sum_left] = subsetsum(arr, sum_left - arr[i], i+1) or subsetsum(arr, sum_left, i+1);
    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        long long totalsum = accumulate(nums.begin(), nums.end(), 0);
        if(totalsum%2 != 0)
        {
            return false;
        }
        return subsetsum(nums, totalsum/2, 0);
    }
};