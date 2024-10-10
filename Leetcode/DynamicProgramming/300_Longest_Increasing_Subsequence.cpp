//Question : https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(arr.size(), 1);
        int maxval = INT_MIN;
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if((arr[i] > arr[j]) and (1 + dp[j] > dp[i]))
                {
                    dp[i] = dp[j]+1;
                }
            }
        }
        for(auto it : dp)
        {
            maxval = std::max(maxval, it);
        }
        return maxval;
    }
};