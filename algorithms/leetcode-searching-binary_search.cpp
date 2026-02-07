/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
private:
    int search(vector<int> &nums, int target, int begin, int end)
    {
        if (end - begin <= 1)
        {
            if (nums[begin] == target)
                return begin;
            else
                return -1;
        }

        int mid = begin + (end - begin) / 2;

        if (target < nums[mid])
            return search(nums, target, begin, mid);
        else
            return search(nums, target, mid, end);
    }

public:
    int search(vector<int> &nums, int target)
    {
        return search(nums, target, 0, nums.size());
    }
};
// @lc code=end
