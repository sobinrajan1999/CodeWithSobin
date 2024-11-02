//question : https://leetcode.com/problems/candy/description/

class Solution {
public:
    int candy(vector<int>& ratings) {
        // Initialize a vector to store candies for each child, each starting with 1 candy
        std::vector<int> candies(ratings.size(), 1);
        
        // First pass: from left to right
        // If the current child's rating is greater than the previous child’s,
        // give one more candy than the previous child.
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        // Second pass: from right to left
        // If the current child's rating is greater than the next child's,
        // ensure they have more candies than the next child.
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = std::max(candies[i], candies[i+1] + 1);
            }
        }

        // Sum up all the candies to get the result
        int result = 0;
        for(auto candy_count : candies) {
            std::cout << candy_count << " "; // Optional: print each child's candy count
            result += candy_count;
        }
        std::cout << std::endl; // Newline for clarity in output

        return result; // Total minimum candies required
    }
};
