/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> parents(numCourses, 0);
        vector<vector<int>> childs(numCourses);

        for (auto dependency : prerequisites)
        {
            childs[dependency[1]].push_back(dependency[0]);
            parents[dependency[0]]++;
        }

        // You always check the available (parents==0) node,
        // then unlock the node it locks.
        queue<int> q;
        vector<int> result;
        for (int i = 0; i < numCourses; i++)
            if (parents[i] == 0)
            {
                q.push(i);
            }

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            result.push_back(current);

            for (int child : childs[current])
            {
                parents[child]--;
                if (parents[child] == 0)
                    q.push(child);
            }
        }
        if (result.size() != numCourses)
            return vector<int>();
        return result;
    }
};
// @lc code=end
