/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; i++)
            graph[i][i] = true;
        for (auto const &pre : prerequisites)
            graph[pre[0]][pre[1]] = true;

        for (int k = 0; k < numCourses; k++)
            for (int i = 0; i < numCourses; i++)
                for (int j = 0; j < numCourses; j++)
                    if (graph[i][j] == false && graph[i][k] == true && graph[k][j] == true)
                        graph[i][j] = true;

        vector<bool> result;
        for (auto const &q : queries)
            result.push_back(graph[q[0]][q[1]]);

        return result;
    }
};
// @lc code=end
