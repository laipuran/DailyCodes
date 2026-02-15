/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *sortedArrayToBST(vector<int> &nums, int begin, int end)
    {
        if (end - begin == 1)
            return new TreeNode(nums[begin]);
        if (end - begin < 1)
            return nullptr;

        int mid = begin + (end - begin) / 2;

        return new TreeNode(nums[mid], sortedArrayToBST(nums, begin, mid), sortedArrayToBST(nums, mid + 1, end));
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};
// @lc code=end
