//question : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description

class Solution {
public:
    // Function to update the bit count array based on the binary representation of `a`
    // `isadd` parameter is used to determine whether to add or subtract bits from bitcount
    void updatearray(int a, vector<int>& bitcount, int isadd) {
        int i = 0;
        // Process each bit in `a` by continuously dividing by 2
        while(a > 0) {
            // Update bitcount at position `i` by adding or subtracting 1 based on `isadd`
            bitcount[i] = bitcount[i] + ((isadd ? 1 : -1) * (a % 2));
            a /= 2;  // Shift `a` right by 1 bit (by dividing by 2)
            i++;     // Move to the next bit position
        }
    }

    // Function to check if the value represented by the current bitcount array is >= k
    bool isgreaterthank(vector<int>& bitcount, int k) {
        long long power = 1;  // `power` represents 2^i
        int result = 0;       // Stores the decimal value of the current bitcount representation
        for(int i = 0; i < bitcount.size(); i++) {
            // If bitcount[i] > 0, add the value of 2^i to `result`
            result += ((bitcount[i] ? 1 : 0) * power);
            power *= 2;  // Move to the next power of 2
        }
        // If the calculated value is greater than or equal to k, return true
        if(result >= k) {
            return true;
        }
        return false;
    }

    // Function to find the minimum length of a subarray with a bitwise OR >= k
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;    // Initialize answer with max possible value
        int n = nums.size();  // Size of the input array
        vector<int> bitcount(32, 0);  // Array to store bit counts for each position (32-bit integers)

        int i = 0;  // Start index of the sliding window
        // Extend the sliding window with the end index `j`
        for(int j = 0; j < n; j++) {
            // Update the bitcount array by adding bits of `nums[j]`
            updatearray(nums[j], bitcount, true);
            
            // While the OR of the current window is greater than or equal to k
            while(isgreaterthank(bitcount, k) && i <= j) {
                // Update the minimum subarray length
                ans = std::min(ans, j - i + 1);
                // Move the start of the window forward, updating the bitcount array
                updatearray(nums[i], bitcount, false);
                i++;
            }
        }
        
        // If no valid subarray is found, return -1; otherwise, return the minimum length
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};
