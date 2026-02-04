// Luogu P1144

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct MinCost
{
    int count;
    int distance;
    MinCost(int count, int length) : count(count), distance(length) {};
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            continue;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    using Node = pair<int, int>;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, 1});

    vector<MinCost> minCost(n + 1, MinCost(0, 0x3f3f3f3f));
    minCost[1].distance = 0;
    minCost[1].count = 1;

    while (!pq.empty())
    {
        auto [distance, index] = pq.top();
        pq.pop();

        if (distance > minCost[index].distance)
            continue;

        for (const auto &neighbor : graph[index])
        {
            if (minCost[index].distance + 1 < minCost[neighbor].distance)
            {
                minCost[neighbor].count = minCost[index].count;
                minCost[neighbor].distance = minCost[index].distance + 1;
                pq.push({minCost[neighbor].distance, neighbor});
            }
            else if (minCost[index].distance + 1 == minCost[neighbor].distance)
            {
                minCost[neighbor].count = (minCost[neighbor].count + minCost[index].count) % 100003;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << minCost[i].count % 100003 << "\n";
    }
}