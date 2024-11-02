//question : https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int n, vector<int>& arr, int sum, int totalsum)
    {
        if(n < 0)
        {
            if(totalsum == sum)
            {
                // std::cout<<totalsum<<" "<<sum<<std::endl;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        return dp[n][sum] = (solve(n-1, arr, sum + arr[n], totalsum) + 
                solve(n-1, arr, sum, totalsum))%1000000007;
    }

    int findTargetSumWays(vector<int>& arr, int d) {
        int n = arr.size();
        int totalsum = accumulate(arr.begin(), arr.end(), 0);
        dp = vector<vector<int>>(n+1, vector<int>(totalsum+1, -1));
        if(totalsum - d < 0 or (totalsum - d)%2 == 1)
        {
            return 0;
        }
        return solve(n-1, arr, 0, (totalsum + d)/2);
    }
};