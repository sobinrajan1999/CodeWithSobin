//question : https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/description

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        // If there's only one price point, no lines are needed
        if (stockPrices.size() == 1) {
            return 0;
        }

        // Sort stockPrices based on the x-coordinate (time)
        sort(stockPrices.begin(), stockPrices.end());

        int result = 1; // Start with one line initially
        int same_x = stockPrices[1][1] - stockPrices[0][1]; // Difference in y-coordinates of the first line segment
        int same_y = stockPrices[1][0] - stockPrices[0][0]; // Difference in x-coordinates of the first line segment

        // Loop through each price point starting from the third point
        for (int i = 2; i < stockPrices.size(); i++) {
            int new_x = stockPrices[i][1] - stockPrices[i - 1][1]; // Difference in y-coordinates for the current segment
            int new_y = stockPrices[i][0] - stockPrices[i - 1][0]; // Difference in x-coordinates for the current segment

            // Calculate cross-multiplication to check if the slopes are different (avoid division for accuracy)
            long long a = (long long)same_x * (long long)new_y;
            long long b = (long long)same_y * (long long)new_x;

            if (a != b) { // If the slopes are different
                result++; // Increase the count of lines
                same_x = new_x; // Update the slope difference values
                same_y = new_y;
            }
        }

        return result; // Return the minimum number of lines needed
    }
};
