//question : https://leetcode.com/problems/house-robber-iii/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // A map to store the results of already computed subproblems
    unordered_map<TreeNode*, int> dp;

    // Helper function to calculate the maximum amount that can be robbed starting at the given node
    int solve(TreeNode* root) {
        // Base case: If the node is null, no value can be robbed
        if (root == nullptr) {
            return 0;
        }

        // If the result for this node is already computed, return it from the memoization map
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }

        // Option 1: Rob this node (pick)
        int ans = root->val; // Start with the value of the current node
        if (root->left) {
            // Add the maximum values from the grandchildren (left->left and left->right)
            ans += solve(root->left->left) + solve(root->left->right);
        }
        if (root->right) {
            // Add the maximum values from the grandchildren (right->left and right->right)
            ans += solve(root->right->left) + solve(root->right->right);
        }

        // Option 2: Do not rob this node (no pick)
        int ans2 = solve(root->left) + solve(root->right); // Take the maximum from the direct children

        // Store the result of the maximum of the two options in the memoization map
        return dp[root] = max(ans, ans2);
    }

    // Main function to calculate the maximum amount that can be robbed
    int rob(TreeNode* root) {
        return solve(root); // Start solving from the root of the tree
    }
};
