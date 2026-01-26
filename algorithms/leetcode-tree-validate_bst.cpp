/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// My own solution:
class Solution
{
private:
    bool isValidBST(TreeNode *root, int *min, int *max)
    {
        return (root == nullptr) ||
               (((max == nullptr || root->val < *max) && (min == nullptr || root->val > *min)) &&
                // Actually don't need the (?:), it also causes interpretation of nullptrs.
                // isValidBST(root->left, min, root->val < *max ? &root->val : max) &&
                // isValidBST(root->right, root->val > *min ? &root->val : min, max));
                isValidBST(root->left, min, &root->val) &&
                isValidBST(root->right, &root->val, max));
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, nullptr, nullptr);
    }
};
// @lc code=end

// Inorder traversal automatically expand the BST to a sorted state.
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;

        auto leftNodes = inorderTraversal(root->left);
        result.insert(result.end(), make_move_iterator(leftNodes.begin()), make_move_iterator(leftNodes.end()));

        result.push_back(root->val);

        auto rightNodes = inorderTraversal(root->right);
        result.insert(result.end(), make_move_iterator(rightNodes.begin()), make_move_iterator(rightNodes.end()));

        return result;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        auto nums = inorderTraversal(root);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
};