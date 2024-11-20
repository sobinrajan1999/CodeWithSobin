//question : https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // Step 1: Sort the array in ascending order
        sort(piles.begin(), piles.end());

        int result = 0;  // Variable to store the maximum coins you can collect
        int n = piles.size(); // Total number of piles
        int left = 0;  // Pointer to the smallest pile
        int right = n - 1;  // Pointer to the largest pile

        // Step 2: Iterate until the left pointer crosses the right pointer
        while (left < right) {
            // Add the second largest pile to the result
            result += piles[right - 1];
            
            // Move the pointers:
            // - Increase the left pointer to exclude the smallest pile (opponent takes it)
            left++;
            // - Decrease the right pointer by 2 to exclude the largest pile (you take the second largest)
            right -= 2;
        }

        // Step 3: Return the total coins collected
        return result;
    }
};
