//question : https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    int widthOfBinaryTree(TreeNode* root) {
        // Initialize a queue to store nodes along with their index positions
        // within the virtual complete binary tree.
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0}); // Start with the root node at index 0

        int result = 0;  // Variable to keep track of the maximum width
        while (!q.empty()) {
            int k = q.size();  // Number of nodes at the current level
            auto mini = q.front().second;  // Minimum index at this level
            int first, last;  // Indices of the first and last nodes at the current level

            // Traverse the current level
            for (int i = 0; i < k; i++) {
                // Extract the front node and its index from the queue
                auto [temp, nodeindex] = q.front();
                nodeindex -= mini;  // Normalize index to prevent overflow
                q.pop();

                // Set 'first' and 'last' to keep track of the width at this level
                if (i == 0) {
                    first = nodeindex;
                }
                if (i == k - 1) {
                    last = nodeindex;
                }

                // Enqueue the left child with index 2 * nodeindex + 1 if it exists
                if (temp->left) {
                    q.push({temp->left, 2 * nodeindex + 1});
                }
                
                // Enqueue the right child with index 2 * nodeindex + 2 if it exists
                if (temp->right) {
                    q.push({temp->right, 2 * nodeindex + 2});
                }
            }

            // Update the result with the maximum width found so far
            result = std::max(result, last - first + 1);
        }

        return result;  // Return the maximum width of the binary tree
    }
};
