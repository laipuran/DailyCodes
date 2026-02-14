#include <vector>

class UnionFind
{
private:
    std::vector<int> parents;

public:
    UnionFind(int n)
    {
        parents.resize(n);
        for (int i = 0; i < n; i++)
            parents[i] = i;
    }

    int find(int index)
    {
        if (parents[index] == index)
            return index;
        return parents[index] = find(parents[index]);
    }

    void merge(int node1, int node2)
    {
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 == root2)
            return;
        parents[root1] = root2;
    }
};