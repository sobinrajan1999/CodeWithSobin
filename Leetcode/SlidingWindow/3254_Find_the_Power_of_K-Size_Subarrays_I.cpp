//question : https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();  // Get the size of the input array
        vector<int> ans(n - k + 1, -1);  // Initialize the result array with -1, size is `n - k + 1`
        int left = 0;  // Start of the sliding window

        // Iterate through the array with `right` pointer representing the end of the window
        for (int right = 0; right < n; right++) {
            // Check if the current element and the previous element are not consecutive
            if (right > 0 && (nums[right] - nums[right - 1]) != 1) {
                left = right;  // Reset the `left` pointer to the current position
            }

            // Adjust the window size if it exceeds `k`
            while (left < right && (right - left + 1) > k) {
                left++;  // Shrink the window from the left
            }

            // If the current window size equals `k`, record the result
            if ((right - left + 1) == k) {
                ans[right - k + 1] = nums[right];  // Store the last element of the valid window
            }
        }

        return ans;  // Return the final result array
    }
};
