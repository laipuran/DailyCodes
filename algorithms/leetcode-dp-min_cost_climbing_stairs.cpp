/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        if (n <= 1)
            return 0;

        int prev2 = 0, prev1 = 0;

        for (int i = 2; i < n + 1; i++)
        {
            int current = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
// @lc code=end
