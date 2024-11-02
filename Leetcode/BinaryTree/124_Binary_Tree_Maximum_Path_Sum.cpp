//question : https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    // Helper function to calculate the maximum path sum
    int solve(TreeNode* root, int& result) {
        // Base case: if the current node is null, return 0 (no path sum)
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the maximum path sum from the left subtree
        int left = solve(root->left, result);

        // Recursively calculate the maximum path sum from the right subtree
        int right = solve(root->right, result);

        // Maximum path sum starting from the current node (without splitting)
        // Either include the current node with the larger of the left or right path sums, or the node's value alone
        int temp = std::max(std::max(left, right) + root->val, root->val);

        // Maximum path sum that could be formed through the current node (with a possible split at this node)
        // This includes the sum of the node’s value, left path, and right path
        int ans = std::max(temp, left + right + root->val);

        // Update the global maximum path sum
        result = std::max(result, ans);

        // Return the maximum path sum for the current node (without splitting)
        return temp;
    }

    // Main function to calculate the maximum path sum in the binary tree
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;  // Initialize the result to the smallest possible value
        solve(root, result);   // Call the helper function
        return result;         // Return the result after traversing the entire tree
    }
};
