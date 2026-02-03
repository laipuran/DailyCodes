/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;

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

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        int result = 0;
        DSU dsu(n);
        for (int i = 0; i < n; i++)
            if (dsu.unite(edges[i][0] - 1, edges[i][1] - 1) == false)
                result = i;
        return edges[result];
    }
};
// @lc code=end
