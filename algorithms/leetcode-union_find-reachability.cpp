/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
// TODO: Add union find solution.

#include <vector>
using namespace std;

class Solution
{
    vector<int> parent;

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        else
            return parent[i] = find(parent[i]);
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &edge : edges)
        {
            int root1 = find(edge[0]), root2 = find(edge[1]);
            if (root1 != root2)
            {
                parent[root2] = root1;
            }
        }
        if (find(source) == find(destination))
            return true;
        return false;
    }
};
// @lc code=end

// My BFS solution:

#include <vector>
using namespace std;

class Solution
{
private:
    bool result = false;
    vector<int> path;

    void backtracking(const vector<vector<int>> &graph, int node, int destination)
    {
        if (path[destination] > 0)
            result = true;

        for (int i = 0; i < graph[node].size(); i++)
        {
            // It is a existing problem, not a verbosing problem.
            if (result == true)
                return;

            int next = graph[node][i];
            if (path[next] > 0)
                continue;
            path[next]++;
            backtracking(graph, next, destination);
            // path[next]--;
        }
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph = vector<vector<int>>(n);
        for (auto item : edges)
        {
            graph[item[0]].push_back(item[1]);
            graph[item[1]].push_back(item[0]);
        }

        path = vector<int>(n);
        path[source]++;
        backtracking(graph, source, destination);
        return result;
    }
};