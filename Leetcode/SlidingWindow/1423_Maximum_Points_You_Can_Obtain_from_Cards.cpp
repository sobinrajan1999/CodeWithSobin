//question : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();   // Total number of cards
        int maxresult = 0;           // Variable to store the maximum score
        int sum = 0;                 // Sum of the current selected cards

        // Calculate the initial sum by taking the first 'k' cards from the beginning
        for(int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        // Set maxresult to the initial sum of the first 'k' cards
        maxresult = std::max(maxresult, sum);

        // i points to the last card in the initial k cards, j starts from the last card
        int i = k - 1;
        int j = n - 1;

        // Move one card from the end and remove one from the start of the initial 'k' cards, 'k' times
        while(k) {
            k--; // Reduce the number of remaining cards to adjust
            // Remove cardPoints[i] from the sum and add cardPoints[j] from the end
            sum = (cardPoints[j] + (sum - cardPoints[i]));
            // Update maxresult if the new sum is higher
            maxresult = std::max(maxresult, sum);

            // Move i and j one step back for the next swap
            i--;
            j--;
        }

        return maxresult; // Return the maximum score possible
    }
};
