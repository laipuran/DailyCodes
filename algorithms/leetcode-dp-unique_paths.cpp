/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> situ(m, vector<int>(n, 0));
        situ[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0)
                    situ[i][j] += situ[i - 1][j];
                if (j > 0)
                    situ[i][j] += situ[i][j - 1];
            }
        }

        return situ[m - 1][n - 1];
    }
};
// @lc code=end
