//question : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // `n` is the size of the input array
        long long n = nums.size();
        
        // A deque to store pairs of prefix sum and their corresponding indices
        deque<pair<long long, long long>> dq;
        
        // `sum` keeps track of the cumulative sum of the array
        long long sum = 0;

        // `result` stores the length of the shortest subarray with sum >= k
        // Initialized to `INT_MAX` to represent no valid subarray found yet
        long long result = INT_MAX;

        // Traverse through the array
        for (long long i = 0; i < n; i++) {
            sum += nums[i]; // Add the current element to the cumulative sum

            // Case 1: If the cumulative sum itself is >= k, update the result
            if (sum >= k) {
                result = std::min(result, i + 1); // `i+1` represents subarray from index 0 to `i`
            }

            // Case 2: Check if there's a previous prefix sum such that the subarray
            // sum between that prefix and the current index is >= k
            while (!dq.empty() && (sum - dq.front().first) >= k) {
                auto [prefix, end_index] = dq.front(); // Extract the front of the deque
                dq.pop_front(); // Remove it after processing
                result = std::min(result, (i - end_index)); // Update the result
            }

            // Case 3: Maintain deque monotonicity by removing all elements
            // with prefix sums greater than or equal to the current sum
            // (as they are no longer useful for forming a shorter subarray)
            while (!dq.empty() && dq.back().first >= sum) {
                dq.pop_back();
            }

            // Add the current cumulative sum and index to the deque
            dq.push_back({sum, i});
        }

        // If no valid subarray was found, return -1; otherwise, return the result
        return result == INT_MAX ? -1 : result;
    }
};
