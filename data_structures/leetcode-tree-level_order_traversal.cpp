/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> tree;
        if (root == nullptr)
            return tree;

        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            int num = nodes.size();
            vector<int> nums;
            for (int i = 0; i < num; i++)
            {
                nums.push_back(nodes.front()->val);
                if (nodes.front()->left != nullptr)
                    nodes.push(nodes.front()->left);
                if (nodes.front()->right != nullptr)
                    nodes.push(nodes.front()->right);
                nodes.pop();
            }
            tree.push_back(nums);
        }
        return tree;
    }
};
// @lc code=end
