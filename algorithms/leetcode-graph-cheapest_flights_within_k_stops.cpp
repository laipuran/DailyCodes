/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    typedef pair<int, int> distance;
    typedef pair<distance, int> step;

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<distance>> graph(n);
        for (auto const &flight : flights)
            graph[flight[0]].push_back({flight[2], flight[1]});

        priority_queue<step, vector<step>, greater<step>> priQueue;
        vector<int> minCost(n, 0x3f3f3f3f);
        minCost[src] = 0;
        priQueue.push({{0, src}, 0});
        vector<int> minSteps(n, 0x3f3f3f3f);

        while (!priQueue.empty())
        {
            auto [distance, stepCount] = priQueue.top();
            auto [cost, index] = distance;
            priQueue.pop();

            if (index == dst) return cost;
            // Higher cost doesn't mean impossible.
            if (stepCount > k /*|| cost > minCost[index]*/)
                continue;

            for (auto const &neighbor : graph[index])
            {
                int currentCost = neighbor.first + cost;
                int nextSteps = stepCount + 1;
                if (currentCost < minCost[neighbor.second] || nextSteps < minSteps[neighbor.second])
                {
                    minCost[neighbor.second] = currentCost;
                    minSteps[neighbor.second] = nextSteps;
                    priQueue.push({{currentCost, neighbor.second}, nextSteps});
                }
            }
        }
        if (minCost[dst] == 0x3f3f3f3f)
            return -1;
        return minCost[dst];
    }
};
// @lc code=end
