/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

// Consider adding Bellman-Ford algorithm.
class Solution
{
private:
    using Node = tuple<int, int, int>;

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto const &flight : flights)
            graph[flight[0]].push_back({flight[1], flight[2]});

        priority_queue<Node, vector<Node>, greater<Node>> priQueue;
        vector<int> min_steps(n, k + 2);

        priQueue.push({0, src, 0});

        while (!priQueue.empty())
        {
            auto [cost, index, stops] = priQueue.top();
            priQueue.pop();

            if (stops > min_steps[index] || stops > k + 1)
                continue;
            min_steps[index] = stops;

            if (index == dst)
                return cost;

            for (const auto &[neighbor, price] : graph[index])
            {
                if (stops + 1 <= k + 1)
                    priQueue.push({cost + price, neighbor, stops + 1});
            }
        }
        return -1;
    }
};
// @lc code=end
