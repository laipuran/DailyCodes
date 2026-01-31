/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    // Make sure the priority queue sort with the first element.
    typedef pair<int, int> distance;
    // {dist, node}

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<distance>> graph(n + 1);
        // Set up the priority_queue like this to make sure the minimum element at front.
        priority_queue<distance, vector<distance>, greater<distance>> priQueue;

        for (auto const &time : times)
            graph[time[0]].push_back({time[2], time[1]});

        // The max int32 = 0x3f3f3f3f
        vector<int> shortest(n + 1, 0x3f3f3f3f);
        shortest[k] = 0;
        priQueue.push({0, k});

        while (!priQueue.empty())
        {
            auto [dist, current] = priQueue.top();
            priQueue.pop();

            if (dist > shortest[current])
                continue;

            for (auto const &neighbor : graph[current])
            {
                if (dist + neighbor.first < shortest[neighbor.second])
                {
                    int temp = shortest[neighbor.second] = dist + neighbor.first;
                    priQueue.push({temp, neighbor.second});
                }
            }
        }

        int max = 0;
        for (int i = 1; i <= n; i++)
            if (shortest[i] > max)
                max = shortest[i];
        if (max == 0x3f3f3f3f)
            return -1;
        return max;
    }
};
// @lc code=end
