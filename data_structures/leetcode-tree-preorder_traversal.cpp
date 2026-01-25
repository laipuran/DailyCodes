/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr)return vector<int>();
        vector<int> numbers;
        
        numbers.push_back(root->val);
        vector<int> leftNums=preorderTraversal(root->left);
        vector<int> rightNums=preorderTraversal(root->right);
        
        numbers.insert(numbers.end(),make_move_iterator(leftNums.begin()),make_move_iterator(leftNums.end()));
        numbers.insert(numbers.end(),make_move_iterator(rightNums.begin()),make_move_iterator(rightNums.end()));
        return numbers;
    }
};
// @lc code=end

