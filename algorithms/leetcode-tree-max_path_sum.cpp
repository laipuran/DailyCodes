/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
using namespace std;

// There are two situation that may be max: left->root->right, or left/right->node->root.
class Solution
{
private:
    int *maxSum;

    int maxTreeSum(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        // Even if the node has no child, we still need to record the max sum.
        int left = maxTreeSum(node->left), right = maxTreeSum(node->right);

        // Not convenient to get the min int, so we use the pointer.
        if (maxSum == nullptr)
            maxSum = new int(node->val + max(0, left) + max(0, right));
        else
        // Compare it with 0, when the child has no gain, we can just not choose it.
            *maxSum = max(*maxSum, node->val + max(0, left) + max(0, right));
        return node->val + max(0, max(left, right));
    }

public:
    Solution() : maxSum(nullptr) {}
    int maxPathSum(TreeNode *root)
    {
        maxTreeSum(root);
        return *maxSum;
    }
};
// @lc code=end
