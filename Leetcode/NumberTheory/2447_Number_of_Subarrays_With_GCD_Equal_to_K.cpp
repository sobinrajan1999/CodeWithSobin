//question : https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int result = 0; // Initialize result to store the count of subarrays with GCD equal to k

        // First, check each individual element
        for (auto i : nums) {
            if (i == k) { // If the element itself is equal to k, count it as a valid subarray
                result++;
            }
        }

        // Iterate through each starting point of subarrays
        for (int i = 0; i < nums.size(); i++) {
            int gcd_ = nums[i]; // Initialize gcd_ with the starting element of the subarray

            // Extend the subarray from i to j
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] % k != 0) { // If nums[j] is not divisible by k, break the inner loop
                    break;
                }

                gcd_ = gcd(gcd_, nums[j]); // Update gcd_ to include nums[j]

                // If the GCD of the subarray equals k, count it as a valid subarray
                if (gcd_ == k) {
                    result++;
                }
            }
        }

        return result; // Return the total count of valid subarrays
    }
};
