//question : https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // 2D vector to store the intermediate results of the subproblems
    vector<vector<int>> dp;

    // Recursive function to find the minimum cost of matrix multiplication
    int solve(int arr[], int i, int j) {
        // Base case: if the chain length is less than or equal to 1, no multiplication needed
        if (i >= j) {
            return 0;
        }
        
        // If the result is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // Variable to store the minimum cost
        int minval = INT_MAX;

        // Iterate through all possible partitions to find the minimum cost
        for (int k = i; k < j; k++) {
            // Recursively calculate the cost of left and right partitions and add the cost of multiplying the two partitions
            int tempans = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            
            // Update the minimum cost
            minval = std::min(tempans, minval);
        }
        
        // Store the computed result and return it
        return dp[i][j] = minval;
    }

    // Function to initialize the dp table and start the recursive solution
    int matrixMultiplication(int N, int arr[]) {
        // Initialize the dp table with -1 to indicate uncomputed states
        dp = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
        
        // Start the recursive function from the first matrix to the last
        return solve(arr, 1, N - 1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    
        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends
