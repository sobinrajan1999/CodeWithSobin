//Question : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

class Solution {
public:

    vector<int> longestIncreasingSubsequence(vector<int> arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(arr[i] > arr[j] and 1 + dp[j] > dp[i])
                {
                    dp[i] = dp[j]+1;
                }
            }
        }
        return dp;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        //longest increasing subsequence
        auto uphill = longestIncreasingSubsequence(nums);
        //instead of longest decreasing subsequence, we will reverse the array and perform the longest increasing subsequence.
        auto downhill = longestIncreasingSubsequence({nums.rbegin(), nums.rend()});
        //reverse the dp array as the values should be in decreasing order.
        std::reverse(downhill.begin(), downhill.end());
        int n = uphill.size();
        int mountainsize = 0;
        //will calculate the mountain in the array.
        for(int i = 0; i <n; i++)
        {
            if(uphill[i] > 1 and downhill[i] > 1)
            {
                mountainsize = std::max(mountainsize, uphill[i] + downhill[i]-1);
            }
        }
        //number of deletion will be (array size - mountain array size)
        return nums.size() - mountainsize;
    }
};