/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        if (amount == 0)
            return 0;

        vector<int> cost(amount + 1, 0x3f3f3f3f - 1);
        cost[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                cost[j] = min(cost[j], cost[j - coins[i]] + 1);
            }
        }

        if (cost[amount] == 0x3f3f3f3f - 1)
            return -1;
        return cost[amount];
    }
};
// @lc code=end
