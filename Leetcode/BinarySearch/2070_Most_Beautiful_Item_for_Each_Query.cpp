//question : https://leetcode.com/problems/most-beautiful-item-for-each-query/description

class Solution {
public:
    // Function to find the maximum beauty for each query in `queries`
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();    // Number of items available
        int m = queries.size();   // Number of queries to process

        // Vector to store the maximum beauty achievable up to each item (sorted by price)
        vector<int> beautyItem(n, 0);

        // Sort items by price in ascending order
        sort(items.begin(), items.end());

        // Initialize the maximum beauty seen so far with the first item's beauty
        beautyItem[0] = items[0][1];
        
        // Compute the maximum beauty achievable up to each item
        for (int i = 1; i < n; i++) {
            // Update `beautyItem[i]` with the maximum beauty so far
            beautyItem[i] = std::max(beautyItem[i - 1], items[i][1]);
        }

        // Vector to store results for each query
        vector<int> result(m);

        // Process each query
        for (int i = 0; i < m; i++) {
            // Create a target vector to find the upper bound of the query price in `items`
            vector<int>&& target = {queries[i], INT_MAX};

            // Find the first item with a price greater than `queries[i]`
            int index = std::upper_bound(items.begin(), items.end(), target) - items.begin();

            // If the index is 0, all item prices are higher than the query price, so beauty is 0
            if (index == 0) {
                result[i] = 0;
            }
            // Otherwise, we can take the maximum beauty achievable up to `index - 1`
            else {
                result[i] = beautyItem[index - 1];
            }
        }
        
        return result;  // Return the results for all queries
    }
};
