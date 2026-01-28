/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<vector<int>> &graph, int index)
    {
        if (!path.empty() && path.back() == graph.size() - 1)
        {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < graph[index].size(); i++)
        {
            int next = graph[index][i];
            if (next != graph.size() - 1 && graph[next].size() == 0)
                continue;
            path.push_back(next);
            backtracking(graph, next);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        path.push_back(0);
        backtracking(graph, 0);
        return result;
    }
};
// @lc code=end
