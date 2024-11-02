//question: https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  vector<vector<int>> dp;
  
    int solve(int price[], int n, int length)
    {
        if(length <= 0)
        {
            return 0;
        }
        
        if(n < 0)
        {
            return 0;
        }
        if(dp[n][length] != -1)
        {
            return dp[n][length];
        }
        
        if(length >= (n+1))
        {
            int pick = price[n] + solve(price, n, length - (n+1));
            int nopick = solve(price, n-1, length);
            return dp[n][length] = max(pick, nopick);
        }
        else
        {
            return dp[n][length] = solve(price, n-1, length);
        }
    }
  
    int cutRod(int price[], int n) {
        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return solve(price, n-1, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends