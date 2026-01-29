/*
 * @lc app=leetcode.cn id=1791 lang=cpp
 *
 * [1791] 找出星型图的中心节点
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        vector<int> count(edges.size() + 2);
        for (auto &edge : edges)
        {
            count[edge[0]]++;
            count[edge[1]]++;
        }
        for (int i = 1; i <= edges.size() + 1; i++)
            if (count[i] > 1)
                return i;
        return 0;
    }
};
// @lc code=end
