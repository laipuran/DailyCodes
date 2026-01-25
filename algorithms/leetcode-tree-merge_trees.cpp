/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;
        else if (root1 == nullptr || root2 == nullptr)
            return root1 == nullptr ? root2 : root1;
        else{
            TreeNode* node =new TreeNode(root1->val+root2->val);
            node->left=mergeTrees(root1->left,root2->left);
            node->right=mergeTrees(root1->right,root2->right);
            return node;
        }
    }
};
// @lc code=end

// In-place solution provided by Gemini:
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 1. 如果其中一棵树为空，直接返回另一棵（Base Case）
        if (!t1) return t2;
        if (!t2) return t1;

        // 2. 如果两棵树都有值，直接加到 t1 上
        t1->val += t2->val;

        // 3. 递归合并子树，并将结果挂载到 t1 的左右指针上
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        // 4. 返回修改后的 t1
        return t1;
    }
};