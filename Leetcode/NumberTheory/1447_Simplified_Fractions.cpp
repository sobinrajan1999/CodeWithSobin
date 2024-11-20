//question : https://leetcode.com/problems/simplified-fractions/description

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> result;        // Stores the result of simplified fractions
        int i = 1;                    // Initialize numerator
        int j = 2;                    // Initialize denominator
        vector<float> store;          // Stores unique decimal values of fractions to avoid duplicates
        store.push_back(1.00);        // Add 1.0 as a base case for unique fraction checking

        while(i <= n) {               // Loop while numerator is within bounds
            if(j > n) {               // Reset denominator if it exceeds the limit
                j = i + 1;            // Set denominator to be greater than numerator for valid fraction
                i++;                  // Move to the next numerator
            }

            // Check if the decimal value of i/j is not already in store (to avoid duplicates)
            if(find(store.begin(), store.end(), (float)i / (float)j) == store.end()) {
                store.push_back((float)i / (float)j); // Store unique decimal value

                // Create the fraction string "i/j" and add it to the result
                string temp = to_string(i) + "/" + to_string(j);
                result.push_back(temp);
            }

            j++;  // Increment denominator
        }

        return result;  // Return the vector of simplified fractions
    }
};

