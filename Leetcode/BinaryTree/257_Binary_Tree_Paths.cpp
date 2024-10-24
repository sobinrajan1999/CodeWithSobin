//question : https://leetcode.com/problems/binary-tree-paths/description/

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

    void binaryTree(vector<std::string>& trees, TreeNode* root, std::string str)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->left == nullptr and root->right == nullptr)
        {
            trees.push_back(str + "->" + std::to_string(root->val));
            return;
        }

        binaryTree(trees, root->left, str + "->" + std::to_string(root->val));
        binaryTree(trees, root->right, str + "->" + std::to_string(root->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<std::string> result;
        binaryTree(result, root, "");
        for(auto& it : result)
        {
            it.erase(it.begin());
            it.erase(it.begin());
        }
        return result;
    }
};