/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr)
            return right;

        if (right == nullptr)
            return left;

        return root;
    }
};
// @lc code=end
// My O(n^2) solution:
class Solution
{
    bool isAncestorOf(TreeNode *root, TreeNode *p)
    {
        if (root == nullptr)
            return false;
        if (root == p)
            return true;
        return isAncestorOf(root->left, p) || isAncestorOf(root->right, p);
    }

    bool isAncestorOf(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return isAncestorOf(root, p) && isAncestorOf(root, q);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        auto isLeft = isAncestorOf(root->left, p, q);
        auto isRight = isAncestorOf(root->right, p, q);

        if (!isLeft && !isRight)
            return root;

        auto node = isLeft ? root->left : root->right;
        return lowestCommonAncestor(node, p, q);
    }
};