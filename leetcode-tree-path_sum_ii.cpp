/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;

    void backtracking(const TreeNode *node, int targetSum)
    {
        if (node == nullptr)
            return;

        if (node->left == nullptr && node->right == nullptr && sum == targetSum)
        {
            result.push_back(path);
            return;
        }

        if (node->left != nullptr)
        {
            int left = node->left->val;
            sum += left;
            path.push_back(left);

            backtracking(node->left, targetSum);

            path.pop_back();
            sum -= left;
        }

        if (node->right != nullptr)
        {
            int right = node->right->val;
            sum += right;
            path.push_back(right);

            backtracking(node->right, targetSum);

            path.pop_back();
            sum -= right;
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return result;

        // Push in the first node.
        path.push_back(root->val);
        sum += root->val;
        backtracking(root, targetSum);
        return result;
    }
};
// @lc code=end
