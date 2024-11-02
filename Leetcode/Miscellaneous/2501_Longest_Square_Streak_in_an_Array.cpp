//question : https://leetcode.com/problems/longest-square-streak-in-an-array/

class Solution {
public:
    // Function to find the longest sequence of perfect squares in the input list
    int longestSquareStreak(vector<int>& nums) {
        // A boolean array to mark the presence of numbers in the input array
        vector<bool> m(100001, false);
        int maxval = -1; // Variable to keep track of the maximum value in nums
        
        // Mark the presence of each number in nums and find the maximum value
        for(auto it : nums) {
            m[it] = true;
            maxval = std::max(maxval, it);
        }

        int maxresult = -1; // Variable to store the maximum length of the sequence
        int msqrt = sqrt(maxval); // Calculate the square root of the maximum value
        
        // Iterate through numbers starting from 2 up to the square root of the maximum value
        for(int i = 2; i <= msqrt; i++) {
            if(m[i] == false) {
                continue; // If the number is not present in nums, skip it
            }

            int cost = 1; // Initialize the count of the sequence
            for(long long int j = i * i; j <= maxval; j *= j) {
                if(m[j]) { // If the square of the number is present in nums
                    cost++; // Increase the count
                    m[j] = false; // Mark the number as visited. it will help in reduce the iterations as it has already been visited and even if we start from here the cost will be less.
                } else {
                    break; // Break the loop if the square of the number is not present
                }
            }
            maxresult = std::max(maxresult, cost); // Update the maximum result
        }
        
        // Return the result, if the longest sequence is less than 2, return -1
        return maxresult < 2 ? -1 : maxresult;
    }
};
