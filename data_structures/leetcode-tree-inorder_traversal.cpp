/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr)return vector<int>();
        vector<int> numbers;

        vector<int> leftNums=postorderTraversal(root->left);
        vector<int> rightNums=postorderTraversal(root->right);

        numbers.insert(numbers.end(),make_move_iterator(leftNums.begin()),make_move_iterator(leftNums.end()));
        numbers.push_back(root->val);
        // Just move the push_back method.
        numbers.insert(numbers.end(),make_move_iterator(rightNums.begin()),make_move_iterator(rightNums.end()));
        return numbers;
    }
};
// @lc code=end

