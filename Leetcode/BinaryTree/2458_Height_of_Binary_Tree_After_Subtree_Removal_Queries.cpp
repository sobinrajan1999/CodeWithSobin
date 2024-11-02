//question : https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries

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
    //dp array to store the max height of the tree after the removal
    vector<int> dp;
    int currentmaxheight;

    void heightleftToRightTree(TreeNode* root, int currentheight)
    {
        if(root == nullptr)
        {
            return;
        }
        dp[root->val] = currentmaxheight;
        currentmaxheight = std::max(currentmaxheight, currentheight);
        heightleftToRightTree(root->left, currentheight+1);
        heightleftToRightTree(root->right, currentheight+1);
    }

    void heightRightotLeftTree(TreeNode* root, int currentheight)
    {
        if(root == nullptr)
        {
            return;
        }
        dp[root->val] = std::max(currentmaxheight, dp[root->val]);
        currentmaxheight = std::max(currentmaxheight, currentheight);
        heightRightotLeftTree(root->right, currentheight+1);
        heightRightotLeftTree(root->left, currentheight+1);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dp = vector<int>(100001, -1);
        vector<int> result;
        //calculating the maxheight of the tree till the sub node
        //calculating by traversing from left to right;
        heightleftToRightTree(root, 0);
        currentmaxheight = 0;
        //calculating by traversing from right to left;
        heightRightotLeftTree(root, 0);
        //at last dp array will have the max height till all the subtree of the root node;
        for(auto it : queries)
        {
            result.push_back(dp[it]);
        }
        return result;
    }
};