/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        dist[0][0] = grid[0][0];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int a = 0x3f3f3f3f, b = 0x3f3f3f3f;
                if (i > 0)
                    a = dist[i - 1][j];
                if (j > 0)
                    b = dist[i][j - 1];

                dist[i][j] = min(a, b) + grid[i][j];
            }
        }

        return dist[m - 1][n - 1];
    }
};
// @lc code=end
