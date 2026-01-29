/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<vector<int>> in(n + 1), out(n + 1);
        for (auto &t : trust)
        {
            out[t[0]].push_back(t[1]);
            in[t[1]].push_back(t[0]);
        }

        // Clearer solution:
        for (int i = 1; i <= n; i++)
        {
            if (out[i].size() == 0 && in[i].size() == n - 1)
                return i;
        }
        return -1;
        
        // int count = 0;
        // int judge = -1;
        // for (int i = 1; i <= n; i++)
        // {
        //     if (in[i].size() < n - 1)
        //         continue;
        //     count++;
        //     judge = i;
        // }
        // // Check if there's no judge.
        // if (judge == -1 || count > 1 || out[judge].size() != 0)
        //     return -1;
        // return judge;
    }
};
// @lc code=end

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{1, 2}, {2, 3}};
    auto result = Solution().findJudge(n, edges);
}