//question : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int dp[1002][1002];
  
    int solve(int W, vector<int>& wt, vector<int>& val, int n)
    {
        if(W <= 0)
        {
            return 0;
        }
        if(n < 0)
        {
            return 0;
        }
        if(dp[W][n] != -1)
        {
            return dp[W][n];
        }
        if(W >= wt[n])
        {
            int pick = val[n] + solve(W - wt[n], wt, val, n-1);
            int nopick = solve(W, wt, val, n-1);
            return dp[W][n] = std::max(pick, nopick);
        }
        else
        {
            return dp[W][n] = solve(W, wt, val, n-1);
        }
        
    }
  
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        memset(dp, -1, sizeof(dp));
        return solve(W, wt, val, wt.size()-1);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends