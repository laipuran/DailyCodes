/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;

// Better solution provided by Gemini
class Solution
{
private:
    // Binary search helper: finds the first index where the element is >= target.
    // Equivalent to std::lower_bound.
    int lowerBound(const vector<int> &nums, int target)
    {
        int left = 0, right = (int)nums.size() - 1;
        int res = nums.size();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                res = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = lowerBound(nums, target);
        // If left boundary is out of bounds or the value is not target, target doesn't exist
        if (left == nums.size() || nums[left] != target)
        {
            return {-1, -1};
        }
        // Right boundary is the position before the first element > target
        int right = lowerBound(nums, target + 1) - 1;
        return {left, right};
    }
};
// @lc code=end
