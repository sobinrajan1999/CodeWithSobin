//question : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(string s1, string s2, int n, int m)
    {
        int maxval = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <=n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > maxval)
                    {
                        maxval = dp[i][j];
                    }
                }
            }
        }
        return maxval;
    }
  
    int longestCommonSubstr(string str1, string str2) {
        return solve(str1, str2, str1.size(), str2.size());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends