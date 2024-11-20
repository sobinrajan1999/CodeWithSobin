//question : https://leetcode.com/problems/flip-string-to-monotone-increasing/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        // `prefix` array where prefix[i] indicates the number of '0's from index i to the end of the string
        vector<int> prefix(n, 0);
        
        // Initialize the last element of `prefix`
        // If the last character is '0', we need one flip at this position
        prefix[n-1] = (s[n-1] == '0' ? 1 : 0);
        
        // Fill the `prefix` array from the second-to-last element to the beginning
        for (int i = n - 2; i >= 0; i--) {
            prefix[i] = prefix[i + 1] + (s[i] == '0' ? 1 : 0);
        }
        
        int oneflip = 0;    // `oneflip` counts the number of '1's encountered so far that would need to flip to '0'
        int totalflip = 0;  // Tracks the total flips needed for each position `i`
        int result = INT_MAX;  // Initialize result to a large value to store the minimum flips
        
        // Traverse the string to compute the minimum flips at each index
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {  // If current character is '1'
                
                // If we're not at the end, `toflip` is the number of '0's to flip from index i to the end
                int toflip = (i + 1 == n) ? 0 : prefix[i];
                
                // Total flips if we consider the current position `i` as the last '1' in a mono-increasing sequence
                totalflip = oneflip + toflip;
                
                // Increment `oneflip` since this '1' would need to be flipped to make a mono-increasing string
                oneflip++;
                
                // Update the result to be the minimum of itself and the `totalflip` calculated at this position
                result = std::min(result, totalflip);
            }
        }
        
        // Edge case: if the entire string is '1's, the result would simply be the count of flips to make all '1's
        result = std::min(result, oneflip);
        
        return result;  // Return the minimum flips found
    }
};
