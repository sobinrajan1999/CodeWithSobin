//question : https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long result = 0;                 // Initialize result to store the count of interchangeable rectangle pairs
        unordered_map<string, int> m;         // Map to store the normalized ratio of each rectangle as a string key with its frequency

        // Iterate through each rectangle in the input
        for (auto it : rectangles) {
            int common = gcd(it[0], it[1]);   // Find the GCD of the rectangle's width and height to normalize the ratio
            it[0] /= common;                  // Divide width by GCD to reduce the fraction
            it[1] /= common;                  // Divide height by GCD to reduce the fraction

            // Create a unique string key for the reduced ratio "width height"
            string ratio = to_string(it[0]) + " " + to_string(it[1]);

            // Increment the count of this unique ratio in the map
            m[ratio]++;
        }

        // Calculate pairs of interchangeable rectangles
        for (auto it : m) {
            // If a ratio appears k times, the number of ways to form pairs is (k * (k - 1)) / 2
            result += ((long long)it.second * ((long long)it.second - 1)) / 2;
        }

        return result;  // Return the total count of interchangeable rectangle pairs
    }
};
