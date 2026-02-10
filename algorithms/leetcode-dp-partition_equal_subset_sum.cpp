/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        for (auto num : nums)
            sum += num;

        if (sum % 2 == 1)
            return false;

        int target = sum / 2;
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            // Using j >= nums[i] to make sure it won't overflow.
            // Loop from big to small to avoid using one thing twice.
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
};
// @lc code=end
