#include <vector>

class GraphAdjList {
private:
    std::vector<std::vector<int>> adj;

public:
    GraphAdjList(int n) {
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const std::vector<int>& neighbors(int u) const {
        return adj[u];
    }

    int size() const {
        return adj.size();
    }
};