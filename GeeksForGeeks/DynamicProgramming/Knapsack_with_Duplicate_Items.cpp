//question : https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

//this knapack is similiar to 0-1 knapsack but the only difference is if we are picking tje pick, we will not reduce the array size, we will keep it as it is.
//array size will only reduce if we are not picking the item.

class Solution{
public:

    vector<vector<int>> dp;

    int solve(int N, int W, int val[], int wt[])
    {
        if(W <= 0)
        {
            return 0;
        }
        
        if(N < 0)
        {
            return 0;
        }
        if(dp[N][W] != -1)
        {
            return dp[N][W];
        }
        
        if(W >= wt[N])
        {
            //here we are picking the item not reducing the array size.
            int pick = val[N] + solve(N, W - wt[N], val, wt);
            int notpick = solve(N-1, W, val, wt);
            return dp[N][W] = std::max(pick, notpick);
        }
        else
        {
            return dp[N][W] = solve(N-1, W, val, wt);
        }
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        dp = vector<vector<int>>(N+1, vector<int>(W+1, -1));
        return solve(N-1, W, val, wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends