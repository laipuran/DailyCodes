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
private:
    int *minCost;

public:
    ~Solution()
    {
        delete[] minCost;
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        if (n <= 1)
            return 0;

        minCost = new int[n + 1];
        minCost[0] = minCost[1] = 0;

        for (int i = 2; i < n + 1; i++)
        {
            minCost[i] = min(minCost[i - 1] + cost[i - 1], minCost[i - 2] + cost[i - 2]);
        }

        return minCost[n];
    }
};
// @lc code=end
