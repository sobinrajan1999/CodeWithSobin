//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

int n;
int visitedall;

int dp[21][1048576];

int TSP(vector<vector<int>>& cost, int mask, int pos)
{
    if(mask == visitedall)
    {
        return cost[pos][0];
    }
    if(dp[pos][mask] != -1)
    {
        return dp[pos][mask];
    }
    int ans = INT_MAX;
    for(int city = 0; city < n; city++)
    {
        if((mask &(1 << city)) == 0)
        {
            int newans = cost[pos][city] + TSP(cost, mask|(1<<city), city);
            ans = std::min(ans, newans);
        }
    }
    return dp[pos][mask] = ans;
}

int total_cost(vector<vector<int>>cost){
    memset(dp, -1, sizeof(dp));
    n = cost.size();
    visitedall = (1<<n) - 1;
    return TSP(cost, 1, 0);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends