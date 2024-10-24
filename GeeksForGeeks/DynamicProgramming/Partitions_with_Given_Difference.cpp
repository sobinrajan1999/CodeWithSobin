//question : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
    
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalsum = accumulate(arr.begin(), arr.end(), 0);
        dp = vector<vector<int>>(n+1, vector<int>(totalsum+1, -1));
        if(totalsum - d < 0 or (totalsum - d)%2 == 1)
        {
            return 0;
        }
        return solve(n-1, arr, 0, (totalsum + d)/2);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends