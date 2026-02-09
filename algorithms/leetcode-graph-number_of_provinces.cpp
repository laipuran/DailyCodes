/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
#include <vector>
using namespace std;

class UnionFind
{
private:
    int *parents;

public:
    UnionFind(int n)
    {
        parents = new int[n];
        for (int i = 0; i < n; i++)
            parents[i] = i;
    }

    ~UnionFind()
    {
        delete[] parents;
    }

    int find(int index)
    {
        if (parents[index] == index)
            return index;

        return parents[index] = find(parents[index]);
    }

    bool unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB)
            return false;

        parents[rootA] = rootB;
        return true;
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j])
                    uf.unite(i, j);
            }
        }

        int count = 1;
        for (int i = 0; i < n; i++)
        {
            if (uf.unite(0, i))
                count++;
        }
        return count;
    }
};
// @lc code=end
