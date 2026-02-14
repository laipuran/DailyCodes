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
    int balanceLayers(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int left = balanceLayers(node->left);
        int right = balanceLayers(node->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;

        return std::max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        int result = balanceLayers(root);
        return result != -1;
    }
};
// @lc code=end
