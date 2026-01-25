/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, int preBegin, int preEnd,
                        vector<int> &inorder, int inBegin, int inEnd)
    {
        if (preEnd - preBegin == 0)
            return nullptr;
        if (preEnd - preBegin == 1)
            return new TreeNode(preorder[preBegin]);
        int root = preorder[preBegin];
        for (int i = inBegin; i < inEnd; i++)
        {
            if (inorder[i] != root)
                continue;
            TreeNode *node = new TreeNode(root);

            // Pretty hard to figure out the index, huh.
            node->left = buildTree(preorder, preBegin + 1, preBegin + i + 1 - inBegin, inorder, inBegin, i);
            node->right = buildTree(preorder, preBegin + i + 1 - inBegin, preEnd, inorder, i + 1, inEnd);
            return node;
        }
        // Warning locally but error remotly.
        return nullptr;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end

// Using more memory but also passed:
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        if (preorder.size() == 1)
            return new TreeNode(preorder[0]);
        int root = preorder[0];
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] != root)
                continue;
            TreeNode *node = new TreeNode(root);
            vector<int> preLeft = vector<int>(preorder.begin() + 1, preorder.begin() + i + 1);
            vector<int> preRight = vector<int>(preorder.begin() + i + 1, preorder.end());
            vector<int> inLeft = vector<int>(inorder.begin(), inorder.begin() + i);
            vector<int> inRight = vector<int>(inorder.begin() + i + 1, inorder.end());
            node->left = buildTree(preLeft, inLeft);
            node->right = buildTree(preRight, inRight);
            return node;
        }
        // Warning locally but error remotly.
        return nullptr;
    }
};

#include <iostream>
#include <string>

vector<int> getVector()
{
    vector<int> result;
    string str;
    getline(cin, str);
    str = str.substr(1, str.length() - 2) + ',';
    int temp = 0;
    for (char ch : str)
    {
        if (isdigit(ch))
        {
            temp = temp * 10 + ch - '0';
            continue;
        }
        result.push_back(temp);
        temp = 0;
    }
    return result;
}

int main()
{
    vector<int> preorder = getVector(), inorder = getVector();
    Solution sln;
    auto node = sln.buildTree(preorder, inorder);
}