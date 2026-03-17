/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int n = nums.size(), idx = n - 1, i = 0;
        while (i <= idx)
        {
            if (nums[i] == val)
            {
                // nums[idx] is no longer used
                // std::swap(nums[i], nums[idx]);
                
                nums[i] = nums[idx];
                idx--;
            }
            else
                i++;
        }
        return idx + 1;
    }
};
// @lc code=end
