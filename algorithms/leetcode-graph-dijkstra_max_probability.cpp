/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 *
 * [1514] 概率最大的路径
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<vector<pair<int, double>>> graph(n);

        for (int i = 0; i < edges.size(); i++)
        {
            const auto &edge = edges[i];
            graph[edge[0]].push_back({edge[1], succProb[i]});
            graph[edge[1]].push_back({edge[0], succProb[i]});
        }

        using Node = pair<double, int>;
        priority_queue<Node> pq;
        vector<double> maxP(n);
        pq.push({1, start_node});

        while (!pq.empty())
        {
            auto [p, index] = pq.top();
            pq.pop();

            if (p < maxP[index])
                continue;
            if (index == end_node)
                return p;

            maxP[index] = p;

            for (auto const &neighbor : graph[index])
            {
                double newP = neighbor.second * p;
                if (newP > maxP[neighbor.first])
                    pq.push({newP, neighbor.first});
            }
        }
        return 0;
    }
};
// @lc code=end
