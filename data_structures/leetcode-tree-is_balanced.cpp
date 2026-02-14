/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
#include <cmath>

class Solution
{
private:
    int getLayers(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        return 1 + std::max(getLayers(node->left), getLayers(node->right));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        if (abs(getLayers(root->left) - getLayers(root->right)) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end
