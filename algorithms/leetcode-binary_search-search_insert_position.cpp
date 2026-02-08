/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
private:
    int search(const vector<int> &nums, int target, int begin, int end)
    {
        if (end - begin <= 1)
        {
            if (nums[begin] >= target)
                return begin;
            else
                return end;
        }

        int mid = begin + (end - begin) / 2;

        if (target < nums[mid])
            return search(nums, target, begin, mid);
        else
            return search(nums, target, mid, end);
    }

public:
    int searchInsert(vector<int> &nums, int target)
    {
        return search(nums, target, 0, nums.size());
    }
};
// @lc code=end
