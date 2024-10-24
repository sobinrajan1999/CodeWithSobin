//question : https://leetcode.com/problems/path-sum/description/

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

    bool calpath(TreeNode* root, int target)
    {
        bool status = false;
        if(target == 0 and root->left == nullptr and root->right == nullptr)
        {
            return true;
        }
        if(root == nullptr)
        {
            return false;
        }
        if(root->left != nullptr)
        {
            status |= calpath(root->left, target - root->left->val);
        }
        if(root->right != nullptr)
        {
            status |= calpath(root->right, target - root->right->val);
        }

        return  status;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
        {
            return false;
        }
        return calpath(root, targetSum - root->val);
    }
};