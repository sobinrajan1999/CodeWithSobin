//question : https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/

class Solution {
public:
    // Function to find the maximum subarray sum using Kadane's algorithm
    int kadence(vector<int>& arr) {
        int n = arr.size();
        int sol = arr[0];  // Initialize solution with the first element
        int sum = 0;       // Initialize current sum to 0

        for (int i = 0; i < n; i++) {
            // Update current sum by adding arr[i] or starting new from arr[i]
            sum = std::max(sum + arr[i], arr[i]);
            // Update the overall solution with the maximum sum found so far
            sol = std::max(sum, sol);
        }
        
        return sol;  // Return the maximum subarray sum
    }

    // Function to calculate the maximum cost of any substring based on given values
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        // Step 1: Initialize a vector to assign values to each character in the alphabet
        vector<int> alpha(26);
        iota(alpha.begin(), alpha.end(), 1); // Default values: 'a' = 1, 'b' = 2, ..., 'z' = 26

        // Step 2: Assign custom values for the characters in `chars`
        for (int i = 0; i < chars.size(); i++) {
            alpha[chars[i] - 'a'] = vals[i];
        }

        // Step 3: Create an array `arr` where each character in `s` is replaced by its value
        vector<int> arr;
        for (int i = 0; i < s.size(); i++) {
            arr.push_back(alpha[s[i] - 'a']);
        }

        // Step 4: Use Kadane's algorithm to find the maximum subarray sum in `arr`
        int result = kadence(arr);

        // Step 5: If the maximum sum is negative or zero, return 0 (no positive-cost substring)
        if (result <= 0) {
            return 0;
        }
        
        return result;  // Return the maximum positive cost
    }
};
