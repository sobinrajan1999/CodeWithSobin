//question : https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    // Recursive function to calculate the height of the tree
    // and update the diameter as we go through the nodes.
    int solve(TreeNode* root, int& result) {
        // Base case: if root is null, height is 0
        if (root == nullptr) {
            return 0;
        }

        // Recursively get the height of the left subtree
        int ldiameter = solve(root->left, result);

        // Recursively get the height of the right subtree
        int rdiameter = solve(root->right, result);

        // Calculate the height of the current node
        // Height is max of left or right subtree height plus 1 for current node
        int temp = std::max(ldiameter, rdiameter) + 1;

        // Calculate the diameter passing through the current node
        int ans = std::max(ldiameter + rdiameter + 1, temp);

        // Update the maximum diameter found so far
        result = std::max(ans, result);

        // Return height of the current subtree
        return temp;
    }

    // Main function to calculate the diameter of the tree
    int diameterOfBinaryTree(TreeNode* root) {
        int result = INT_MIN; // Initialize result to the minimum integer value
        solve(root, result);  // Call recursive function to calculate diameter
        return result - 1;    // Subtract 1 to get the edge count
    }
};
