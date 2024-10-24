//question : https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

struct jobs
{
    int start;
    int end;
    int profit;
    jobs(int a, int b, int c)
    {
        start = a;
        end = b;
        profit = c;
    }
};

class Solution {
public:

    vector<int> dp;
    //this recursive solution will work upon dynamic programming problem based on pick and no pick.
    int solve(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int i , int n)
    {
        if(i >= n)
        {
            return 0;
        }
        int ans = 0;
        if(dp[i] != -1)
        {
            return dp[i];
        }
        //using binary search to get the next job that has greater starttime after the current job's endtime.
        int nexti = lower_bound(startTime.begin() + i, startTime.end(), endTime[i]) - startTime.begin();
        //either we pick the current job or no moving with the next job.(pick or no pick)
        int pick = profit[i] + solve(startTime, endTime, profit, nexti, n);
        int nopick = solve(startTime, endTime, profit, i+1, n);
        //storing the value in dp and also returning it.
        return dp[i] = std::max(pick, nopick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<jobs> arr;
        int n = startTime.size();
        dp = vector<int>(n+1, -1);
        //storing the solution in a structure and sorting it.
        for(int i = 0 ; i< n; i++)
        {
            jobs j(startTime[i], endTime[i], profit[i]);
            arr.push_back(j);
        }
        //sorting based on the starttime
        sort(arr.begin(), arr.end(), [](auto& a, auto& b)
        {
            return a.start < b.start;
        });
        for(int i = 0 ; i< n; i++)
        {
            startTime[i] = arr[i].start;
            endTime[i] = arr[i].end;
            profit[i] = arr[i].profit;
        }
        //using recursion
        return solve(startTime, endTime, profit, 0, n);
        //using tabulation
        // for(int i = n-1; i >=0; i--)
        // {
        //     int nexti = lower_bound(startTime.begin() + i, startTime.end(), endTime[i]) - startTime.begin();
        //     int pick = profit[i] + dp[nexti];
        //     int nopick = dp[i+1];
        //     dp[i] = std::max(pick, nopick);
        // }
        // return dp[0];
    }
};