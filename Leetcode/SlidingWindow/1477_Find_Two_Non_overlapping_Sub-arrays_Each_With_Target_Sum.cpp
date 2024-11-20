//question : https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // Vectors to store the minimum subarray length from the left and right
        vector<int> leftvec(n), rightvec(n);
        
        // Variables for maintaining the sliding window and tracking subarray sums
        int left = 0;
        int right = 0;
        int sum = 0;

        // `maxsize` represents the smallest subarray length found so far
        int maxsize = INT_MAX;

        // Process from the left to calculate `leftvec`
        while (right < n) {
            sum += arr[right]; // Expand the sliding window
            // Shrink the window if the sum exceeds the target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            // If a subarray with the sum equal to target is found
            if (sum == target) {
                maxsize = std::min(maxsize, (right - left + 1));
            }
            leftvec[right] = maxsize; // Store the minimum length up to this point
            right++; // Move the right pointer forward
        }

        // Reset variables for processing from the right
        left = n - 1;
        right = n - 1;
        sum = 0;
        maxsize = INT_MAX;

        // Process from the right to calculate `rightvec`
        while (right >= 0) {
            sum += arr[right]; // Expand the sliding window
            // Shrink the window if the sum exceeds the target
            while (sum > target) {
                sum -= arr[left];
                left--;
            }
            // If a subarray with the sum equal to target is found
            if (sum == target) {
                maxsize = std::min(maxsize, (left - right + 1));
            }
            rightvec[right] = maxsize; // Store the minimum length up to this point
            right--; // Move the right pointer backward
        }

        // Final calculation: Combine the two vectors to find the minimum sum of lengths
        int result = INT_MAX;
        for (int j = 1; j < n; j++) {
            // Check if valid subarrays exist on both sides
            if ((leftvec[j - 1] != INT_MAX && rightvec[j] != INT_MAX)) {
                result = std::min(result, (rightvec[j] + leftvec[j - 1]));
            }
        }

        // If no valid combination is found, return -1; otherwise, return the result
        return result == INT_MAX ? -1 : result;
    }
};
