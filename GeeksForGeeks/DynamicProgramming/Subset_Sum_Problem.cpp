//question : https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
  int dp[202][40002];
  
    bool solve(vector<int>& arr, int sum, int n)
    {
        if(sum == 0)
        {
            return true;
        }
        if(n < 0 || sum < 0)
        {
            return false;
        }
        if(dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        return dp[n][sum] = solve(arr, sum - arr[n], n-1) or solve(arr, sum, n-1);
    }
  
    bool isSubsetSum(vector<int> arr, int sum) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, sum, arr.size()-1);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}

// } Driver Code Ends