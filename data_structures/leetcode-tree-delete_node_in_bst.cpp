/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;

            // We need to find a node that is bigger than all the
            // left nodes and smaller than all the right nodes.
            // And that is the smallest on the right (or opposite).
            auto minNode = root->right;
            while (minNode->left != nullptr)
                minNode = minNode->left;

            root->val = minNode->val;

            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }
};
// @lc code=end
