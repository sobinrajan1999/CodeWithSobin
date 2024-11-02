//question : https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    
cout << "~" << "\n";
}
return 0;
}
// } Driver Code Ends

vector<vector<int>> dp;

int solve(string& s, int i, int j)
{
    if(i > j)
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if(s[i] == s[j])
    {
        if(i == j)
        {
            return dp[i][j] = 1 + solve(s, i+1, j-1);
        }
        else
        {
            return dp[i][j] = 2 + solve(s, i+1, j-1);
        }
        
    }
    return dp[i][j] = std::max(solve(s, i, j-1), solve(s, i+1, j));
}

int minDeletions(string s, int n) { 
    dp = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
    //number of deletion in the strin is :  longest palindrome in the string - size of the string.
    return s.size() - solve(s, 0, s.size()-1);
} 