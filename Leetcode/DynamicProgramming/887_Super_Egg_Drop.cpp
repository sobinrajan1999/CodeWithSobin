//question : https://leetcode.com/problems/super-egg-drop/description/

class Solution {
public:

    vector<vector<int>> dp;
    //Using DP memoization
    int solve(int k, int n)
    {
        //case where floor is only 0 or 1. then return the count of floors.
        if(n == 0 or n == 1)
        {
            return n;
        }
        //if the egg count is 1. then the number of trials will be equal to the number of floors left. because we have to check every floor.
        if(k == 1)
        {
            return n;
        }
        //if the solution for the subproblem is already stored, then return the result.
        if(dp[n][k] != -1)
        {
            return dp[n][k];
        }
        int ans = INT_MAX;
        int left = 1;
        int right = n;
        //using binary search to reduce the search time.
        while(left <= right)
        {
            int mid = (left + right)/2;
            //two scenarios, where an egg breaks or the eggs doesn't break.
            int breakegg = 0;
            int notbreak = 0;
            //checking for the subproblem present in the dp.
            if(dp[mid-1][k-1] != -1)
            {
                breakegg = dp[mid-1][k-1];
            }
            else
            {
                breakegg = solve(k-1, mid-1);
            }
            if(dp[n-mid][k] != -1)
            {
                notbreak = dp[n-mid][k];
            }
            else
            {
                notbreak = solve(k, n - mid);
            }
            //here we are taking the maximum of worst case trails for breaking and not breaking and taking the minimum trails needed from all such floors.
            ans = std::min(std::max(breakegg, notbreak), ans);
            //if the worst case for breaking the egg is more, then we go down the floors and try to minimize the breaking egg scenarios.
            if(breakegg > notbreak)
            {
                right = mid-1;
            }//else we will try the upper floors for more breaking scenarios
            else
            {
                left = mid+1;
            }
        }
        return dp[n][k] = ans + 1;
    }

    int superEggDrop(int k, int n) {
        dp = vector<vector<int>>(n+1, vector<int>(k+1, -1));
        return solve(k, n);
    }
};