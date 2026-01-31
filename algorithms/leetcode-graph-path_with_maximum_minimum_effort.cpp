/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Better solution provided by Gemini:
class Solution
{
private:
    typedef pair<int, int> distance;

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int lnTotal = heights.size();
        int colTotal = heights[0].size();
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<distance, vector<distance>, greater<distance>> priQueue;
        vector<int> minEfforts(lnTotal * colTotal, 0x3f3f3f3f);

        minEfforts[0] = 0;
        priQueue.push({0, 0});

        while (!priQueue.empty())
        {
            auto [effort, index] = priQueue.top();
            priQueue.pop();

            if (effort > minEfforts[index])
                continue;

            int x = index / colTotal;
            int y = index % colTotal;

            // 如果已经到达终点，可以提前返回
            if (x == lnTotal - 1 && y == colTotal - 1)
                return effort;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];

                if (nx >= 0 && nx < lnTotal && ny >= 0 && ny < colTotal)
                {
                    int nIdx = nx * colTotal + ny;
                    int cost = max(effort, abs(heights[nx][ny] - heights[x][y]));
                    if (cost < minEfforts[nIdx])
                    {
                        minEfforts[nIdx] = cost;
                        priQueue.push({cost, nIdx});
                    }
                }
            }
        }
        return minEfforts[lnTotal * colTotal - 1];
    }
};
// @lc code=end

// My solution using a adjacency list:
class Solution
{
private:
    typedef pair<int, int> distance;

    int getIndex(const vector<vector<int>> &heights, int ln, int col)
    {
        return ln * heights[0].size() + col;
    }

    vector<int> getBesideIndex(const vector<vector<int>> &heights, int ln, int col)
    {
        int lnTotal = heights.size();
        int colTotal = heights[0].size();

        vector<int> result;
        if (ln > 0)
            result.push_back(getIndex(heights, ln - 1, col));
        if (ln < lnTotal - 1)
            result.push_back(getIndex(heights, ln + 1, col));

        if (col > 0)
            result.push_back(getIndex(heights, ln, col - 1));
        if (col < colTotal - 1)
            result.push_back(getIndex(heights, ln, col + 1));
        return result;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int lnTotal = heights.size();
        int colTotal = heights[0].size();

        priority_queue<distance, vector<distance>, greater<distance>> priQueue;
        vector<vector<distance>> graph(lnTotal * colTotal);

        for (int ln = 0; ln < lnTotal; ln++)
        {
            for (int col = 0; col < colTotal; col++)
            {
                int index = getIndex(heights, ln, col);
                auto neighbors = getBesideIndex(heights, ln, col);
                for (auto const &neighbor : neighbors)
                {
                    graph[index].push_back(
                        {abs(heights[neighbor / colTotal][neighbor % colTotal] - heights[ln][col]),
                         neighbor});
                }
            }
        }

        vector<int> minEfforts(lnTotal * colTotal, 0x3f3f3f3f);
        minEfforts[0] = 0;
        priQueue.push({0, 0});
        while (!priQueue.empty())
        {
            auto [deltaHeight, index] = priQueue.top();
            priQueue.pop();

            if (deltaHeight > minEfforts[index])
                continue;

            for (auto neighbor : graph[index])
            {
                int cost = max(minEfforts[index], neighbor.first);
                if (cost < minEfforts[neighbor.second])
                {
                    minEfforts[neighbor.second] = cost;
                    priQueue.push({cost, neighbor.second});
                }
            }
        }
        return minEfforts[lnTotal * colTotal - 1];
    }
};