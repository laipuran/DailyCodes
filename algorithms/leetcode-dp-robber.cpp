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
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // dp[i] means the max money can be robbed from house 0 to i
        // For each house, you have two choices:
        // 1. Rob it: You can't rob the previous house (i-1), so add dp[i-2] + nums[i]
        // 2. Don't rob it: Take the max from previous house (dp[i-1])
        // dp[i] = max(dp[i-1], dp[i-2] + nums[i])

        int prev2 = nums[0]; // dp[i-2]
        int prev1 = max(nums[0], nums[1]); // dp[i-1]

        for (int i = 2; i < n; ++i)
        {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
// @lc code=end
