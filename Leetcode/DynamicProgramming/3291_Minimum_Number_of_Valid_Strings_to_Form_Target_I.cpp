//question : https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-i/description

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// Trie node structure
struct trie {
    trie* node[26]; // Array of pointers to child nodes for each letter
    int wordcount; // Tracks if a word ends at this node (not used in solution, but may be helpful for future extensions)

    // Constructor initializes all children as nullptr
    trie() {
        for (int i = 0; i < 26; i++) {
            node[i] = nullptr;
        }
        wordcount = 0;
    }
};

class Solution {
public:
    trie* root; // Root of the Trie
    int dp[5001]; // DP array for memoization

    // Builds the Trie with each word from the list
    void buildTrie(string word) {
        trie* temp = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a'; // Find the index for the character
            if (temp->node[index] == nullptr) {
                temp->node[index] = new trie(); // Create a new node if not present
            }
            temp = temp->node[index];
        }
    }

    // Recursive function to find minimum valid strings required from `pos` in the target string
    int solve(int pos, int n, string& target) {
        if (pos == n) {
            // Reached end of target string, no more characters needed
            return 0;
        }
        
        if (dp[pos] != -1) {
            // Return memoized result
            return dp[pos];
        }
        
        trie* temp = root;
        int ans = 1e6; // Initialize with a large value to minimize
        
        // Try to match substrings of target with words in Trie
        for (int i = pos; i < n; i++) {
            int index = target[i] - 'a';
            if (temp->node[index] != nullptr) {
                temp = temp->node[index];
                // Recursive call to solve the remaining target from index i+1
                ans = min(ans, 1 + solve(i + 1, n, target));
            } else {
                // No match found in Trie, break out of loop
                break;
            }
        }
        
        return dp[pos] = ans; // Memoize and return the result
    }

    // Main function to calculate the minimum number of valid strings
    int minValidStrings(vector<string>& words, string target) {
        memset(dp, -1, sizeof(dp)); // Initialize DP array with -1
        root = new trie(); // Initialize Trie root
        
        // Build the Trie from the list of words
        for (const string& word : words) {
            buildTrie(word);
        }
        
        int result = solve(0, target.size(), target); // Solve for entire target string

        // If the result is greater than or equal to an arbitrary large value, return -1 (no valid solution)
        return result >= 1e4 ? -1 : result;
    }
};
