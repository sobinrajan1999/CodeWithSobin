//question : https://leetcode.com/problems/maximum-strong-pair-xor-ii/description

#include <bits/stdc++.h>
using namespace std;

// Definition of the Trie data structure to store binary representation of numbers
struct Trie {
    Trie* zero; // Pointer to the child node representing bit 0
    Trie* one;  // Pointer to the child node representing bit 1
    int count;  // Count of numbers passing through this node
    Trie() {
        zero = nullptr;
        one = nullptr;
        count = 0;
    }
};

class Solution {
public:
    Trie* root; // Root of the Trie

    // Function to insert a number into the Trie
    void insertTrie(int n) {
        Trie* temp = root;
        // Traverse each bit from the 31st to the 0th bit
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1; // Get the ith bit of the number
            if (bit == 1) { // If bit is 1
                if (temp->one == nullptr) { // If no child for 1, create it
                    temp->one = new Trie();
                }
                temp = temp->one; // Move to the 1 child
            } else { // If bit is 0
                if (temp->zero == nullptr) { // If no child for 0, create it
                    temp->zero = new Trie();
                }
                temp = temp->zero; // Move to the 0 child
            }
            temp->count++; // Increment count for each node in the path
        }
    }

    // Function to remove a number from the Trie
    void removeTrie(int n) {
        Trie* temp = root;
        // Traverse each bit from the 31st to the 0th bit
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1; // Get the ith bit of the number
            if (bit == 1) { // If bit is 1
                if (temp->one != nullptr) { // Move to 1 child if it exists
                    temp = temp->one;
                    temp->count--; // Decrement count for this node
                }
            } else { // If bit is 0
                if (temp->zero != nullptr) { // Move to 0 child if it exists
                    temp = temp->zero;
                    temp->count--; // Decrement count for this node
                }
            }
        }
    }

    // Function to find the maximum XOR for a given number in the Trie
    int findmaxxor(int n) {
        int ans = 0; // Stores the maximum XOR result
        Trie* temp = root;
        // Traverse each bit from the 31st to the 0th bit
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1; // Get the ith bit of the number
            // Try to find the opposite bit to maximize XOR
            if (bit == 0) { // If current bit is 0, prefer path with 1
                if (temp->one != nullptr && temp->one->count > 0) {
                    ans += (1 << i); // Set the ith bit in the answer
                    temp = temp->one; // Move to 1 child
                } else {
                    temp = temp->zero; // Move to 0 child
                }
            } else { // If current bit is 1, prefer path with 0
                if (temp->zero != nullptr && temp->zero->count > 0) {
                    ans += (1 << i); // Set the ith bit in the answer
                    temp = temp->zero; // Move to 0 child
                } else {
                    temp = temp->one; // Move to 1 child
                }
            }
        }
        return ans; // Return the maximum XOR result
    }

    // Function to find the maximum XOR of any strong pair
    int maximumStrongPairXor(vector<int>& nums) {
        root = new Trie(); // Initialize the root of the Trie
        std::sort(nums.begin(), nums.end()); // Sort the array to process elements in ascending order
        int maxxor = 0; // Initialize the maximum XOR result
        int n = nums.size();
        int r = 0; // Right pointer to add elements satisfying the 2*nums[i] condition
        
        for (int i = 0; i < n; i++) {
            // Insert elements into the Trie while they satisfy the 2 * nums[i] condition
            while (r < n && nums[r] <= 2 * nums[i]) {
                insertTrie(nums[r]);
                r++;
            }
            
            // Find max XOR for current nums[i] with the Trie elements
            maxxor = std::max(maxxor, findmaxxor(nums[i]));
            
            // Remove nums[i] from the Trie to prevent reuse in the next iteration
            removeTrie(nums[i]);
        }
        
        return maxxor; // Return the final maximum XOR result
    }
};
