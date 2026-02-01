/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, 0x3f3f3f3f));
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (const auto& edge : edges)
            dist[edge[1]][edge[0]] = dist[edge[0]][edge[1]] = edge[2];

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        vector<int> arrivals(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && dist[i][j] <= distanceThreshold)
                    arrivals[i]++;

        int min = 0x3f3f3f3f;
        int minIndex = 0;
        for (int i = 0; i < n; i++)
            if (arrivals[i] <= min)
            {
                min = arrivals[i];
                minIndex = i;
            }
        return minIndex;
    }
};
// @lc code=end
