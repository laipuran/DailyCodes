/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

// Considering Kruskal and Prim
class DSU
{
private:
    vector<int> parents;

public:
    DSU(int n)
    {
        parents = vector<int>(n);
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int x)
    {
        if (parents[x] == x)
            return x;
        return parents[x] = find(parents[x]);
    }

    bool unite(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return false;
        parents[rootx] = rooty;
        return true;
    }
};

struct Edge
{
    int from, to, weight;
    bool operator<(const Edge &another)
    {
        return weight < another.weight;
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        vector<Edge> edges;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                edges.push_back({i, j, abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0])});

        sort(edges.begin(), edges.end());

        DSU dsu(n);
        int result = 0;
        int count = 0;
        for (auto const &edge : edges)
        {
            if (dsu.unite(edge.from, edge.to))
            {
                result += edge.weight;
                count++;
            }
            // Remember to cut:
            if (count == n - 1)
                break;
        }
        return result;
    }
};
// @lc code=end
