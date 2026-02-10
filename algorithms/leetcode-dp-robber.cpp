/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
private:
    int *robbed;

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        if (n == 3)
            return max(nums[0] + nums[2], nums[1]);

        robbed = new int[n];
        robbed[0] = nums[0];
        robbed[1] = nums[1];
        robbed[2] = nums[0] + nums[2];

        for (int i = 3; i < n; i++)
        {
            robbed[i] = max(robbed[i - 2], robbed[i - 3]) + nums[i];
        }
        return max(robbed[n - 1], robbed[n - 2]);
    }
};
// @lc code=end
