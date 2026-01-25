/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (q == nullptr && p == nullptr)
            return true;
        // Do not ignore this situation:
        else if (q == nullptr || p == nullptr)
            return false;
        return q->val == p->val && isSameTree(q->left, p->left) && isSameTree(q->right, p->right);
    }
};
// @lc code=end
